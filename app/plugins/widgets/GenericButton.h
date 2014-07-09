#ifndef GENERICBUTTON_H
#define GENERICBUTTON_H

#pragma once
#include <QSvgRenderer>
#include "BaseWidget.h"

class GenericButton: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
	MTQ_QML_PLUGIN_REGISTRATION(GenericButton, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used
	Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
	Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)

public:
	GenericButton(QQuickItem *parent = 0);
	GenericButton(QQuickItem *parent, const QString label);

	void paint(QPainter *painter);

	QString text() const;
	void setText(const QString text);

	bool active() const;
	void setActive(const bool state);

	QColor color() const;
	void setColor(const QColor color);

private:
	QString m_text;
	bool m_active;
	QSvgRenderer *m_svgRenderer;
	QColor m_color;

protected:
	void processTapDown(mtq::TapEvent *event);
	void processTapUp(mtq::TapEvent *event);
	void processTapCancel(mtq::TapEvent *event);

signals:
	void pressed();
	void textChanged(QString text);
	void activeChanged(bool active);
	void colorChanged(QColor color);
};


#endif
