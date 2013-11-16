#include "EventConsole.h"

#include <QPainter>
#include <QDebug>

#include "Design.h"

#define sendSignalCaseType(EnumName, SignalName, Type) \
	case Event::EnumName: \
		SignalName((Type *)event); \
		break;

using namespace mtq;

//We need to register this Type in QML
QML_REGISTER_PLUGIN(EventConsole)

EventConsole::EventConsole(QQuickItem *parent)
    : QQuickItem(parent)
{
}

bool EventConsole::invokeMTQEventHandler(Event *event)
{
	if (!event)
		return false;

	switch (event->kind()) {
		sendSignalCaseType(ContactDown, contactDown, ContactEvent)
		sendSignalCaseType(ContactMove, contactMove, ContactEvent)
		sendSignalCaseType(ContactChanged, contactChanged, ContactEvent)
		sendSignalCaseType(ContactMerged, contactMerged, ContactEvent)
		sendSignalCaseType(ContactUp, contactUp, ContactEvent)

		sendSignalCaseType(TapDown, tapDown, TapEvent)
		sendSignalCaseType(TapCancel, tapCancel, TapEvent)
		sendSignalCaseType(TapUp, tapUp, TapEvent)
		sendSignalCaseType(Dwell, dwell, TapEvent)
		sendSignalCaseType(Tap, tap, TapEvent)
		sendSignalCaseType(DoubleTap, doubleTap, TapEvent)

		default:
			return false;
	}

	return true;
}

void EventConsole::contactDown(ContactEvent *)
{
    qDebug() << "contactDown";
}

void EventConsole::contactMove(ContactEvent *)
{
    qDebug() << "contactMove";
}

void EventConsole::contactChanged(ContactEvent *)
{
    qDebug() << "contactChanged";
}

void EventConsole::contactMerged(ContactEvent *)
{
    qDebug() << "contactMerge";
}

void EventConsole::contactUp(ContactEvent *)
{
    qDebug() << "contactUp";
}

void EventConsole::tapDown(TapEvent *)
{
    qDebug() << "tapDown";
}

void EventConsole::tapCancel(TapEvent *)
{
    qDebug() << "tapCancel";
}

void EventConsole::tapUp(TapEvent *)
{
    qDebug() << "tapUp";
}

void EventConsole::dwell(TapEvent *)
{
    qDebug() << "dwell";
}

void EventConsole::tap(TapEvent *)
{
    qDebug() << "tap";
}

void EventConsole::doubleTap(TapEvent *)
{
    qDebug() << "doubleTap";
}
