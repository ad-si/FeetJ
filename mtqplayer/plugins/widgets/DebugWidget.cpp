#include "DebugWidget.h"

#include <QPainter>

#include "Design.h"

using namespace mtq;

//We need to register this Type in QML
QML_REGISTER_PLUGIN(DebugWidget)

DebugWidget::DebugWidget(QQuickItem *)
	: m_svgRenderer(new QSvgRenderer(design::widgetsSvgFile, this))
{
    setHeight(300);
    setWidth(300);
    setAcceptedMouseButtons(Qt::LeftButton | Qt::RightButton | Qt::MidButton);
    //here the stuff get's initialized

    m_markerCount = 0;

    m_thresholdUp = 0;
    m_thresholdDown = 0;
    m_thresholdTilted = 0;
    m_thresholdUntilted = 0;

    //not it gets filled with test data

    m_markerCount = 2;

    m_thresholdUp = 2.384;
    m_thresholdDown = 0.12;
    m_thresholdTilted = 13.5;
    m_thresholdUntilted = 0.12;

    //marker specific stuff
/*
    unsigned long anID = 2;
    m_exists[anID] = true;
    m_positions[anID] = QPointF(150.3,310.8);
    m_rotations[anID] = 1.57;
    m_contactStates[anID] = QString("contactDown");
    m_tapStates[anID] = QString("tapDown");
    m_distancesToFloor[anID] = 3.21;
    m_anglesToFloor[anID] = 0.21;

    anID = 5;
    m_exists[anID] = true;
    m_positions[anID] = QPointF(550.3,510.8);
    m_rotations[anID] = 1.57;
    m_contactStates[anID] = QString("contactDown");
    m_tapStates[anID] = QString("tapDown");
    m_distancesToFloor[anID] = 3.21;
    m_anglesToFloor[anID] = 0.21;*/

}

void DebugWidget::removeMarker(unsigned long id) {
    m_exists[id] = false;
}

