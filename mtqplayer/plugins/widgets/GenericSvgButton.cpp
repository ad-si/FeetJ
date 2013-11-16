#include "GenericSvgButton.h"

#include <QPainter>

#include "Design.h"

using namespace mtq;

//We need to register this Type in QML
QML_REGISTER_PLUGIN(GenericSvgButton)

//This is a Button without caption, that shows an SVG element with a specified ID
GenericSvgButton::GenericSvgButton(QQuickItem *parent)
    : BaseWidget(parent),
      m_active(false),
	  m_svgElementId("GenericSvgButton::default"),
	  m_svgRenderer(new QSvgRenderer(design::widgetsSvgFile, this))
{
}

void GenericSvgButton::paint(QPainter *painter)
{
    m_svgRenderer->render(painter, m_svgElementId, QRect(0, 0, width(), height()));
}

bool GenericSvgButton::active()
{
	return m_active;
}

void GenericSvgButton::setActive(bool state)
{
	m_active = state;
	update();
}

QString GenericSvgButton::svgElementId()
{
	return m_svgElementId;
}

void GenericSvgButton::setSvgElementId(QString newId)
{
	m_svgElementId = newId;
}



void GenericSvgButton::mousePressEvent(QMouseEvent *event)
{
	BaseWidget::mousePressEvent(event);
	setActive(true);
	emit pressed();
}

void GenericSvgButton::mouseReleaseEvent(QMouseEvent *event)
{
	BaseWidget::mouseReleaseEvent(event);
	setActive(false);
}

void GenericSvgButton::tapDown(mtq::TapEvent *event)
{
	BaseWidget::tapDown(event);
	setActive(true);
	emit pressed();
}

void GenericSvgButton::tapUp(mtq::TapEvent *event)
{
	BaseWidget::tapUp(event);
	setActive(false);
}

void GenericSvgButton::tapCancel(mtq::TapEvent *event)
{
	BaseWidget::tapCancel(event);
	setActive(false);
}
