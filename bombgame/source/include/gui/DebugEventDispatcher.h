#pragma once

#include "ExportDefines.h"
#include "events/Events.h"

namespace mtq {

	class MTQ_EXPORT DebugEventDispatcher {
	public:
		virtual bool invokeDebugEventHandler(DebugEvent *event);
	protected:

		virtual void debug(DebugEvent *event);
	};

}
