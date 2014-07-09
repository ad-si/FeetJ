#pragma once

#include "BaseWidget.h"
#include "core/QmlPluginRegistry.h"

class ToggleButton: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
	MTQ_QML_PLUGIN_REGISTRATION(ToggleButton, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used
	Q_PROPERTY(QString activeTitle READ activeTitle WRITE setActiveTitle NOTIFY activeTitleChanged)
	Q_PROPERTY(QString inactiveTitle READ inactiveTitle WRITE setInactiveTitle NOTIFY inactiveTitleChanged)
	Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)

public:
	ToggleButton(QQuickItem *parent = 0);
	void paint(QPainter *painter);

	QString activeTitle() const;
	void setActiveTitle(const QString newActiveTitle);

	QString inactiveTitle() const;
	void setInactiveTitle(const QString newInactiveTitle);

	bool active();
	void setActive(bool newActive);

private:
	QString m_activeTitle;
	QString m_inactiveTitle;
	bool m_active;
	int m_progress;
	QTimer m_timer;

protected:
    void processTapDown(mtq::TapEvent *event);

signals:
	void activeChanged(bool active);
	void activeTitleChanged(QString activeTitle);
	void inactiveTitleChanged(QString inactiveTitle);

private slots:
	void animateMovement();
};
