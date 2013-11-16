#pragma once

#include <QImage>
#include <QNetworkAccessManager>

#include "BaseWidget.h"

class BombGame;

struct Marker {
    QPoint position;
    qreal rotation;
    QSize size;
};

class Bomb {
public:
    typedef enum {BS_NORMAL, BS_LIT, BS_BOOM} BombState;

    Bomb(BombGame *game);

    void tick();
    void paint(QPainter *painter);
    bool detectCollision(Marker marker);
    void light();
    void explode();

    static QImage m_bomb;
    static QImage m_bombLit;
    static QImage m_boom;

private:
    BombGame *m_game;
    QImage *m_image;
    BombState m_state;
    int m_radius;
    QPoint m_position;
    double m_direction;
    double m_speed;
    int m_inactiveCounter;
};

class BombGame : public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
    QML_PLUGIN_REGISTRATION(BombGame, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used

public:
    typedef enum {BG_GETREADY, BG_WAITFORFEET, BG_GAME, BG_GAMEOVER} GameState;

    BombGame(QQuickItem *parent = 0);

	void paint(QPainter *painter);
    void gameOver();

protected:
    void contactMove(ContactEvent *event);

private slots:
    void tick();

private:
    void sendHighscore(int highscore);

    QTime m_time;
    QTimer *m_timer;
    QList<Bomb*> m_bombs;
    int m_frame;
    GameState m_state;
    QImage m_getReadyImg;
    QImage m_gameOverImg;
    QImage m_timerImg;
    QList<QImage> m_digitsImg;
    QMap<QString, Marker> m_markers;
    QNetworkAccessManager *m_networkMgr;
    int m_flashCounter;
};
