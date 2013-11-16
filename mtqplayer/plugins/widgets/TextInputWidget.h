#pragma once

#include "BaseWidget.h"

using namespace mtq;

class TextInputWidget: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
    QML_PLUGIN_REGISTRATION(TextInputWidget, "widgets")

public:
	TextInputWidget(QQuickItem *parent = 0);

};

