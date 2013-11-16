#pragma once

#include "events/PositionEvent.h"

#include <QPointF>
#include <QSizeF>

namespace mtq {

    struct ContactInfo : PositionInfo
    {
        qreal rotation;
        QSizeF size;
    };

    class MTQ_EXPORT ContactEvent : public PositionEvent
	{
        Q_OBJECT
        Q_PROPERTY(qreal rotation READ rotation)
        Q_PROPERTY(QSizeF size READ size)

	public:
        ContactEvent(ContactInfo *contactInfo = new ContactInfo(), Kind kind = Event::None);
        ContactEvent(const ContactEvent &other);

        qreal rotation() const;
        QSizeF size() const;
	};

}
