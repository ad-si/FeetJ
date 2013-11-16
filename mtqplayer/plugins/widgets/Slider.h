#pragma once

#include <QSvgRenderer>

#include "BaseWidget.h"

using namespace mtq;

class Slider: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
    QML_PLUGIN_REGISTRATION(Slider, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used
	Q_PROPERTY(qreal value READ value WRITE setValue NOTIFY valueChanged)
	Q_PROPERTY(bool active READ active WRITE setActive)

public:
	Slider(QQuickItem *parent = 0);

	void paint(QPainter *painter);

	qreal value();
	void setValue(qreal value);
	bool active();
	void setActive(bool state);

private:
	bool m_active;
	qreal m_value;
    QSvgRenderer *m_svgRenderer;

	void setValueByTapX(int x);

protected:
	void tapDown(TapEvent *event);
	void tapUp(TapEvent *event);
	void tapCancel(TapEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

signals:
	void valueChanged(qreal value);
};
