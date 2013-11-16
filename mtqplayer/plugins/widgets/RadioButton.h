#pragma once

#include <QSvgRenderer>
#include <QVector>

#include "BaseWidget.h"

using namespace mtq;

class RadioButton: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
    QML_PLUGIN_REGISTRATION(RadioButton, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used
	Q_PROPERTY(int selectedItem READ selectedItem WRITE setSelectedItem NOTIFY selectedItemChanged)

public:
	RadioButton(QQuickItem *parent = 0);

	void paint(QPainter *painter);

	void setSelectedItem(int index);
	int selectedItem() {return m_selectedItem;}

public slots:
	void addItem(const QString & itemText);

private:
	QVector<QString> m_items;
	int m_selectedItem;
    QSvgRenderer *m_svgRenderer;

	void renderOneMenuItem(QPainter *painter, int itemWidth);
	void renderMoreItems(QPainter *painter, int itemWidth, int itemCount);

protected:
	void mousePressEvent(QMouseEvent *event);
	void tapDown(TapEvent *event);

signals:
	void selectedItemChanged(int selectedItem);
};
