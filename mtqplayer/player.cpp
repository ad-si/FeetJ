#include "player.h"
#include "bass/bass.h"
#include <stdlib.h>
#include <iostream>
#include "songlist.h"
#include <QDebug>

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

	// lineare lautstaerke kurve
	BASS_SetConfig(BASS_CONFIG_CURVE_VOL, false);

}

//void Player::playA()
//{
//	BASS_ChannelPlay(trackA, FALSE);
//	qDebug() << "[A] Playing";

//}

//void Player::playB()
//{
//	BASS_ChannelPlay(trackB, FALSE);
//	qDebug() << "[B] Playing";
//}

void Player::playTrack(int track)
{
	HSTREAM* T = getTrackByNo(track);
	BASS_ChannelPlay(*T, FALSE);

	qDebug() << "[" << track << "] Playing.";
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

void Player::setTrackVolume(int track, float vol)
{
	HSTREAM* T = getTrackByNo(track);
	BASS_ChannelSetAttribute(*T, BASS_ATTRIB_VOL, vol);
	qDebug() << "[" << track << "] Set Volume to " << vol;

}

void Player::pauseTrack(int track)
{
	HSTREAM* T = getTrackByNo(track);
	BASS_ChannelPause(*T);
}

void Player::effectFlanger(int track)
{
	HSTREAM* T = getTrackByNo(track);
	BASS_ChannelSetFX(*T,BASS_FX_DX8_FLANGER,1);
}

void Player::effectReverb(int track)
{
	HSTREAM* T = getTrackByNo(track);
	BASS_ChannelSetFX(*T,BASS_FX_DX8_REVERB,1);
}

void Player::setTrack(int track, Song s)
{
	HSTREAM* T = getTrackByNo(track);
	string s2 = lib.getFullPath(s);
	*T = BASS_StreamCreateFile(FALSE, (void*)(s2.c_str()), 0, 0, 0);
	qDebug() << "[" << track << "] Loaded Song ";
}

void Player::setCrossfade(float pos)
{
	// 0 = A hat volle Lautstaerke;
	// 1 = B hat volle Lautstaerke

	setTrackVolume(1, 1-pos);
	setTrackVolume(2,pos);

}
