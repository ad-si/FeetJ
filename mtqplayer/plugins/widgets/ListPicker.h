#pragma once

#include <QSvgRenderer>
#include <QVector>

#include "BaseWidget.h"

using namespace mtq;

class ListPicker: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
    QML_PLUGIN_REGISTRATION(ListPicker, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used
	Q_PROPERTY(int selectedItem READ selectedItem WRITE setSelectedItem NOTIFY selectedItemChanged)
	Q_PROPERTY(QString caption READ caption WRITE setCaption)

public:
	ListPicker(QQuickItem *parent = 0);

	void paint(QPainter *painter);

	void setSelectedItem(int index);
	int selectedItem() {return m_selectedItem;}
	QString caption() {return m_caption;}
	void setCaption(const QString &caption);

public slots:
	void addItem(const QString & itemText);

private:
	QVector<QString> m_items;
    QSvgRenderer *m_svgRenderer;
	int m_selectedItem;
	QString m_caption;

protected:
	void mousePressEvent(QMouseEvent *event);
	void tapDown(TapEvent *event);

signals:
	void selectedItemChanged(int selectedItem);
};
