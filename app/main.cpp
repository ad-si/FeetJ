#include "core/Application.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <QtQml>
#include <QQmlEngine>

// wegen sleep
#include <unistd.h>

#include "player.h"
#include "soundMain.h"

using namespace std;

int main(int argc, char **argv)
{
	mtq::Application app(argc, argv);

	//Player p;

	/*
	int e;
	e = qmlRegisterType<Player>("fb.player", 1,0, "Player");
	cout << e;
	printf("ich bin eine wildblume!\n");
	*/



	/*
	p.playA();
	sleep(2);
	p.playB();
	p.playA();
	*/
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


	//QObject::connect(silence, SIGNAL(qmlSignal()),&p,SLOT(testSlot()));

	return app.exec();
}
