#pragma once

#include <QSvgRenderer>

#include "BaseWidget.h"

class GenericSvgButton: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
	MTQ_QML_PLUGIN_REGISTRATION(GenericSvgButton, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used
	Q_PROPERTY(QString svgElementId READ svgElementId WRITE setSvgElementId NOTIFY idChanged)

public:
	GenericSvgButton(QQuickItem *parent = 0);

	void paint(QPainter *painter);

	QString svgElementId() const;
	void setSvgElementId(const QString newId);
	bool active() const;
	void setActive(const bool active);

private:
	bool m_active;
	QString m_svgElementId;
	QSvgRenderer *m_svgRenderer;

protected:
    void processTapDown(mtq::TapEvent *event);
    void processTapUp(mtq::TapEvent *event);
    void processTapCancel(mtq::TapEvent *event);

signals:
	void pressed();
	void idChanged(QString id);
};
