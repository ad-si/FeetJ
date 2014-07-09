#pragma once

#include <QSvgRenderer>
#include <QVector>

#include "BaseWidget.h"

class RadioButton: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
	MTQ_QML_PLUGIN_REGISTRATION(RadioButton, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used
	Q_PROPERTY(int selectedItem READ selectedItem WRITE setSelectedItem NOTIFY selectedItemChanged)

public:
	RadioButton(QQuickItem *parent = 0);

	void paint(QPainter *painter);

	void setSelectedItem(const int index);
	int selectedItem() const;

public slots:
	void addItem(const QString & itemText);

private:
	QVector<QString> m_items;
	int m_selectedItem;
	QSvgRenderer *m_svgRenderer;

	void renderOneMenuItem(QPainter *painter, const int itemWidth);
	void renderMoreItems(QPainter *painter, const int itemWidth, const int itemCount);

protected:
    void processTapDown(mtq::TapEvent *event);

signals:
	void selectedItemChanged(int selectedItem);
};
