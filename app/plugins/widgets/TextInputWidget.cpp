#include "TextInputWidget.h"

using namespace mtq;

//We need to register this Type in QML
MTQ_QML_REGISTER_PLUGIN(TextInputWidget)


//This is a text field with an attached Keyboard. Note that you can't actually get at the text yet.
TextInputWidget::TextInputWidget(QQuickItem *parent)
	: BaseWidget(parent)
{
	m_keyboard = new Keyboard(this);
	m_textField = new TextField(this, m_keyboard->width());

	m_keyboard->setX(0);
	m_keyboard->setY(130);
	m_keyboard->setParentItem(this);

	m_textField->setX(0);
	m_textField->setY(0);
	m_textField->setParentItem(this);

	connect(m_keyboard, SIGNAL(pressed(QString)), m_textField, SLOT(addCharacter(QString)));
}
