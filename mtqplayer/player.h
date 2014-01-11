#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "bass/bass.h"

#include <iostream>

class Player : public QObject
{
	Q_OBJECT

	public:
		Player();
		Q_INVOKABLE void playA();
		Q_INVOKABLE void playB();

	public slots:
		void testSlot();

	private:
		HSTREAM trackA;
		HSTREAM trackB;
};

#endif // PLAYER_H
