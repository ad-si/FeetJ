#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "bass/bass.h"
#include "songlist.h"

#include <iostream>

class Player : public QObject
{
	Q_OBJECT

	public:
		Player();
		Q_INVOKABLE void playA();
		Q_INVOKABLE void playB();
		void setTrackA(Song s);
		void setTrackB(Song s);

	public slots:
		void testSlot();

	private:
		HSTREAM trackA;
		HSTREAM trackB;
		SongList lib;
		void setTrack(HSTREAM *T, Song s);
};

#endif // PLAYER_H
