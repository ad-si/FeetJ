#include "ListPicker.h"

#include <QPainter>

#include "Design.h"

#define SEPARATOR_HEIGHT 8

using namespace mtq;

//We need to register this Type in MTQ
MTQ_QML_REGISTER_PLUGIN(ListPicker)

//ListPicker can be used to select an option in a List. Possibly as a menu
ListPicker::ListPicker(QQuickItem *parent)
	: BaseWidget(parent),
	  m_svgRenderer(new QSvgRenderer(design::widgetsSvgFile, this))
{
	m_items = QVector<QString>();
}

void ListPicker::paint(QPainter *painter)
{
	int itemCount = m_items.size();
	int itemHeight = (height() / (itemCount + 1)) - SEPARATOR_HEIGHT;

	//Drawing the caption
	painter->setPen(design::labelFontColor);
	painter->setFont(design::captionFont);
	painter->drawText(QRect(0, 0, width(), itemHeight),
					  Qt::AlignCenter,
					  m_caption);

	//Render menuItems
	if (itemCount > 0) {
		painter->setFont(design::labelFont);
		for (int i = 0; i < itemCount; i++) {
			if (m_selectedItem == i)
				m_svgRenderer->render(painter, "ListPicker::selectedItem",
									 QRect(0, (i+1) * itemHeight, width(), itemHeight));

			/* QSvgRenderer renders an SVG item with id "ListPicker::separator"
			 * from from mtqviewer\resources\svg\Widgets.svg
			 * into a rectangle refering to the coordinates of the parent widget */
			m_svgRenderer->render(painter, "ListPicker::separator",
								 QRect(0, (i+1) * itemHeight, width(), SEPARATOR_HEIGHT));

			painter->drawText(QRect(QRect(0, (i+1) * itemHeight + SEPARATOR_HEIGHT, width(), itemHeight)),
							  Qt::AlignCenter , m_items.at(i));
		}
	}
}

void ListPicker::addItem(const QString &itemText)
{
	m_items.push_back (itemText);
	// Everything that might cause a change in the appearance of the items
	// requires calling the paint method with update()
	update();
}

void ListPicker::setSelectedItem(const int index)
{
	m_selectedItem = index;
	emit selectedItemChanged(index);
}

int ListPicker::selectedItem() const
{
	return m_selectedItem;
}

QString ListPicker::caption() const
{
	return m_caption;
}

void ListPicker::setCaption(const QString &caption)
{
	m_caption = caption;
	update();
}

void ListPicker::processTapDown(mtq::TapEvent *event)
{
    int y = event->mappedCenter().y();
	if ( y / (height() / (m_items.size() +1 )) > 1 ) //prevents selecting the first line with caption
		setSelectedItem(y / (height() / (m_items.size() +1 )) - 1);
	update();
}
