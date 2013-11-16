#include "BaseWidget.h"

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

// we forward the floor and mouse events for use in QML
void BaseWidget::contactDown(ContactEvent *event)
{
    emit qmlContactDown(event);
}

void BaseWidget::contactMove(ContactEvent *event)
{
    emit qmlContactMove(event);
}

void BaseWidget::contactChanged(ContactEvent *event)
{
    emit qmlContactChanged(event);
}

void BaseWidget::contactMerged(ContactEvent *event)
{
    emit qmlContactMerged(event);
}

void BaseWidget::contactUp(ContactEvent *event)
{
    emit qmlContactUp(event);
}

void BaseWidget::tapDown(TapEvent *event)
{
    emit qmlTapDown(event);
}

void BaseWidget::tapCancel(TapEvent *event)
{
    emit qmlTapCancel(event);
}

void BaseWidget::tapUp(TapEvent *event)
{
    emit qmlTapUp(event);
}

void BaseWidget::dwell(TapEvent *event)
{
    emit qmlDwell(event);
}

void BaseWidget::tap(TapEvent *event)
{
    emit qmlTap(event);
}

void BaseWidget::doubleTap(TapEvent *event)
{
    emit qmlDoubleTap(event);
}

void BaseWidget::mousePressEvent(QMouseEvent *event)
{
	emit qmlMousePress(event);
}

void BaseWidget::mouseReleaseEvent(QMouseEvent *event)
{
	emit qmlMouseRelease(event);
}
