#pragma once

#include <QVector>

#include "BaseWidget.h"

class PaintField : public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
	MTQ_QML_PLUGIN_REGISTRATION(PaintField, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used
	Q_PROPERTY(qreal strokeHue READ strokeHue WRITE setStrokeHue NOTIFY strokeHueChanged)
	Q_PROPERTY(int backgroundBrightness READ backgroundBrightness WRITE setBackgroundBrightness NOTIFY backgroundBrightnessChanged)

public:
	PaintField(QQuickItem *parent = 0);

	void paint(QPainter *painter);

	qreal strokeHue() const;
	void setStrokeHue(const qreal hue);
	int backgroundBrightness() const;
	void setBackgroundBrightness(const int brightness);

private:
	QVector<QVector<QPointF> > m_strokes;

protected:
    void processContactDown(mtq::ContactEvent *event);
    void processContactMove(mtq::ContactEvent *event);
    void processContactUp(mtq::ContactEvent *event);

	qreal m_strokeHue;
	int m_backgroundBrightness;
	QVector<QColor> m_strokeColors;
	QColor m_bgColor;

signals:
	void strokeHueChanged(qreal strokeHue);
	void backgroundBrightnessChanged(int backgroundBrightness);
};