void DebugWidget::paint(QPainter *painter)
{
    int debugIndicatorSize = 50;
    int contactStateIndicatorSize = 60;
    int debugTextHeight = 50;
    int space = 3;
    int markerSize = 100;
    int rotationIndicatorSize = 50;
    qreal indicatorDistanceScale = 0.5;

    painter->setPen(design::labelFontColor);
    painter->setFont(design::debugFont);


    for(int i = 0; i < m_markerCount; i++) {
		m_svgRenderer->render(painter, "DebugWidget::alvarMarker", QRect(space + i* (space + debugIndicatorSize), 10, debugIndicatorSize, debugIndicatorSize));
    }

	m_svgRenderer->render(painter, "DebugWidget::thresholdHorizontal", QRect(space , space + space + debugIndicatorSize, debugIndicatorSize, debugIndicatorSize));
    painter->drawText(QRect(2*space + debugIndicatorSize, space + debugIndicatorSize, debugIndicatorSize, debugTextHeight),
                      Qt::AlignCenter,
                      QString::number(m_thresholdUp));

    painter->drawText(QRect(2*space + debugIndicatorSize, 7*space + debugIndicatorSize, debugIndicatorSize, debugTextHeight),
                      Qt::AlignCenter,
                      QString::number(m_thresholdDown));

	m_svgRenderer->render(painter, "DebugWidget::thresholdAngular", QRect(space , space + 2 * (space + debugIndicatorSize), debugIndicatorSize, debugIndicatorSize));



    painter->drawText(QRect(2*space + debugIndicatorSize, 2*space + 2*debugIndicatorSize, debugIndicatorSize, debugTextHeight),
                      Qt::AlignCenter,
                      QString::number(m_thresholdTilted));

    painter->drawText(QRect(2*space + debugIndicatorSize, 8*space + 2*debugIndicatorSize, debugIndicatorSize, debugTextHeight),
                      Qt::AlignCenter,
                      QString::number(m_thresholdUntilted));

    //Marker-specific Debug-Info

    QMapIterator<unsigned long, bool> i(m_exists);
    while(i.hasNext()) {
        i.next();
        if(m_exists[i.key()]) {
            //Marker
            int centerX = static_cast<int>(m_positions[i.key()].x()+0.5);
            int centerY = static_cast<int>(m_positions[i.key()].y()+0.5);
			m_svgRenderer->render(painter, "DebugWidget::marker",
                                 QRect(centerX - markerSize/2,
                                       centerY - markerSize/2,
                                       markerSize, markerSize));

            //Rotation
            int rotationIndicatorX = cos(m_rotations[i.key()]) * markerSize/2;
            int rotationIndicatorY = sin(m_rotations[i.key()]) * markerSize/2;

			m_svgRenderer->render(painter, "DebugWidget::rotationIndicator",
                                 QRect(centerX + rotationIndicatorX - rotationIndicatorSize/2,
                                       centerY + rotationIndicatorY - rotationIndicatorSize/2,
                                       rotationIndicatorSize, rotationIndicatorSize));


            painter->drawText(QRect(centerX + rotationIndicatorX - rotationIndicatorSize/2,
                                    centerY + rotationIndicatorY - rotationIndicatorSize/2,
                                    rotationIndicatorSize, rotationIndicatorSize),
                              Qt::AlignCenter,
                              QString::number(static_cast<int>(radToDegree(m_rotations[i.key()]))));

            //ID
            painter->drawText(QRect(centerX + static_cast<int>(indicatorDistanceScale*80),
                                    centerY - static_cast<int>(indicatorDistanceScale*215),
                                    rotationIndicatorSize, rotationIndicatorSize),
                              Qt::AlignCenter,
                              "id: " + QString::number(i.key()));


            QString distanceString;
            distanceString.sprintf("floorDistance: %.2f", m_distancesToFloor[i.key()]);

            //DistanceToFloor
            painter->drawText(QRect(centerX + static_cast<int>(indicatorDistanceScale*130),
                                    centerY - static_cast<int>(indicatorDistanceScale*135),
                                    5*rotationIndicatorSize, rotationIndicatorSize),
                              Qt::AlignLeft,
                              distanceString);


            //normalToFloorAngle
            painter->drawText(QRect(centerX + static_cast<int>(indicatorDistanceScale*150),
                                    centerY - static_cast<int>(indicatorDistanceScale*80),
                                    5*rotationIndicatorSize, rotationIndicatorSize),
                              Qt::AlignLeft,
                              "floorAngle: " + QString::number(static_cast<int>(radToDegree(m_anglesToFloor[i.key()]))));


            //contactState
			m_svgRenderer->render(painter, "DebugWidget::" + m_contactStates[i.key()],
                                 QRect(centerX + static_cast<int>(indicatorDistanceScale*150),
                                       centerY - static_cast<int>(indicatorDistanceScale*20), contactStateIndicatorSize, contactStateIndicatorSize));

            //tapState
			m_svgRenderer->render(painter, "DebugWidget::" + m_tapStates[i.key()],
                                 QRect(centerX + static_cast<int>(indicatorDistanceScale*90),
                                       centerY + static_cast<int>(indicatorDistanceScale*110),
                                       contactStateIndicatorSize, contactStateIndicatorSize));

            //debugString
            QString console = m_debugStrings[i.key()].join('\n');
            painter->drawText(QRect(centerX - static_cast<int>(indicatorDistanceScale*160),
                                    centerY + static_cast<int>(indicatorDistanceScale*150),
                                    7*rotationIndicatorSize, 3*rotationIndicatorSize),
                              Qt::AlignLeft,
                              console);
        }

    }


}

qreal DebugWidget::radToDegree(qreal angleInRad) {
    return 180*angleInRad / 3.14159;
}

void DebugWidget::debug(DebugEvent *event_) {
    DebugEvent event = *event_;
    QMap<QString, QVariant> eventMap = event.debugInfo().toMap();
    if (eventMap["type"].toString() == "marker") {
        if (eventMap.contains("id")) {

            int anID = eventMap["id"].toUInt();

            m_exists[anID]		= !(eventMap["deleted"].toBool());

            m_positions[anID]		= eventMap["position"].toPointF();
            m_anglesToFloor[anID]	= eventMap["normalToFloorAngle"].toReal();
            m_rotations[anID]		= eventMap["rotation"].toReal();
            m_distancesToFloor[anID]= eventMap["distanceToFloor"].toReal();
            if (eventMap["text"].toString()!="") {
                m_debugStrings[anID].append(eventMap["text"].toString().trimmed());
                if (m_debugStrings[anID].size()>5)
                    m_debugStrings[anID].removeFirst();
            }

            m_contactStates[anID] = QString("contactDown");
            m_tapStates[anID] = QString("tapDown");
        }
    }
    update();

}
