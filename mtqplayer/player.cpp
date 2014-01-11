#include "player.h"
#include "bass/bass.h"
#include <stdlib.h>
#include <iostream>
#include "songlist.h"

//HSTREAM Player::trackA;
//HSTREAM Player::trackB;




Player::Player()
{

	int device = -1; // Default Sounddevice
	int freq = 44100; // Sample rate (Hz)
	/* Initialize output device */
	BASS_Init(device, freq, 0, 0, NULL);

	trackA = BASS_StreamCreateFile(FALSE, "/home/hci1/emailp.wav", 0, 0, 0);
	Song s = lib.getTestSong();
	string s2 = lib.getFullPath(s);
	trackB = BASS_StreamCreateFile(FALSE, (void*)(s2.c_str()), 0, 0, 0);

}

void Player::playA()
{
	BASS_ChannelPlay(trackA, FALSE);
}

void Player::playB()
{
	BASS_ChannelPlay(trackB, FALSE);
}

void Player::setTrackA(Song s)
{
	setTrack(&trackA,s);
}

void Player::setTrackB(Song s)
{
	setTrack(&trackB,s);
}

void Player::setTrack(HSTREAM *T, Song s)
{
	string s2 = lib.getFullPath(s);
	*T = BASS_StreamCreateFile(FALSE, (void*)(s2.c_str()), 0, 0, 0);

}

void Player::testSlot()
{
	std::cout << "FRESH SLUUUUUUUUUT!";
	playA();
}

