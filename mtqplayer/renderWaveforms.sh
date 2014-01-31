#! /bin/bash

for song in songs/*.mp3
do
	echo "Generate waveform for ${song##*/}"
	waveform $song --width 2000 --color-center c8c8c8ff --color-outer c8c8c8ff --scan ${song%.mp3}.png
	convert ${song%.mp3}.png -rotate 90 ${song%.mp3}.png
done
