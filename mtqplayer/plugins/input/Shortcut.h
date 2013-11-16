#pragma once

#include <QQmlComponent>
#include <QKeyEvent>

#include "core/QmlPluginRegistry.h"

using namespace mtq;

/* BASED ON
 * http://kdeblog.mageprojects.com/2012/12/07/
 * application-wide-shortcuts-in-qml-this-time-without-qshortcut/
 * "The code is as free as it can get. No licence at all,
 * just free for whatever one wants to do with it." */

class Shortcut : public QObject
{
	Q_OBJECT

    QML_PLUGIN_REGISTRATION(Shortcut, "input")

	Q_PROPERTY(QVariant key READ key WRITE setKey NOTIFY keyChanged)

public:
	explicit Shortcut(QObject *parent = 0);

	void setKey(QVariant key);
    QVariant key();

	bool eventFilter(QObject *obj, QEvent *e);

signals:
	void keyChanged();
	void activated();
	void pressedAndHold();

private:
	QKeySequence m_keySequence;
	bool m_keypressAlreadySend;
};
