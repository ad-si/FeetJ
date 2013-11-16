#include "PaintField.h"

#include <QPainter>

//We need to register this Type in QML
QML_REGISTER_PLUGIN(PaintField)

//Constructor
PaintField::PaintField(QQuickItem *)
{
	setHeight(600);
	setWidth(600);
	setStrokeHue(0);
	setBackgroundBrightness(255);
}

void PaintField::paint(QPainter *painter)
{
	painter->setRenderHint(QPainter::Antialiasing);
	QRect rect(4, 4, width() - 8, height() - 8);
	painter->fillRect(rect, m_bgColor);

	for (int strokeI = 0; strokeI < m_strokes.size(); strokeI++)
	{
		painter->setPen(QPen(QBrush(m_strokeColors.at(strokeI)),4));
		if (m_strokes.at(strokeI).size() == 1)
			painter->drawPoint(m_strokes.at(strokeI).at(0));
		else if (m_strokes.at(strokeI).size() > 1) {
			for (int i = 0; i < m_strokes.at(strokeI).size() - 1; i++) {
				painter->drawLine(m_strokes.at(strokeI).at(i),
								  m_strokes.at(strokeI).at(i+1));
			}
		}
    }
}

qreal PaintField::strokeHue()
{
	return m_strokeHue;
}

void PaintField::setStrokeHue(qreal hue)
{
	m_strokeHue = hue;
}

int PaintField::backgroundBrightness()
{
	return m_backgroundBrightness;
}

void PaintField::setBackgroundBrightness(int brightness)
{
	m_backgroundBrightness = brightness;
	m_bgColor = QColor().fromHsv(1, 0, brightness);
	update();
}

void PaintField::contactDown(ContactEvent *event)
{
	BaseWidget::contactDown(event);
	m_strokes.push_back(QVector<QPointF>());
	m_strokeColors.push_back(QColor().fromHsvF(m_strokeHue, 1, 1));
	QPointF center = event->center();
	m_strokes.last().push_back(center);
	update();
}

void PaintField::contactMove(ContactEvent *event)
{
	BaseWidget::contactMove(event);
	QPointF center = event->center();
	m_strokes.last().push_back(center);
	update();
}

void PaintField::contactUp(ContactEvent *event)
{
    BaseWidget::contactUp(event);
	update();
}

void PaintField::mousePressEvent(QMouseEvent *event)
{
	BaseWidget::mousePressEvent(event);
	m_strokes.push_back(QVector<QPointF>());
	m_strokeColors.push_back(QColor().fromHsvF(m_strokeHue, 1, 1));
	QPointF center = event->pos();
	m_strokes.last().push_back(center);
	update();
}

void PaintField::mouseMoveEvent(QMouseEvent *event)
{
	BaseWidget::mouseMoveEvent(event);
	QPointF center = event->pos();
	m_strokes.last().push_back(center);
	update();
}

void PaintField::mouseReleaseEvent(QMouseEvent *event)
{
    BaseWidget::mouseReleaseEvent(event);
	update();
}
