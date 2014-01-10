#include "core/Application.h"
#include <stdlib.h>
#include <stdio.h>

// wegen sleep
#include <unistd.h>

#include "player.h"
#include "soundMain.h"

int main(int argc, char **argv)
{
	mtq::Application app(argc, argv);
	printf("\nIch bin dumm!\n\n");

	Player p;


	p.playA();
	sleep(2);
	p.playB();
	p.playA();

	/*
	initSound();
	playA();
	playB();
	sleep(1);
	playA();
	sleep(1);
	playB();
	sleep(5);
	playA();*/

	return app.exec();
}
