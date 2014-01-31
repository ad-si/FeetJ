#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "bass/bass.h"
#include "bass/bass_fx.h"
#include "songlist.h"

#include <iostream>

class Player : public QObject
{
	Q_OBJECT

	public:
		Player();
//		Q_INVOKABLE void playA();
//		Q_INVOKABLE void playB();
		void playTrack(int track);
		void setTrack(int track, Song s);
		void setTrackVolume(int track, float vol);
		void setCrossfade(float pos);
		void pauseTrack(int track);
		void toggleEffect(int track, int effectNumber);
		void stopEffect(int track);
		void modifyEffect(int track, float x, float y);
		void crossfade(int target, int source, float timeInMs);
		SongList lib;

	private:
		HSTREAM trackA;
		HSTREAM trackB;
		HFX effectA;
		int effectNoA;
		HFX effectB;
		int effectNoB;

		HPLUGIN bFX;

		HSTREAM* getTrackByNo(int n);
		HFX* getTrackEffectByNo(int track);
		int getTrackEffectNo(int track);

		bool isThisEffectCurrentlyActiveOnThisTrack(int track, int effectNo);
		void setTrackEffectNo(int track, int no);

		void effectFlanger(int track);
		void effectReverb(int track);
		void modifyFlanger(int track, int x, int y);
		void modifyReverb(int track, float x, float y);
		void effectEQ(int track);
		void modifyEQ(int track, float x, float y);
};

#endif // PLAYER_H
