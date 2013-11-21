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

protected:
	// Event handlers
	virtual void contactDown(mtq::ContactEvent *event);
	virtual void contactMove(mtq::ContactEvent *event);
	virtual void contactChanged(mtq::ContactEvent *event);
	virtual void contactMerged(mtq::ContactEvent *event);
	virtual void contactUp(mtq::ContactEvent *event);

	virtual void tapDown(mtq::TapEvent *event);
	virtual void tapCancel(mtq::TapEvent *event);
	virtual void tapUp(mtq::TapEvent *event);
	virtual void dwell(mtq::TapEvent *event);
	virtual void tap(mtq::TapEvent *event);
	virtual void doubleTap(mtq::TapEvent *event);

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent (QMouseEvent *event);


signals:
	// Signals to be sent, for instance to QML
	void qmlContactDown(mtq::ContactEvent *event);
	void qmlContactMove(mtq::ContactEvent *event);
	void qmlContactChanged(mtq::ContactEvent *event);
	void qmlContactMerged(mtq::ContactEvent *event);
	void qmlContactUp(mtq::ContactEvent *event);

	void qmlTapDown(mtq::TapEvent *event);
	void qmlTapCancel(mtq::TapEvent *event);
	void qmlTapUp(mtq::TapEvent *event);
	void qmlDwell(mtq::TapEvent *event);
	void qmlTap(mtq::TapEvent *event);
	void qmlDoubleTap(mtq::TapEvent *event);

	void qmlMousePress(QMouseEvent *event);
	void qmlMouseRelease(QMouseEvent *event);

};


