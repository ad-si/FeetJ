#include "TextInputWidget.h"

#include "plugins/widgets/Keyboard.h"
#include "plugins/widgets/TextField.h"

using namespace mtq;

//We need to register this Type in QML
QML_REGISTER_PLUGIN(TextInputWidget)


//This is a text field with an attached Keyboard
TextInputWidget::TextInputWidget(QQuickItem *parent)
    : BaseWidget(parent)
{
	Keyboard *keyboard = new Keyboard(this);
	TextField *textField = new TextField(this, keyboard->width());

	keyboard->setX(0);
	keyboard->setY(130);
	keyboard->setParentItem(this);

	textField->setX(0);
	textField->setY(0);
	textField->setParentItem(this);

	connect(keyboard, SIGNAL(pressed(QString)), textField, SLOT(addCharacter(QString)));
}
