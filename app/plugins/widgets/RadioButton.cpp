#include "RadioButton.h"

#include <QPainter>

#include "Design.h"

#define SEPARATOR_WIDTH 2
#define ROUNDED_CORNER_WIDTH 44

using namespace mtq;

//We need to register this Type in MTQ
MTQ_QML_REGISTER_PLUGIN(RadioButton)

//Constructor
RadioButton::RadioButton(QQuickItem *parent)
	: BaseWidget(parent),
	  m_svgRenderer(new QSvgRenderer(design::widgetsSvgFile, this))
{
	setHeight(168);
	m_items = QVector<QString>();
}

void RadioButton::paint(QPainter *painter)
{
	int itemCount = m_items.size();
	int itemWidth = (width() / itemCount) - 2;

	painter->setPen(design::labelFontColor);
	painter->setFont(design::labelFont);

	if(itemCount > 1) {
		renderMoreItems(painter, itemWidth, itemCount);
	}
	else if (itemCount > 0) {
		renderOneMenuItem(painter, itemWidth);
	}
}

// paints the radiobutton if there are more than one item
void RadioButton::renderMoreItems(QPainter *painter, const int itemWidth, const int itemCount)
{
	QString selectedID = "";
	if(m_selectedItem == 0) {
		selectedID = "selected::";
	}

	// Render leftMostItem
	m_svgRenderer->render(painter, "RadioButton::" + selectedID + "frame::left", QRect(0, 0, ROUNDED_CORNER_WIDTH, height()));
	m_svgRenderer->render(painter, "RadioButton::" + selectedID + "frame",	   QRect(ROUNDED_CORNER_WIDTH, 0, itemWidth - ROUNDED_CORNER_WIDTH, height()));
	m_svgRenderer->render(painter, "RadioButton::separator",					 QRect(itemWidth, 0, SEPARATOR_WIDTH, height()));

	painter->drawText(QRect(0, 0, itemWidth, height()),
					  Qt::AlignCenter , m_items.at(0));

	// Render items in middle
	for(int i=1; i< itemCount -1; i++) {

		if(m_selectedItem == i)
			selectedID = "selected::";
		else
			selectedID = "";

		m_svgRenderer->render(painter, "RadioButton::" + selectedID + "frame",   QRect(i*(itemWidth + SEPARATOR_WIDTH), 0, itemWidth, height()));
		m_svgRenderer->render(painter, "RadioButton::separator",				 QRect((i+1)*(itemWidth + SEPARATOR_WIDTH) - SEPARATOR_WIDTH, 0, SEPARATOR_WIDTH, height()));

		QRect rect(i*(itemWidth + SEPARATOR_WIDTH), 0, itemWidth, height());
		painter->drawText(rect, Qt::AlignCenter , m_items.at(i));
	}

	// Render rightMostItem
	if(m_selectedItem == m_items.size()-1)
		selectedID = "selected::";
	else
		selectedID = "";

	m_svgRenderer->render(painter, "RadioButton::" + selectedID + "frame",	   QRect(width() - itemWidth - SEPARATOR_WIDTH, 0, itemWidth - ROUNDED_CORNER_WIDTH, height()));
	m_svgRenderer->render(painter, "RadioButton::" + selectedID + "frame::right",QRect(width() - ROUNDED_CORNER_WIDTH - SEPARATOR_WIDTH, 0, ROUNDED_CORNER_WIDTH, height()));

	QRect rect(width() - itemWidth - SEPARATOR_WIDTH, 0, itemWidth, height());
	painter->drawText(rect, Qt::AlignCenter , m_items.at(m_items.size()-1));

}

/* paints the radiobutton if there is only one item.
 * you think radiobuttons with only one option are somewhat pointless?
 * yes, I agree :-) */
void RadioButton::renderOneMenuItem(QPainter *painter, const int itemWidth)
{
	QString selectedID = "";
	if(m_selectedItem == 0)
			selectedID = "selected::";
		else
			selectedID = "";

		m_svgRenderer->render(painter, "RadioButton::" + selectedID + "frame::left",   QRect(0, 0, ROUNDED_CORNER_WIDTH, height()));
		m_svgRenderer->render(painter, "RadioButton::" + selectedID + "frame",		 QRect(ROUNDED_CORNER_WIDTH, 0, width() - ROUNDED_CORNER_WIDTH, height()));
		m_svgRenderer->render(painter, "RadioButton::" + selectedID + "frame::right",  QRect(width() - ROUNDED_CORNER_WIDTH, 0, ROUNDED_CORNER_WIDTH, height()));

		QRectF rect = QRect(0, 0, itemWidth, height());
		painter->drawText(rect, Qt::AlignCenter , m_items.at(0));
}

void RadioButton::addItem(const QString &itemText)
{
	m_items.push_back(itemText);
	update();
}

void RadioButton::processTapDown(mtq::TapEvent *event)
{
    int x = event->mappedCenter().x();
	setSelectedItem(x / (width() / m_items.size() ));
	update();
}

void RadioButton::setSelectedItem(const int index)
{
	m_selectedItem = index;
	emit selectedItemChanged(index);
}

int RadioButton::selectedItem() const
{
	return m_selectedItem;
}
