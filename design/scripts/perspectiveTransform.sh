#! /bin/bash

convert png/overview.png \
	-matte -virtual-pixel transparent \
	-distort Perspective '0,0 1417,264  1417,0 570,862  0,866 870,104  1417,866 0,398' \
	-trim \
	png/overview-perspective.png
