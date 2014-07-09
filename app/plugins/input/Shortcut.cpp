#include "Shortcut.h"

#include <QCoreApplication>

//BASED ON
//http://kdeblog.mageprojects.com/2012/12/07/application-wide-shortcuts-in-qml-this-time-without-qshortcut/
//"The code is as free as it can get. No licence at all, just free for whatever one wants to do with it."

//We need to register this Type in QML
MTQ_QML_REGISTER_PLUGIN(Shortcut)

Shortcut::Shortcut(QObject *parent)
	: QObject(parent),
	  m_keySequence(),
	  m_keypressAlreadySend(false)
{
	qApp->installEventFilter(this);
}

QVariant Shortcut::key() const
{
	return m_keySequence;
}

void Shortcut::setKey(const QVariant key)
{
	QKeySequence newKey = key.value<QKeySequence>();
	if(m_keySequence != newKey) {
		m_keySequence = key.value<QKeySequence>();
		emit keyChanged();
	}
}

bool Shortcut::eventFilter(QObject *obj, QEvent *e)
{
	if(e->type() == QEvent::KeyPress && !m_keySequence.isEmpty()) {
		QKeyEvent *keyEvent = static_cast<QKeyEvent*>(e);

		// Just mod keys is not enough for a shortcut, block them just by returning.
		if (keyEvent->key() >= Qt::Key_Shift && keyEvent->key() <= Qt::Key_Alt) {
			return QObject::eventFilter(obj, e);
		}

		int keyInt = keyEvent->modifiers() + keyEvent->key();

		if(!m_keypressAlreadySend && QKeySequence(keyInt) == m_keySequence) {
			m_keypressAlreadySend = true;
			emit activated();
		}
	}
	else if(e->type() == QEvent::KeyRelease) {
		m_keypressAlreadySend = false;
	}
	return QObject::eventFilter(obj, e);
}
