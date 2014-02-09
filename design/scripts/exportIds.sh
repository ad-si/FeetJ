#! /bin/bash

ids=(
	initial-view
	select-mode
	add-lane
	select-filter
	select-song
	play-song
	add-second-song
	crossfade
	loop
	scratch
	add-effectpanel
	control-controlpad
	overview
)

for id in ${ids[@]}
do
	inkscape --export-id=$id --export-dpi=90 --export-png=png/$id.png svg/walkthrough.svg
done