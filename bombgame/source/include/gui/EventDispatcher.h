#pragma once

#include "ExportDefines.h"
#include "events/Events.h"

namespace mtq {

	class MTQ_EXPORT EventDispatcher {
	public:
		bool invokeEventHandler(Event *event);

	protected:
		virtual void contactDown(ContactEvent *);
		virtual void contactMove(ContactEvent *);
		virtual void contactUp(ContactEvent *);

		virtual void tapDown(TapEvent *);
		virtual void tapCancel(TapEvent *);
		virtual void tapUp(TapEvent *);
		virtual void dwell(TapEvent *);
		virtual void tap(TapEvent *);
		virtual void doubleTap(TapEvent *);
	};

}
