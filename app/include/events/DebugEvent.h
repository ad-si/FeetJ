#pragma once

#include "Event.h"

#include <QPointF>
#include <QVariant>

namespace mtq {

	struct DebugInfo : EventInfo
	{
		QVariant debugInfo;
	};

	class MTQ_EXPORT DebugEvent : public Event
	{
		Q_OBJECT
		Q_PROPERTY(QVariant debugInfo READ debugInfo)

	public:
		DebugEvent(DebugInfo *debugInfo = new DebugInfo(), Kind kind = Event::None);
		DebugEvent(const DebugEvent &other);

		QVariant debugInfo() const;
	};

}
