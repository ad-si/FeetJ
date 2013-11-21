#pragma once

#include <QObject>
#include <QEvent>
#include <QSharedPointer>

#include "ExportDefines.h"

namespace mtq {

	struct EventInfo
	{
		QString user;
		QString foot;
	};

	typedef QSharedPointer<EventInfo> EventInfoPtr;

	class MTQ_EXPORT Event : public QObject, public QEvent
	{
		Q_OBJECT
		Q_PROPERTY(Kind kind READ kind)
		Q_PROPERTY(bool handled READ isHandled WRITE setHandled)
		Q_PROPERTY(QString user READ user)
		Q_PROPERTY(QString foot READ foot)

	public:
		Q_ENUMS(Kind)

		enum Kind
		{
			None,						//!< Basic, unspecified event

			Debug,					  //!< A debug event

			ContactDown,				//!< A contact appeared
			ContactMove,				//!< A contact moved
			ContactChanged,				//!< A contact became larger (e.g. a person sat down)
			ContactMerged,				//!< A new contact was created by merging two
			ContactUp,					//!< A contact disappeared.

			TapDown,					//!< A short tap started
			TapUp,						//!< A short tap was released
			TapCancel,					//!< The user moved his feet after a tap started, thus it's a usal walk
			Dwell,						//!< The user tapped for very long
			Tap,						//!< A sequence of tap down and tap up occured
			DoubleTap					//!< Two taps in a short period of time occured at the same position
		};

		static QEvent::Type type()	  //!< A user defined QEvent::Type type, common to all Events
		{ return typeOfEvent; }

		Event(EventInfo *info = new EventInfo(), Kind kind = None);
		Event(const Event &other);
		virtual ~Event();

		bool isHandled() const;
		void setHandled(const bool handled);
		Kind kind() const;
		QString user() const;
		QString foot() const;

	protected:
		EventInfoPtr m_info;
		Kind m_kind;
		bool m_handled;

	private:
		static QEvent::Type typeOfEvent;
	};

}
