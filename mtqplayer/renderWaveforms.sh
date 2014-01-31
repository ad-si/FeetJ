#! /bin/bash

for song in songs/*.mp3
do
	echo "Generate waveform for ${song##*/}"
	waveform $song --width 2000 --color-center 464646ff --color-outer 464646ff ${song%.mp3}.png
done
