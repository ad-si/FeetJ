#include "BombGame.h"

#include <QPainter>

#include "core/Configuration.h"

//We need to register this Type in QML
MTQ_QML_REGISTER_PLUGIN(BombGame)

#define BOMB_RADIUS 20
#define BOMB_EXPLODE_DISTANCE 50
#define BOMB_SPEED 20
#define BOMB_LIT_SPEED 30
#define BOMB_INACTIVE 50
#define TEXT_DURATION 2000
#define EXPECTED_MARKER_COUNT 4
#define MARKER_TTL 20
#define HELP_MARKER_TTL 20
#define FLASH_FRAMES 20

QImage Bomb::m_bomb;
QImage Bomb::m_bombLit;
QImage Bomb::m_boom;

Bomb::Bomb(BombGame *game)
	: m_game(game),
	  m_image(&Bomb::m_bomb),
	  m_state(BS_NORMAL),
	  m_radius(BOMB_RADIUS),
	  m_position(QPoint(m_radius, m_radius)),
	  m_direction((std::rand() % 14) / 10.0 + 0.1),
	  m_speed(BOMB_SPEED),
	  m_inactiveCounter(0)
{
}

void Bomb::tick()
{
	if (m_state == BS_BOOM)
		return;

	if (m_inactiveCounter)
		m_inactiveCounter--;

	m_position.setX(m_position.x() + m_speed * sin(m_direction));
	m_position.setY(m_position.y() + m_speed * cos(m_direction));

	double random = (qrand() % 200 - 100) / 300.0;
	if (m_state == BS_LIT)
		random *= 2;

	if (m_position.x() < m_radius) {
		m_position.setX(m_radius * 2 - m_position.x());
		m_direction = -m_direction + random;
	}

	if (m_position.x() > m_game->width() - m_radius) {
		m_position.setX((m_game->width() - m_radius) * 2 - m_position.x());
		m_direction = -m_direction + random;
	}

	if (m_position.y() < m_radius) {
		m_position.setY(m_radius * 2 - m_position.y());
		m_direction = -m_direction + M_PI + random;
	}

	if (m_position.y() > m_game->height() - m_radius) {
		m_position.setY((m_game->height() - m_radius) * 2 - m_position.y());
		m_direction = -m_direction + M_PI + random;
	}
}

void Bomb::paint(QPainter *painter)
{
	painter->drawImage(m_position - QPoint(m_image->width() / 2, m_image->height() / 2), *m_image);
}

bool Bomb::detectCollision(Marker marker)
{
	if (m_inactiveCounter)
		return false;

	int distance = (m_position - marker.position).manhattanLength();
	if (distance < BOMB_EXPLODE_DISTANCE) {
		if (m_state == BS_NORMAL) {
			light();
			m_inactiveCounter = BOMB_INACTIVE;
			return true;
		} else if (m_state == BS_LIT) {
			explode();
			m_game->gameOver();
			return true;
		}
	}

	return false;
}

void Bomb::light()
{
	m_state = BS_LIT;
	m_speed = BOMB_LIT_SPEED;
	m_image = &Bomb::m_bombLit;
}

void Bomb::explode()
{
	m_state = BS_BOOM;
	m_image = &Bomb::m_boom;
}

//Constructor
BombGame::BombGame(QQuickItem *parent)
	: BaseWidget(parent),
	  m_timer(new QTimer(this)),
	  m_state(BG_GETREADY),
	  m_networkMgr(new QNetworkAccessManager(this)),
	  m_flashCounter(0)
{
	Bomb::m_bomb = QImage(":/img/bomb.png");
	Bomb::m_bombLit = QImage(":/img/bomb_lit.png");
	Bomb::m_boom = QImage(":/img/boom.png");

	m_getReadyImg = QImage(":/img/get_ready.png");
	m_gameOverImg = QImage(":/img/game_over.png");
	m_timerImg = QImage(":/img/timer.png");

	for(int i=0; i<10; i++)
		m_digitsImg.append(QImage(QString(":/img/digit_%1.png").arg(i)));

	m_timer->setInterval(TEXT_DURATION);
	connect(m_timer, SIGNAL(timeout()), this, SLOT(tick()));
	m_timer->start();
}

