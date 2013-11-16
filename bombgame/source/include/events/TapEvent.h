#pragma once

#include "PositionEvent.h"

#include <QPointF>

namespace mtq {

    struct TapInfo : PositionInfo
    {
    };

    class MTQ_EXPORT TapEvent : public PositionEvent
    {
        Q_OBJECT

    public:
        TapEvent(TapInfo *tapInfo = new TapInfo(), Kind kind = Event::None);
        TapEvent(const TapEvent &other);
    };

}
