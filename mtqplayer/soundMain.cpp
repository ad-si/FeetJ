#include "bass/bass.h"
#include <stdlib.h>
#include <stdio.h>


HSTREAM streamHandle; // Handle for open stream

void initSound()
{
	int device = -1; // Default Sounddevice
	int freq = 44100; // Sample rate (Hz)
	/* Initialize output device */
	BASS_Init(device, freq, 0, 0, NULL);
	/* Load your soundfile and play it */
	streamHandle = BASS_StreamCreateFile(FALSE, "/home/hci1/emailp.wav", 0, 0, 0);

	//BASS_ChannelSetFX(streamHandle,BASS_FX_DX8_ECHO,1);
}


void playTest()
{
	BASS_ChannelPlay(streamHandle, FALSE);
}
