#include "FjPlayer.h"
#include "qglobal.h"
#include <algorithm>
#include <QPainter>
#include "Design.h"
#include "player.h"
#include <QDebug>

using namespace mtq;

Player p;

//We need to register this Type in MTQ
MTQ_QML_REGISTER_PLUGIN(FjPlayer)

FjPlayer::FjPlayer(QQuickItem *parent)
	: BaseWidget(parent),
	  m_active(false),
	  m_value(0.5),
	  m_svgRenderer(new QSvgRenderer(design::widgetsSvgFile, this))
{
	setHeight(168 + 140); //toolTipHeight included
}

void FjPlayer::testStuff()
{
//	p.setTrackVolume(1,0);
//	p.setTrackVolume(2,0);
//	qDebug() << "Wow, I'm soo changing the volume right now!";
 //p.setTrackVolume(1,0.3);
 //p.setTrackVolume(2,0.1); Deprecaaaaaaaaaaaaaaaaaaaaaated
}

void FjPlayer::paint(QPainter *painter)
{
	int toolTipHeight = 140;
	int indicatorWidth = 160;
	int toolTipWidth = 160;
	int roundedCornerSize = 48;
	int frameThickness = 8;

	int frameHeight = height() - toolTipHeight;

	//Render frame
	m_svgRenderer->render(painter, "Slider::frame::topleft",	 QRect(0, toolTipHeight, roundedCornerSize, roundedCornerSize));
	m_svgRenderer->render(painter, "Slider::frame::vertical",	QRect(0,
																   toolTipHeight + roundedCornerSize,
																   frameThickness,
																   frameHeight - (2*roundedCornerSize)));
	m_svgRenderer->render(painter, "Slider::frame::bottomleft",  QRect(0, height() - roundedCornerSize,
																	 roundedCornerSize, roundedCornerSize));

	m_svgRenderer->render(painter, "Slider::frame::horizontal",  QRect(roundedCornerSize, toolTipHeight, width()-2*roundedCornerSize, frameThickness));
	m_svgRenderer->render(painter, "Slider::frame::horizontal",  QRect(roundedCornerSize, height() - frameThickness, width()-2*roundedCornerSize, frameThickness));

	m_svgRenderer->render(painter, "Slider::frame::topright",	QRect(width() - roundedCornerSize, toolTipHeight, roundedCornerSize, roundedCornerSize));
	m_svgRenderer->render(painter, "Slider::frame::vertical",	QRect(width() - frameThickness,
																   toolTipHeight + roundedCornerSize,
																   frameThickness,
																   frameHeight - (2*roundedCornerSize)));
	m_svgRenderer->render(painter, "Slider::frame::bottomright", QRect(width() - roundedCornerSize, height() - roundedCornerSize,
																	 roundedCornerSize, roundedCornerSize));

	//Render indicator (with tooltip if active)
	int pixelX = static_cast<int>((width() - indicatorWidth) * value());
	QString indicatorElementId;
	if (active()) {
		indicatorElementId = "pressed";
		m_svgRenderer->render(painter, "Slider::tooltip", QRect(pixelX, 0, toolTipWidth, toolTipHeight));

		// Render caption
		QRectF rect(pixelX, -5, toolTipWidth, toolTipHeight);
		painter->setPen(design::darkTextColor);
		painter->setFont(design::labelFont);
		painter->drawText(rect, Qt::AlignCenter ,QString::number(static_cast<int>(0.5 + 100*value()))+"%");

	} else {
		indicatorElementId = "normal";
	}

	m_svgRenderer->render(painter, "Slider::indicator::" + indicatorElementId + "::top",	 QRect(pixelX, toolTipHeight, indicatorWidth, roundedCornerSize - frameThickness));
	m_svgRenderer->render(painter, "Slider::indicator::" + indicatorElementId + "::middle",  QRect(pixelX,
																								 toolTipHeight + (roundedCornerSize - frameThickness),
																								 indicatorWidth,
																								 height() - toolTipHeight - 2*(roundedCornerSize - frameThickness)));
	m_svgRenderer->render(painter, "Slider::indicator::" + indicatorElementId + "::bottom",  QRect(pixelX, height() - (roundedCornerSize - frameThickness),
																								 indicatorWidth, roundedCornerSize - frameThickness));
}

void FjPlayer::processTapDown(mtq::TapEvent *event)
{
	if(static_cast<int>(event->mappedCenter().y()) >= 140) { //not on tooltip area

		setValueByTapX(static_cast<int>(event->mappedCenter().x()));
		setActive(true);
	}
}

void FjPlayer::processTapUp(mtq::TapEvent *event)
{
	setActive(false);
}

void FjPlayer::processTapCancel(mtq::TapEvent *event)
{
	setActive(false);
}

void FjPlayer::setValueByTapX(int x) {
	qreal newValue = (x - 80) / (width() - 160);
	newValue = std::max(0., std::min(1., newValue)); //crop to 0 and 1
	setValue(newValue);
	emit valueChanged(newValue);
	update();
}

void FjPlayer::crossfade(float pos)
{
	p.setCrossfade(pos);
}

qreal FjPlayer::value() const
{
	return m_value;
}

void FjPlayer::setValue(const qreal value)
{
	m_value = value;
}

bool FjPlayer::active() const
{
	return m_active;
}

void FjPlayer::setActive(const bool state)
{
	m_active = state;
	update();
}

void FjPlayer::test() {
	p.setTrack(1, p.lib.getAnotherTestSong());
	p.setTrack(2,p.lib.getAnotherTestSong());
	p.playTrack(1);
	p.playTrack(2);
	//p.effectFlanger(1);
	//p.effectReverb(2);
	printf("abgespült");
}

void FjPlayer::changeTrack(int channel, int title) {
	Song s = p.lib.getSong(title);
	p.setTrack(channel, s);
	printf("song gewechselt.");
}

void FjPlayer::play(int channel) {
	p.playTrack(channel);
}

void FjPlayer::toggleEffect(int track, int effectNumber)
{
	p.toggleEffect(track, effectNumber);
}

void FjPlayer::modifyEffect(int track, float x, float y)
{
	p.modifyEffect(track, x, y);
}

void FjPlayer::setVolume(int track, float vol) {
//	p.setTrackVolume(track, vol);
}
