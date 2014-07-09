#include "Keyboard.h"

#include <QVector>
#include <QSignalMapper>
#include <QStringList>

#define BUTTON_WIDTH 100
#define BUTTON_HEIGHT 100
#define BUTTON_X_INCREMENT 110
#define BUTTON_Y_INCREMENT 110

using namespace mtq;

//We need to register this Type in MTQ
MTQ_QML_REGISTER_PLUGIN(Keyboard)

Keyboard::Keyboard(QQuickItem *parent)
	: BaseWidget(parent)
{
	setHeight(550);
	setWidth(1210);

	QSignalMapper *signalMapper = new QSignalMapper(this);

	QStringList rows;
	rows << QString::fromUtf8("1234567890←")
		 << "qwertzuiop"
		 << QString::fromUtf8("asdfghjkl↵")
		 << "yxcvbnm,.-";

	int currentX = 0;
	int currentY = 0;
	int offsetX = 1;

	foreach (const QString & line, rows)
	{
		foreach (const QChar & key, line)
		{
			std::vector<PushButton*> new_vec;
			buttons.push_back(new_vec);
			PushButton *temp = new PushButton(this, key);
			buttons.at(0).push_back(temp);
			temp->setX(currentX);
			temp->setY(currentY);
			temp->setWidth(BUTTON_WIDTH);
			temp->setHeight(BUTTON_HEIGHT);
			temp->setParentItem(this);
			currentX += BUTTON_X_INCREMENT;

			connect(temp, SIGNAL(pressed()), signalMapper, SLOT(map()));
			signalMapper->setMapping(temp, QString(key));
		}
		currentX = 10+offsetX;
		currentY += BUTTON_Y_INCREMENT;
		offsetX +=20;
	}

	//Space-Button
	PushButton *space = new PushButton(this);
	space->setWidth(4*BUTTON_X_INCREMENT + BUTTON_WIDTH);
	space->setHeight(BUTTON_HEIGHT);
	space->setX((childrenRect().width()/2)-(space->width()/2));
	space->setY(currentY);
	space->setParentItem(this);
	connect(space, SIGNAL(pressed()), signalMapper, SLOT(map()));
	signalMapper->setMapping(space, " ");

	connect(signalMapper, SIGNAL(mapped(QString)), this, SLOT(keyPressed(QString)));
}


void Keyboard::keyPressed(QString text) {
	emit pressed(text);
}
