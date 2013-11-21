#pragma once

#include <QQuickView>

#include "events/Events.h"
#include "gui/EventDispatcher.h"
#include "gui/DebugEventDispatcher.h"

namespace mtq {

	struct SceneViewDetail;

	class SceneView : public QQuickView
	{
		Q_OBJECT

	public:
		explicit SceneView(QWindow *parent = 0);
		virtual ~SceneView();

	public slots:
		void debugEvent(DebugEvent event);
		void tapEvent(TapEvent event);
		void contactEvent(ContactEvent event);
		void show();

	protected:
		void moveToScreen(bool primary);

		void reload(bool clearCache = true);

		void keyPressEvent(QKeyEvent *event);

	private:
		void setupQMLEnvironment();
		void setupTracking();
		void setQMLSource();

		void sendEventToTouchedItems(PositionEvent *event);
		void sendEventToDebugItems(DebugEvent *event);

		QList<EventDispatcher *> touchedItems(PositionEvent *event);
		void traverseChildren(QQuickItem *item, QList<EventDispatcher *> &accumulator, QPointF &scenePos);
		void traverseChildrenDebug(QQuickItem *item, QList<DebugEventDispatcher *> &accumulator);

		SceneViewDetail *m_detail;
		QUrl m_source;
	};

}
