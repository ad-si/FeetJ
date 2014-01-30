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

	BASS_SetConfig(BASS_CONFIG_CURVE_VOL, false);

}

/* ===================================================================================================
 * TRACK CONTROL
 * =================================================================================================== */


void Player::playTrack(int track)
{
	HSTREAM* T = getTrackByNo(track);
	BASS_ChannelPlay(*T, FALSE);

	qDebug() << "[" << track << "] Playing.";
}

void Player::pauseTrack(int track)
{
	HSTREAM* T = getTrackByNo(track);
	BASS_ChannelPause(*T);
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






/* ===================================================================================================
 * HILFSFUNKTIONEN
 * =================================================================================================== */

HSTREAM* Player::getTrackByNo(int n)
{
	if (n==1)
		return &trackA;
	else if (n==2)
		return &trackB;
	else
		return NULL;
}





/* ===================================================================================================
 * EFFEKTE -> Steuerung insgesamt
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

void Player::stopEffect(int track)
{
	HSTREAM* T = getTrackByNo(track);
	HFX* E = getTrackEffectByNo(track);

	if (!BASS_ChannelRemoveFX(*T, *E)) std::cout << "Stop Error!\n";

	setTrackEffectNo(track, 0);
}

void Player::toggleEffect(int track, int effectNumber)
{
	std::cout << *(getTrackEffectByNo(1));
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

void Player::modifyEffect(int track, int x, int y)
{

}

/* ===================================================================================================
 * EFFEKTE -> Implementierung einzelne Effekte
 * =================================================================================================== */



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

void Player::modifyFlanger(int track, int x, int y)
{

}

void Player::effectReverb(int track)
{
	HSTREAM* T = getTrackByNo(track);
	HFX* E = getTrackEffectByNo(track);
	*E = BASS_ChannelSetFX(*T,BASS_FX_DX8_REVERB,1);
}


