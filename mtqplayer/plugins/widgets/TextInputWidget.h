#pragma once

#include "BaseWidget.h"
#include "plugins/widgets/Keyboard.h"
#include "plugins/widgets/TextField.h"

class TextInputWidget: public BaseWidget
{
	//Tell the Qt-Preprocessor this is a QObject
	Q_OBJECT

	//Register widget as plugin for use in QML
	MTQ_QML_PLUGIN_REGISTRATION(TextInputWidget, "widgets")

private:
		Keyboard *m_keyboard;
		TextField *m_textField;
public:
	TextInputWidget(QQuickItem *parent = 0);

};
