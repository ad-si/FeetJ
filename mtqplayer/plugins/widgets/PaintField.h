#pragma once

#include <QVector>

#include "BaseWidget.h"

class PaintField : public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
    QML_PLUGIN_REGISTRATION(PaintField, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used
	Q_PROPERTY(qreal strokeHue READ strokeHue WRITE setStrokeHue)
	Q_PROPERTY(int backgroundBrightness READ backgroundBrightness WRITE setBackgroundBrightness)

public:
    PaintField(QQuickItem *parent = 0);

	void paint(QPainter *painter);

	qreal strokeHue();
	void setStrokeHue(qreal hue);
	int backgroundBrightness();
	void setBackgroundBrightness(int brightness);

private:
    QVector<QVector<QPointF> > m_strokes;

protected:
	void contactDown(ContactEvent *event);
	void contactMove(ContactEvent *event);
	void contactUp(ContactEvent *event);

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

	qreal m_strokeHue;
	int m_backgroundBrightness;
	QVector<QColor> m_strokeColors;
	QColor m_bgColor;

};


