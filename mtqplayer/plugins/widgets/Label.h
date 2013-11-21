#pragma once

#include "BaseWidget.h"

class Label: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
	MTQ_QML_PLUGIN_REGISTRATION(Label, "widgets")

	//QProperties: access attributes from QML.
	//Here we define the getters and setters to be used
	Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
	Label(QQuickItem *parent = 0);

	void paint(QPainter *painter);

	void setText(const QString &text);
	QString text() const;

signals:
	void textChanged(QString text);

private:
	QString m_text;
};
