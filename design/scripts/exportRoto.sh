#! /bin/bash

set -e

cp svg/roto_floor.svg svg/roto_floor.tmp.svg

inkscape \
	--select emptyFloor \
	--verb EditDelete \
	--select bgImage \
	--verb EditDelete \
	--verb FileSave \
	--verb FileClose \
	svg/roto_floor.tmp.svg
	
inkscape \
	--export-png png/floor-overview.png \
	--export-dpi 200 \
	svg/roto_floor.tmp.svg
	
rm svg/roto_floor.tmp.svg