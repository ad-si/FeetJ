#pragma once

#include <QQuickPaintedItem>

#include "events/Events.h"
#include "gui/EventDispatcher.h"
#include "core/QmlPluginRegistry.h"

//This is a generic widget. Inherit from BaseWidget to get mouse and floor events
class BaseWidget : public QQuickPaintedItem, public mtq::EventDispatcher
{
	//We need to tell the Qt-Preprocessor
	Q_OBJECT

public:
	BaseWidget(QQuickItem *parent = 0);
	void paint(QPainter *painter);
	virtual ~BaseWidget() {}

private:
	// Event handlers
    void contactDown(mtq::ContactEvent *event);
    void contactMove(mtq::ContactEvent *event);
    void contactChanged(mtq::ContactEvent *event);
    void contactMerged(mtq::ContactEvent *event);
    void contactUp(mtq::ContactEvent *event);

    void tapDown(mtq::TapEvent *event);
    void tapCancel(mtq::TapEvent *event);
    void tapUp(mtq::TapEvent *event);
    void dwell(mtq::TapEvent *event);
    void tap(mtq::TapEvent *event);
    void doubleTap(mtq::TapEvent *event);

    void mouseDoubleClickEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent (QMouseEvent *event);

protected:
	virtual void processContactDown(mtq::ContactEvent *);
    virtual void processContactMove(mtq::ContactEvent *);
    virtual void processContactChanged(mtq::ContactEvent *);
    virtual void processContactMerged(mtq::ContactEvent *);
    virtual void processContactUp(mtq::ContactEvent *);

    virtual void processTapDown(mtq::TapEvent *);
    virtual void processTapCancel(mtq::TapEvent *);
    virtual void processTapUp(mtq::TapEvent *);
    virtual void processDwell(mtq::TapEvent *);
    virtual void processTap(mtq::TapEvent *);
    virtual void processDoubleTap(mtq::TapEvent *);

signals:
	void mtqContactDown(QObject *event);
	void mtqContactMove(QObject *event);
	void mtqContactChanged(QObject *event);
	void mtqContactMerged(QObject *event);
	void mtqContactUp(QObject *event);

	void mtqTapDown(QObject *event);
	void mtqTapCancel(QObject *event);
	void mtqTapUp(QObject *event);
	void mtqDwell(QObject *event);
	void mtqTap(QObject *event);
	void mtqDoubleTap(QObject *event);
};
