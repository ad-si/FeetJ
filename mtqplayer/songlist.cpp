#include "songlist.h"

SongList::SongList()
{
	// hardcoding magic

	basePath = "/home/hci1/dis13_group8/mtqplayer/songs/";

	Song nirv("Come as you are", "Nirvana", "Grungy Grunge", "nirvana.ogg");
	Song acdc("Back in Black", "ACDC", "Hard Rock", "acdc.ogg");

	songs.push_back(nirv);
	songs.push_back(acdc);
}

Song SongList::getTestSong()
{
	return songs.front();
}

string SongList::getFullPath(Song s)
{
	return basePath + s.getFilename();
}
