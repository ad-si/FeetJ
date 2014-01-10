#include "player.h"
#include "bass/bass.h"
#include <stdlib.h>

//HSTREAM Player::trackA;
//HSTREAM Player::trackB;


Player::Player()
{

	int device = -1; // Default Sounddevice
	int freq = 44100; // Sample rate (Hz)
	/* Initialize output device */
	BASS_Init(device, freq, 0, 0, NULL);

	trackA = BASS_StreamCreateFile(FALSE, "/home/hci1/emailp.wav", 0, 0, 0);
	trackB = BASS_StreamCreateFile(FALSE, "/home/hci1/adios.wav", 0, 0, 0);

}

void Player::playA()
{
	BASS_ChannelPlay(trackA, FALSE);
}

void Player::playB()
{
	BASS_ChannelPlay(trackB, FALSE);
}
