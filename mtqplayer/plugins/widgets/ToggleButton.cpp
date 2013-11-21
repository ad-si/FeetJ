#include "ToggleButton.h"

#include <QPainter>

#include "Design.h"

using namespace mtq;

//We need to register this Type in QML
MTQ_QML_REGISTER_PLUGIN(ToggleButton)

//ToggleButton, works like a nice modern checkBox
ToggleButton::ToggleButton(QQuickItem *parent)
	: BaseWidget(parent)
{
	setWidth(200);
	setHeight(80);

	m_timer.setInterval(20);
	m_progress = 100;
	m_active = false;
	connect(&m_timer, SIGNAL(timeout()), this, SLOT(animateMovement()));
}

void ToggleButton::paint(QPainter *painter)
{
	painter->setRenderHint(QPainter::Antialiasing);
	painter->setRenderHint(QPainter::HighQualityAntialiasing);

	//Render the Text
	QRectF rect_left(0, 0, width()/2, height());
	QRectF rect_right(width()/2, 0, width()/2, height());
	painter->setPen(design::labelFontColor);
	painter->setFont(design::labelFont);
	painter->drawText(rect_left, Qt::AlignCenter, m_activeTitle);
	painter->drawText(rect_right, Qt::AlignCenter, m_inactiveTitle);

	//Render Button
	QColor buttonColor = QColor(
				(design::normalColor.red() * m_progress + design::activeColor.red() * (100 - m_progress)) / 100,
				(design::normalColor.green() * m_progress + design::activeColor.green() * (100 - m_progress)) / 100,
				(design::normalColor.blue() * m_progress + design::activeColor.blue() * (100 - m_progress)) / 100);

	painter->setBrush(buttonColor);
	painter->setPen(Qt::NoPen);
	painter->drawRoundedRect(
				QRect(
					design::borderWidth + (width() / 2 - design::borderWidth) * m_progress / 100,
					design::borderWidth,
					(width()-2*design::borderWidth)/2,
					height()-2*design::borderWidth),
				design::borderRadius, design::borderRadius);

	// Render border
	painter->setPen(QPen(QBrush(design::normalColor), design::borderWidth));
	painter->setBrush(Qt::NoBrush);
	painter->drawRoundedRect(
				QRect(
					design::borderWidth,
					design::borderWidth,
					width()-2*design::borderWidth,
					height()-2*design::borderWidth),
				design::borderRadius, design::borderRadius);
}

void ToggleButton::animateMovement()
{
	if(m_active)
		m_progress -= 10;
	else
		m_progress += 10;

	m_progress = m_progress < 0 ? 0 : (m_progress > 100 ? 100 : m_progress);
	if(m_progress == 0 || m_progress == 100) m_timer.stop();
	update();
}

void ToggleButton::processTapDown(mtq::TapEvent *event)
{
	setActive(!active());
}

QString ToggleButton::activeTitle() const
{
	return m_activeTitle;
}

void ToggleButton::setActiveTitle(QString newActiveTitle)
{
	m_activeTitle = newActiveTitle;
	update();
}

QString ToggleButton::inactiveTitle() const
{
	return m_inactiveTitle;
}

void ToggleButton::setInactiveTitle(QString newInactiveTitle)
{
	m_inactiveTitle = newInactiveTitle;
	update();
}

bool ToggleButton::active()
{
	return m_active;
}

void ToggleButton::setActive(bool newActive)
{
	if (newActive != m_active) {
		m_active = newActive;
		m_timer.start();
		emit activeChanged(m_active);
	}
}
