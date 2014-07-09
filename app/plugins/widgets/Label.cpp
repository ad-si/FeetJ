#include "Label.h"

#include <QPainter>

#include "Design.h"

using namespace mtq;

//We need to register this Type in MTQ
MTQ_QML_REGISTER_PLUGIN(Label)

Label::Label(QQuickItem *parent)
	: BaseWidget(parent)
{
	setHeight(168);
	m_text = "label";
}

void Label::paint(QPainter *painter)
{
	//Draw text
	painter->setPen(design::labelFontColor);
	painter->setFont(design::labelFont);
	QRect rect(0, 0, width(), height());
	painter->drawText(rect, Qt::AlignCenter , m_text);
}

void Label::setText(const QString &text)
{
	m_text = text;
	update();
}

QString Label::text() const
{
	return m_text;
}
