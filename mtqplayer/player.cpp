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
	Song s = lib.getSong(0);
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

/* ===================================================================================================
 * EFFEKTE
 * =================================================================================================== */

HFX* Player::getTrackEffectByNo(int track)
{
	if (track == 1) return &effectA;
	if (track == 2) return &effectB;
	return NULL;
}

bool Player::isThisEffectCurrentlyActiveOnThisTrack(int track, int effectNo)
{
	if (track == 1) return (effectNoA == effectNo);
	if (track == 2) return (effectNoB == effectNo);
	return 0;
}

void Player::setTrackEffectNo(int track, int no)
{
	if (track == 1) (effectNoA = no);
	if (track == 2) (effectNoB = no);
}

void Player::toggleEffect(int track, int effectNumber)
{
	std::cout << "[" << track << "] Toggling Effect " << effectNumber;
	std::cout << " (Current Effect: " << effectNoA << effectNoB << ")\n";
	if (isThisEffectCurrentlyActiveOnThisTrack(track, effectNumber))
	{

		stopEffect(track);
		std::cout << BASS_ErrorGetCode() << "stopping effect.\n";
	}
	else
	{
		switch(effectNumber)
		{
			case 1: effectFlanger(track);
			case 2: effectReverb(track);
		}
		setTrackEffectNo(track, effectNumber);

	}
}

void Player::stopEffect(int track)
{
	HSTREAM* T = getTrackByNo(track);
	HFX* E = getTrackEffectByNo(track);

	//BASS_ChannelRemoveFX(*E, *T);
	BASS_ChannelRemoveFX(trackA, effectA); // #hardcode
}

void Player::effectFlanger(int track)
{
	HSTREAM* T = getTrackByNo(track);
	HFX* E = getTrackEffectByNo(track);

	*E = BASS_ChannelSetFX(*T,BASS_FX_DX8_FLANGER,1);

	float fWetDryMix = 80; // that's pretty wet
	float fDepth = 100; // that's pretty deep (default -50)
	float fFeedback = 50;
	float fFrequency = 1; // that's pretty frequent
	DWORD lWaveform = 1;
	float fDelay = 2;
	DWORD lPhase = BASS_DX8_PHASE_ZERO;

	BASS_DX8_FLANGER flangerParams = {fWetDryMix, fDepth, fFeedback, fFrequency, lWaveform, fDelay, lPhase};

	BASS_FXSetParameters(*E, &flangerParams);
}

void Player::effectReverb(int track)
{
	HSTREAM* T = getTrackByNo(track);
	HFX* E = getTrackEffectByNo(track);
	*E = BASS_ChannelSetFX(*T,BASS_FX_DX8_REVERB,1);
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
