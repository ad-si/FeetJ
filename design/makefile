SHELL := /bin/bash


all: steps ids roto

steps:
	for i in {1..11};\
	do\
		inkscape --export-id=step$$i --export-dpi=10 --export-png=png/step$$i.png svg/walkthrough.svg;\
	done

ids:
	./scripts/exportIds.sh

roto:
	./scripts/exportRoto.sh