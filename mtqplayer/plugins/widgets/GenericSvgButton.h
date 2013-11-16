#pragma once

#include <QSvgRenderer>

#include "BaseWidget.h"

using namespace mtq;

class GenericSvgButton: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
    QML_PLUGIN_REGISTRATION(GenericSvgButton, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used
	Q_PROPERTY(QString svgElementId READ svgElementId WRITE setSvgElementId)

public:
	GenericSvgButton(QQuickItem *parent = 0);

	void paint(QPainter *painter);

	QString svgElementId();
	void setSvgElementId(QString newId);
	bool active();
	void setActive(bool active);

private:
	bool m_active;
	QString m_svgElementId;
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
