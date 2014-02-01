#pragma once

#include <QSvgRenderer>
#include <QVector>

#include "BaseWidget.h"

class ListPicker: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
	MTQ_QML_PLUGIN_REGISTRATION(ListPicker, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used
	Q_PROPERTY(int selectedItem READ selectedItem WRITE setSelectedItem NOTIFY selectedItemChanged)
	Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
	Q_PROPERTY(QString caption READ caption WRITE setCaption NOTIFY captionChanged)

public:
	ListPicker(QQuickItem *parent = 0);

	void paint(QPainter *painter);

	void setSelectedItem(const int index);
	int selectedItem() const;

	QString caption() const;
	void setCaption(const QString &caption);

	QColor color() const;
	void setColor(const QColor color);

public slots:
	void addItem(const QString & itemText);

private:
	QVector<QString> m_items;
	QSvgRenderer *m_svgRenderer;
	int m_selectedItem;
	QString m_caption;
	QColor m_color;

protected:
    void processTapDown(mtq::TapEvent *event);

signals:
	void selectedItemChanged(int selectedItem);
	void captionChanged(QString caption);
	void colorChanged(QColor color);
};
