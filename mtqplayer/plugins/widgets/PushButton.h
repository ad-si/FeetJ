#pragma once

#include <QSvgRenderer>

#include "BaseWidget.h"

using namespace mtq;

class PushButton: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
    QML_PLUGIN_REGISTRATION(PushButton, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used
	Q_PROPERTY(QString text READ text WRITE setText)
	Q_PROPERTY(bool active READ active WRITE setActive)

public:
	PushButton(QQuickItem *parent = 0);
	PushButton(QQuickItem *parent, QString label);

	void paint(QPainter *painter);

	QString text();
	void setText(QString text);
	bool active();
	void setActive(bool state);

private:
	QString m_text;
	bool m_active;
    QSvgRenderer *m_svgRenderer;

protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void tapDown(mtq::TapEvent *event);
	void tapUp(mtq::TapEvent *event);
	void tapCancel(mtq::TapEvent *event);

signals:
	void pressed();
};
