#pragma once

#include <QQuickPaintedItem>

#include "events/Events.h"
#include "gui/EventDispatcher.h"
#include "core/QmlPluginRegistry.h"

using namespace mtq;

//This is a generic widget. Inherit from BaseWidget to get mouse and floor events
class BaseWidget : public QQuickPaintedItem, public EventDispatcher
{
	//We need to tell the Qt-Preprocessor
	Q_OBJECT

public:
	BaseWidget(QQuickItem *parent = 0);
	void paint(QPainter *painter);
	virtual ~BaseWidget() {}

protected:
	// Event handlers
    virtual void contactDown(ContactEvent *event);
    virtual void contactMove(ContactEvent *event);
    virtual void contactChanged(ContactEvent *event);
    virtual void contactMerged(ContactEvent *event);
    virtual void contactUp(ContactEvent *event);

    virtual void tapDown(TapEvent *event);
    virtual void tapCancel(TapEvent *event);
    virtual void tapUp(TapEvent *event);
    virtual void dwell(TapEvent *event);
    virtual void tap(TapEvent *event);
    virtual void doubleTap(TapEvent *event);

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent (QMouseEvent *event);


signals:
	// Signals to be sent, for instance to QML
    void qmlContactDown(QObject *event);
    void qmlContactMove(QObject *event);
    void qmlContactChanged(QObject *event);
    void qmlContactMerged(QObject *event);
    void qmlContactUp(QObject *event);

    void qmlTapDown(QObject *event);
    void qmlTapCancel(QObject *event);
    void qmlTapUp(QObject *event);
    void qmlDwell(QObject *event);
    void qmlTap(QObject *event);
    void qmlDoubleTap(QObject *event);

	void qmlMousePress(QMouseEvent *event);
	void qmlMouseRelease(QMouseEvent *event);

};
