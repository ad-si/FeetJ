#pragma once

#include "BaseWidget.h"
#include "core/QmlPluginRegistry.h"

using namespace mtq;

class ToggleButton: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
    QML_PLUGIN_REGISTRATION(ToggleButton, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used
	Q_PROPERTY(QString activeTitle READ activeTitle WRITE setActiveTitle)
	Q_PROPERTY(QString inactiveTitle READ inactiveTitle WRITE setInactiveTitle)
	Q_PROPERTY(bool active READ active WRITE setActive)

public:
	ToggleButton(QQuickItem *parent = 0);
	void paint(QPainter *painter);

	QString activeTitle();
	void setActiveTitle(QString newActiveTitle);

	QString inactiveTitle();
	void setInactiveTitle(QString newInactiveTitle);

	bool active();
	void setActive(bool newActive);

private:
	QString m_activeTitle;
	QString m_inactiveTitle;
	bool m_active;
	int m_progress;
	QTimer m_timer;

protected:
	void mousePressEvent(QMouseEvent *event);
	void tapDown(mtq::TapEvent *event);

signals:
	void changed(bool active);

private slots:
	void animateMovement();
};

