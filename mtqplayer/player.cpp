#include "player.h"
#include "bass/bass.h"
#include <stdlib.h>
#include <iostream>
#include "songlist.h"
#include <QDebug>
#include <typeinfo>

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

void Player::setTrackVolume(int track, float vol)
{
		HSTREAM* T = getTrackByNo(track);
		BASS_ChannelSetAttribute(*T, BASS_ATTRIB_VOL, vol);
		//qDebug() << "[" << track << "] Set Volume to " << vol;

}

void Player::setCrossfade(float pos)
{
	// 0 = A hat volle Lautstaerke;
	// 1 = B hat volle Lautstaerke

	setTrackVolume(1, 1-pos);
	setTrackVolume(2,pos);

}


void Player::crossfade(int target, int source, float timeInMs){
	//Was wird Bam Margera als nächstes tun?
	HSTREAM* TON = getTrackByNo(target);
	HSTREAM* TOFF = getTrackByNo(source);
	/*HSTREAM* T = getTrackByNo(track);
	BASS_ChannelSetAttribute(*T, BASS_ATTRIB_VOL, vol);*/

	BASS_ChannelSlideAttribute(*TON, BASS_ATTRIB_VOL, 1, timeInMs);
	BASS_ChannelSlideAttribute(*TOFF, BASS_ATTRIB_VOL, 0, timeInMs);
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

int Player::getTrackEffectNo(int track)
{
	if (track == 1) return effectNoA;
	if (track == 2) return effectNoB;
	return 0;
}

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
			case 1: effectFlanger(track); break; // BREAK BREAK BREAK AHAAAAAAAAAAAAAAAAAAH TOD UND HASSSSSSSSSS
			case 2: effectReverb(track); break;
			case 3: effectEQ(track); break;
		}
		setTrackEffectNo(track, effectNumber);

	}
}

void Player::modifyEffect(int track, float x, float y)
{
	//redundant? track == ENo?
	int ENo = getTrackEffectNo(track);
	switch(ENo)
	{
		case 1: modifyFlanger(track, x, y); break;
		case 2: modifyReverb(track, x, y); break;
		case 3: modifyEQ(track, x, y); break;
	}
}

/* ===================================================================================================
 * EFFEKTE -> Implementierung einzelne Effekte
 * =================================================================================================== */



void Player::effectFlanger(int track)
{
	HSTREAM* T = getTrackByNo(track);
	HFX* E = getTrackEffectByNo(track);

	*E = BASS_ChannelSetFX(*T,BASS_FX_DX8_FLANGER,1);
	cout << "let's see..." << *E << "\n";
	// default parameters for flanger
	modifyFlanger(track, 50, 50);
	//std::cout << effectA << "effect: gerade modify aufgerufen\n";
}

void Player::modifyFlanger(int track, int x, int y)
{
	//HSTREAM* T = getTrackByNo(track);
	cout << "Modify Effect: " << effectA << "\n";
	HFX* E = getTrackEffectByNo(track);
	cout << "E: " << *E << "\n";

	// 0 to 100
	float fWetDryMix = x; // that's pretty wet (

	// 0 to 100
	float fDepth = 100; // that's pretty deep (default 100)
	float fFeedback = y-20;
	float fFrequency = 1; // that's pretty frequent
	DWORD lWaveform = 1;
	float fDelay = 2;
	DWORD lPhase = BASS_DX8_PHASE_ZERO;

	BASS_DX8_FLANGER flangerParams = {fWetDryMix, fDepth, fFeedback, fFrequency, lWaveform, fDelay, lPhase};
	BASS_FXSetParameters(*E, &flangerParams);

	cout << ":::" << track << " -> Modified Flanger to " << x << " / " << y <<  " :: " << BASS_ErrorGetCode() << "\n";
}

void Player::effectReverb(int track)
{
	HSTREAM* T = getTrackByNo(track);
	HFX* E = getTrackEffectByNo(track);
	*E = BASS_ChannelSetFX(*T,BASS_FX_DX8_REVERB,1);
}


void Player::modifyReverb(int track, float x, float y)
{
	HFX* E = getTrackEffectByNo(track);
	float fInGain = 0; // dB
	float fReverbMix = (x-100)*0.96/100; // -96 bis 0 dB
	float fReverbTime = y*30; // 0.001 to 3000 ms
	float fHighFreqRTRatio = 0.001; //ms
	BASS_DX8_REVERB revParams = {fInGain, fReverbMix, fReverbTime, fHighFreqRTRatio};


	BASS_FXSetParameters(*E, &revParams);

	cout << "Modify Reverb: " << BASS_ErrorGetCode() << "\n";
}

void Player::effectEQ(int track)
{
	HSTREAM* T = getTrackByNo(track);
	HFX* E = getTrackEffectByNo(track);

	*E = BASS_ChannelSetFX(*T,BASS_FX_DX8_PARAMEQ,1);
	cout << "EQ activated! " << BASS_ErrorGetCode() << "\n";
}

void Player::modifyEQ(int track, float x, float y)
{
	HFX* E = getTrackEffectByNo(track);

	float fCenter = 160*x; // 80 - 16000
	float fBandwith = 16; // semitones
	float fGain = y*0.3 - 15; // -15 to 15

	BASS_DX8_PARAMEQ EQParams = {fCenter, fBandwith, fGain};

	BASS_FXSetParameters(*E, &EQParams);

	cout << "Modify EQ: " << BASS_ErrorGetCode() << "\n";
}




