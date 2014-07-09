#include "BaseWidget.h"

using namespace mtq;

BaseWidget::BaseWidget(QQuickItem *parent)
	: QQuickPaintedItem(parent)
{
	setWidth(200);
	setHeight(200);
	setAcceptedMouseButtons(Qt::LeftButton | Qt::RightButton | Qt::MidButton);
}

void BaseWidget::paint(QPainter *)
{
}

// we forward the floor events for use in QML
void BaseWidget::contactDown(mtq::ContactEvent *event)
{
    event->mapFromScene(this);
    emit mtqContactDown(event);
    processContactDown(event);
}

void BaseWidget::contactMove(mtq::ContactEvent *event)
{
    event->mapFromScene(this);
    emit mtqContactMove(event);
    processContactMove(event);
}

void BaseWidget::contactChanged(mtq::ContactEvent *event)
{
    event->mapFromScene(this);
    emit mtqContactChanged(event);
    processContactChanged(event);
}

void BaseWidget::contactMerged(mtq::ContactEvent *event)
{
    event->mapFromScene(this);
    emit mtqContactMerged(event);
    processContactMerged(event);
}

void BaseWidget::contactUp(mtq::ContactEvent *event)
{
    event->mapFromScene(this);
    emit mtqContactUp(event);
    processContactUp(event);
}

void BaseWidget::tapDown(mtq::TapEvent *event)
{
    event->mapFromScene(this);
    emit mtqTapDown(event);
    processTapDown(event);
}

void BaseWidget::tapCancel(mtq::TapEvent *event)
{
    event->mapFromScene(this);
    emit mtqTapCancel(event);
    processTapCancel(event);
}

void BaseWidget::tapUp(mtq::TapEvent *event)
{
    event->mapFromScene(this);
    emit mtqTapUp(event);
    processTapUp(event);
}

void BaseWidget::dwell(mtq::TapEvent *event)
{
    event->mapFromScene(this);
    emit mtqDwell(event);
    processDwell(event);
}

void BaseWidget::tap(mtq::TapEvent *event)
{
    event->mapFromScene(this);
    emit mtqTap(event);
    processTap(event);
}

void BaseWidget::doubleTap(mtq::TapEvent *event)
{
    event->mapFromScene(this);
    emit mtqDoubleTap(event);
    processDoubleTap(event);
}

// handle mouse events and generate appropriate contact and tap events
void BaseWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->modifiers() && Qt::ShiftModifier) {
        TapInfo *tapInfo = new TapInfo;
        TapEvent tapEvent(tapInfo, Event::Tap);

        tapInfo->center = this->mapToScene(event->pos());
        tapInfo->mappedCenter = QPointF(event->pos());
        tapInfo->user = "MOUSE";
        tapInfo->foot = event->button() == Qt::LeftButton ? "left" : "right";

        emit doubleTap(&tapEvent);
    }
}

void BaseWidget::mouseMoveEvent(QMouseEvent *event)
{
    ContactInfo *contactInfo = new ContactInfo;
    ContactEvent contactEvent(contactInfo, Event::ContactMove);

    contactInfo->center = mapToScene(event->pos());
    contactInfo->mappedCenter = QPointF(event->pos());
    contactInfo->user = "MOUSE";
    contactInfo->foot = event->button() == Qt::LeftButton ? "left" : "right";

    emit contactMove(&contactEvent);
}

void BaseWidget::mousePressEvent(QMouseEvent *event)
{
    ContactInfo *contactInfo = new ContactInfo;
    ContactEvent contactEvent(contactInfo, Event::ContactDown);

    contactInfo->center = mapToScene(event->pos());
    contactInfo->mappedCenter = QPointF(event->pos());
    contactInfo->user = "MOUSE";
    contactInfo->foot = event->button() == Qt::LeftButton ? "left" : "right";

    emit contactDown(&contactEvent);

    if (event->modifiers() && Qt::ShiftModifier) {
        TapInfo *tapInfo = new TapInfo;
        TapEvent tapEvent(tapInfo, Event::TapDown);

        tapInfo->center = mapToScene(event->pos());
        tapInfo->mappedCenter = QPointF(event->pos());
        tapInfo->user = "MOUSE";
        tapInfo->foot = event->button() == Qt::LeftButton ? "left" : "right";

        emit tapDown(&tapEvent);
    }
}

void BaseWidget::mouseReleaseEvent(QMouseEvent *event)
{
    ContactInfo *contactInfo = new ContactInfo;
    ContactEvent contactEvent(contactInfo, Event::ContactDown);

    contactInfo->center = mapToScene(event->pos());
    contactInfo->mappedCenter = QPointF(event->pos());
    contactInfo->user = "MOUSE";
    contactInfo->foot = event->button() == Qt::LeftButton ? "left" : "right";

    emit contactUp(&contactEvent);

    if (event->modifiers() && Qt::ShiftModifier) {
        TapInfo *tapInfo = new TapInfo;
        TapInfo *tapUpInfo = new TapInfo;
        TapEvent tapEvent(tapInfo, Event::Tap);
        TapEvent tapUpEvent(tapUpInfo, Event::TapUp);

        tapInfo->center = mapToScene(event->pos());
        tapInfo->mappedCenter = QPointF(event->pos());
        tapInfo->user = "MOUSE";
        tapInfo->foot = event->button() == Qt::LeftButton ? "left" : "right";
        tapUpInfo->center = mapToScene(event->pos());
        tapUpInfo->mappedCenter = QPointF(event->pos());
        tapUpInfo->user = "MOUSE";
        tapUpInfo->foot = event->button() == Qt::LeftButton ? "left" : "right";

        emit tap(&tapEvent);
        emit tapUp(&tapUpEvent);
    }
}

// basic event processing methods
void BaseWidget::processContactDown(mtq::ContactEvent *)
{
}

void BaseWidget::processContactMove(mtq::ContactEvent *)
{
}

void BaseWidget::processContactChanged(mtq::ContactEvent *)
{
}

void BaseWidget::processContactMerged(mtq::ContactEvent *)
{
}

void BaseWidget::processContactUp(mtq::ContactEvent *)
{
}

void BaseWidget::processTapDown(mtq::TapEvent *)
{
}

void BaseWidget::processTapCancel(mtq::TapEvent *)
{
}

void BaseWidget::processTapUp(mtq::TapEvent *)
{
}

void BaseWidget::processDwell(mtq::TapEvent *)
{
}

void BaseWidget::processTap(mtq::TapEvent *)
{
}

void BaseWidget::processDoubleTap(mtq::TapEvent *)
{
}
