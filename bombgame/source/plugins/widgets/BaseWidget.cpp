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
void BaseWidget::contactDown(mtq::ContactEvent *event)
{
	emit qmlContactDown(event);
}

void BaseWidget::contactMove(mtq::ContactEvent *event)
{
	emit qmlContactMove(event);
}

void BaseWidget::contactChanged(mtq::ContactEvent *event)
{
	emit qmlContactChanged(event);
}

void BaseWidget::contactMerged(mtq::ContactEvent *event)
{
	emit qmlContactMerged(event);
}

void BaseWidget::contactUp(mtq::ContactEvent *event)
{
	emit qmlContactUp(event);
}

void BaseWidget::tapDown(mtq::TapEvent *event)
{
	emit qmlTapDown(event);
}

void BaseWidget::tapCancel(mtq::TapEvent *event)
{
	emit qmlTapCancel(event);
}

void BaseWidget::tapUp(mtq::TapEvent *event)
{
	emit qmlTapUp(event);
}

void BaseWidget::dwell(mtq::TapEvent *event)
{
	emit qmlDwell(event);
}

void BaseWidget::tap(mtq::TapEvent *event)
{
	emit qmlTap(event);
}

void BaseWidget::doubleTap(mtq::TapEvent *event)
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
