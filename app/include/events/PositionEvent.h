#pragma once

#include "Event.h"

#include <QPointF>
#include <QtQuick/QQuickItem>

namespace mtq {

	struct PositionInfo : EventInfo
	{
        QPointF center;
        QPointF mappedCenter;
	};

	class MTQ_EXPORT PositionEvent : public Event
	{
		Q_OBJECT
        Q_PROPERTY(QPointF center READ center)
        Q_PROPERTY(QPointF mappedCenter READ mappedCenter)
        Q_PROPERTY(qreal x READ x)
        Q_PROPERTY(qreal y READ y)

	public:
		PositionEvent(PositionInfo *positionInfo = new PositionInfo(), Kind kind = Event::None);
		PositionEvent(const PositionEvent &other);

        void mapFromScene(const QQuickItem &scene);

        QPointF center() const;
        QPointF mappedCenter() const;
        qreal x() const;
        qreal y() const;
    };

}
