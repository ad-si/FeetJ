#include "GenericButton.h"
#include <QPainter>
#include "Design.h"
#include <iostream>

using namespace mtq;

//We need to register this Type in MTQ
MTQ_QML_REGISTER_PLUGIN(GenericButton)

GenericButton::GenericButton(QQuickItem *parent)
	: BaseWidget(parent),
	  m_active(false),
	  m_svgRenderer(new QSvgRenderer(design::widgetsSvgFile, this))
{
	setHeight(160);
	setWidth(250);
	setColor("#ffaaaa");
}

GenericButton::GenericButton(QQuickItem *parent, const QString label)
	: BaseWidget(parent),
	  m_active(false),
	  m_svgRenderer(new QSvgRenderer(design::widgetsSvgFile, this))
{
	setHeight(160);
	setWidth(250);
	setColor("#ffaaaa");

	setText(label);
}

//This is the painting method. It paints the GenericButton using the QPainter painter
void GenericButton::paint(QPainter *painter)
{
	//int roundedCornerSize = 40;
	//if(height() < 80 || width() < 80)
	//	roundedCornerSize = 0;

	//painter->setRenderHint(QPainter::Antialiasing);
	//painter->setRenderHint(QPainter::HighQualityAntialiasing);
	//painter->setPen(Qt::black);

	QString elementId;
	if (active())
		elementId = "pressed";
	else
		elementId = "normal";

	// Render SVG
	/*
	m_svgRenderer->render(painter, "PushButton::"+elementId+"::topleft", QRect(0, 0, roundedCornerSize, roundedCornerSize));
	m_svgRenderer->render(painter, "PushButton::"+elementId+"::middle", QRect(roundedCornerSize, 0,
																			 width() - (2*roundedCornerSize), height()));
	m_svgRenderer->render(painter, "PushButton::"+elementId+"::bottomleft", QRect(0, height() - roundedCornerSize,
																				roundedCornerSize, roundedCornerSize));
	m_svgRenderer->render(painter, "PushButton::"+elementId+"::topright", QRect(width() - roundedCornerSize, 0,
																			   roundedCornerSize, roundedCornerSize));
	m_svgRenderer->render(painter, "PushButton::"+elementId+"::middle", QRect(0,roundedCornerSize,
																			width(), height() - (2*roundedCornerSize)));
	m_svgRenderer->render(painter, "PushButton::"+elementId+"::bottomright", QRect(width() - roundedCornerSize, height() - roundedCornerSize,
																			   roundedCornerSize, roundedCornerSize));

	*/

	//std::cout << width();

	// Render caption

	this->setFillColor(QColor(color()));

	QRectF rect(0, 0, width(), height());

	//painter->setBrush(QColor(color()));
	//painter->drawRect(rect);


	painter->setPen(design::labelFontColor);
	painter->setFont(design::labelFont);
	painter->drawText(rect, Qt::AlignCenter , m_text);
}

void GenericButton::processTapDown(mtq::TapEvent *event)
{
	setActive(true);
	emit pressed();
}

void GenericButton::processTapUp(mtq::TapEvent *event)
{
	setActive(false);
}

void GenericButton::processTapCancel(mtq::TapEvent *event)
{
	setActive(false);
}

QString GenericButton::text() const
{
	return m_text;
}

void GenericButton::setText(const QString text)
{
	m_text = text;
}

QColor GenericButton::color() const
{
	return m_color;
}

void GenericButton::setColor(const QColor color)
{
	m_color = color;
}

bool GenericButton::active() const
{
	return m_active;
}

void GenericButton::setActive(const bool state)
{
	m_active = state;
	update();
}
