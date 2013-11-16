#pragma once

#include "Event.h"

#include <QPointF>

namespace mtq {

    struct PositionInfo : EventInfo
    {
        QPointF center;
    };

    class MTQ_EXPORT PositionEvent : public Event
    {
        Q_OBJECT
        Q_PROPERTY(QPointF center READ center)
        Q_PROPERTY(qreal x READ x)
        Q_PROPERTY(qreal y READ y)

    public:
        PositionEvent(PositionInfo *positionInfo = new PositionInfo(), Kind kind = Event::None);
        PositionEvent(const PositionEvent &other);

        QPointF center() const;
        Q_INVOKABLE qreal x() const;
        Q_INVOKABLE qreal y() const;
    };

}
