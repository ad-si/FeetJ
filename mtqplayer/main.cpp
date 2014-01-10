#include "core/Application.h"
#include <stdlib.h>
#include <stdio.h>
#include "bass/bass.h"

int main(int argc, char **argv)
{
	mtq::Application app(argc, argv);
	printf("\nIch bin dumm!\n\n");

	int device = -1; // Default Sounddevice
	int freq = 44100; // Sample rate (Hz)
	HSTREAM streamHandle; // Handle for open stream


	/* Initialize output device */
	BASS_Init(device, freq, 0, 0, NULL);


	/* Load your soundfile and play it */
	streamHandle = BASS_StreamCreateFile(FALSE, "/home/hci1/emailp.wav", 0, 0, 0);
	BASS_ChannelPlay(streamHandle, FALSE);

	return app.exec();
}
