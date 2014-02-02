#! /bin/bash

ids=(
	looping
	crossfading
	overview
	overviewEffectPad
)

for id in ${ids[@]}
do
	inkscape --export-id=$id --export-dpi=10 --export-png=png/$id.png svg/walkthrough.svg
done