#pragma once

#include <QQuickPaintedItem>
#include <QSvgRenderer>

#include "gui/DebugEventDispatcher.h"
#include "core/QmlPluginRegistry.h"

using namespace mtq;

class DebugWidget : public QQuickPaintedItem, public DebugEventDispatcher
{
	Q_OBJECT

    QML_PLUGIN_REGISTRATION(DebugWidget, "widgets")

public:
    DebugWidget(QQuickItem *parent = 0);
    void paint(QPainter *painter);
    void debug(DebugEvent *event);


private:

    void removeMarker(unsigned long id);
    qreal radToDegree(qreal angleInRad);

    int m_markerCount;
    qreal m_thresholdUp;
    qreal m_thresholdDown;
    qreal m_thresholdTilted;
    qreal m_thresholdUntilted;

	QSvgRenderer *m_svgRenderer;

    QMap<unsigned long, bool> m_exists;
    QMap<unsigned long, QPointF> m_positions;
    QMap<unsigned long, qreal> m_rotations;
    QMap<unsigned long, QString> m_contactStates;
    QMap<unsigned long, QString> m_tapStates;
    QMap<unsigned long, qreal> m_distancesToFloor;
    QMap<unsigned long, qreal> m_anglesToFloor;
    QMap<unsigned long, QStringList> m_debugStrings;



};
