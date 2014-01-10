#include "core/Application.h"
#include <stdlib.h>
#include <stdio.h>

// wegen sleep
#include <unistd.h>


#include "soundMain.h"

int main(int argc, char **argv)
{
	mtq::Application app(argc, argv);
	printf("\nIch bin dumm!\n\n");

	initSound();
	playTest();
	sleep(1);
	playTest();
	sleep(3);
	playTest();
	sleep(5);
	playTest();

	return app.exec();
}
