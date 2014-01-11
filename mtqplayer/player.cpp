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

	trackA = BASS_StreamCreateFile(FALSE, "/home/hci1/winter.wav", 0, 0, 0);
	Song s = lib.getTestSong();
	string s2 = lib.getFullPath(s);
	//trackB = BASS_StreamCreateFile(FALSE, (void*)(s2.c_str()), 0, 0, 0);
	//setTrack(1, lib.getTestSong());

}

void Player::playA()
{
	BASS_ChannelPlay(trackA, FALSE);
}

void Player::playB()
{
	BASS_ChannelPlay(trackB, FALSE);
}

HSTREAM* Player::getTrackByNo(int n)
{
	if (n==1)
		return &trackA;
	else if (n==2)
		return &trackB;
	else
		return NULL;
}



void Player::setTrack(int track, Song s)
{
	HSTREAM* T = getTrackByNo(track);
	string s2 = lib.getFullPath(s);
	*T = BASS_StreamCreateFile(FALSE, (void*)(s2.c_str()), 0, 0, 0);

}

void Player::testSlot()
{
	std::cout << "FRESH SLUUUUUUUUUT!";
	playA();
}

