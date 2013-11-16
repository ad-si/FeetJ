#pragma once

#include <QVector>

#include "BaseWidget.h"
#include "plugins/widgets/PushButton.h"

using namespace mtq;

class Keyboard: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
    QML_PLUGIN_REGISTRATION(Keyboard, "widgets")

public:
	Keyboard(QQuickItem *parent = 0);

private:
	std::vector<std::vector<PushButton* > > buttons;

public slots:
	void keyPressed(QString text);

signals:
	void pressed(QString text);

};
