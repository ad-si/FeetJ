#pragma once

#include <QQuickPaintedItem>
#include <QSvgRenderer>

#include "gui/EventDispatcher.h"
#include "core/QmlPluginRegistry.h"

class EventConsole : public QQuickItem, public mtq::EventDispatcher
{
	Q_OBJECT

	MTQ_QML_PLUGIN_REGISTRATION(EventConsole, "widgets")

public:
	EventConsole(QQuickItem *parent = 0);
	virtual ~EventConsole() {}

protected:
	bool invokeMTQEventHandler(const mtq::Event *);
	void contactDown(mtq::ContactEvent *);
	void contactMove(mtq::ContactEvent *);
	void contactChanged(mtq::ContactEvent *);
	void contactMerged(mtq::ContactEvent *);
	void contactUp(mtq::ContactEvent *);

	void tapDown(mtq::TapEvent *);
	void tapCancel(mtq::TapEvent *);
	void tapUp(mtq::TapEvent *);
	void dwell(mtq::TapEvent *);
	void tap(mtq::TapEvent *);
	void doubleTap(mtq::TapEvent *);
};