void BombGame::paint(QPainter *painter)
{
	if (m_flashCounter)
		m_flashCounter--;

	if (m_state == BG_GAMEOVER)
		m_flashCounter = 0;

	painter->setRenderHint(QPainter::Antialiasing);
	painter->setBrush(QBrush(m_flashCounter && (qrand() % 2) ? Qt::black : Qt::white));
	painter->drawRect(this->clipRect());

	int millis, digit0, digit1, digit2, digit3, digit4;

	switch(m_state) {
	case BG_GETREADY:
	case BG_WAITFORFEET:
		painter->drawImage(QPoint((width() - m_getReadyImg.width()) / 2.0, (height() - m_getReadyImg.height()) / 2.0), m_getReadyImg);
		break;

	case BG_GAMEOVER:
		painter->drawImage(QPoint((width() - m_gameOverImg.width()) / 2.0, (height() - m_gameOverImg.height()) / 2.0), m_gameOverImg);
	case BG_GAME:
		millis = m_time.elapsed();
		digit0 = millis / 600000;
		millis %= 600000;
		digit1 = millis / 60000;
		millis %= 60000;
		digit2 = millis / 10000;
		millis %= 10000;
		digit3 = millis / 1000;
		millis %= 1000;
		digit4 = millis / 100;

		if (!m_flashCounter) {
			painter->drawImage(QPoint(width() - 250, 10), m_timerImg);

			painter->drawImage(QPoint(width() - 295, 10), m_digitsImg.at(digit0));
			painter->drawImage(QPoint(width() - 250, 10), m_digitsImg.at(digit1));
			painter->drawImage(QPoint(width() - 180, 10), m_digitsImg.at(digit2));
			painter->drawImage(QPoint(width() - 135, 10), m_digitsImg.at(digit3));
			painter->drawImage(QPoint(width() - 70, 10), m_digitsImg.at(digit4));
		}

		foreach (Bomb *bomb, m_bombs) {
			bomb->paint(painter);
		}
		break;
	}
}

void BombGame::tick()
{
	switch(m_state) {
	case BG_GETREADY:
		m_markers.clear();
		m_state = BG_WAITFORFEET;
		m_timer->setInterval(100);
		break;
	case BG_WAITFORFEET:
		if (m_markers.count() >= EXPECTED_MARKER_COUNT) {
			m_state = BG_GAME;
			m_timer->setInterval(20);
			m_time.start();
			m_frame = 0;
		}
		break;
	case BG_GAME:
		if (m_frame % 100 == 0) {
			m_bombs.append(new Bomb(this));
		}
		foreach (Bomb *bomb, m_bombs) {
			bomb->tick();
			foreach (Marker event, m_markers) {
				if (bomb->detectCollision(event))
					m_flashCounter = FLASH_FRAMES;
			}
		}
		m_frame++;
		update();
		break;
	case BG_GAMEOVER:
		m_state = BG_GETREADY;
		m_timer->setInterval(TEXT_DURATION);
		foreach (Bomb *bomb, m_bombs) {
			delete bomb;
		}
		m_bombs.clear();
		update();
		break;
	}
}

void BombGame::sendHighscore(int highscore)
{
	#include "SendHighscore.inc"
}

void BombGame::gameOver()
{
	m_state = BG_GAMEOVER;
	m_timer->setInterval(TEXT_DURATION);
	sendHighscore(m_time.elapsed());
}

void BombGame::contactMove(mtq::ContactEvent *event)
{
	QString markerId = event->user() + ":" + event->foot();

	Marker marker;
	marker.position.setX(event->center().x());
	marker.position.setY(event->center().y());
	marker.rotation = event->rotation();
	marker.size.setHeight(event->size().height());
	marker.size.setWidth(event->size().width());

	m_markers.insert(markerId, marker);
}
