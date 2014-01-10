#ifndef PLAYER_H
#define PLAYER_H

#include "bass/bass.h"

class Player
{
	public:
		Player();
		void playA();
		void playB();


	private:
		HSTREAM trackA;
		HSTREAM trackB;
};

#endif // PLAYER_H
