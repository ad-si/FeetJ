#ifndef SONGLIST_H
#define SONGLIST_H

#include <iostream>
#include <list>
#include "song.h"

using namespace std;

class SongList
{
public:
	SongList();
	//Song getTestSong();
	string getFullPath(Song s);
	Song getSong(int title);

private:
	string basePath;
	list<Song> songs;
};

#endif // SONGLIST_H
