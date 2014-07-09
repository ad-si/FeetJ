#include "GenericSvgButton.h"

#include <QPainter>

#include "Design.h"

using namespace mtq;

//We need to register this Type in MTQ
MTQ_QML_REGISTER_PLUGIN(GenericSvgButton)

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

bool GenericSvgButton::active() const
{
	return m_active;
}

void GenericSvgButton::setActive(const bool state)
{
	m_active = state;
	update();
}

QString GenericSvgButton::svgElementId() const
{
	return m_svgElementId;
}

void GenericSvgButton::setSvgElementId(const QString newId)
{
	m_svgElementId = newId;
}

void GenericSvgButton::processTapDown(mtq::TapEvent *event)
{
	setActive(true);
	emit pressed();
}

void GenericSvgButton::processTapUp(mtq::TapEvent *event)
{
	setActive(false);
}

void GenericSvgButton::processTapCancel(mtq::TapEvent *event)
{
	setActive(false);
}
