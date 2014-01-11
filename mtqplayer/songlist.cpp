#include "songlist.h"

SongList::SongList()
{
	// hardcoding magic

	basePath = "/home/hci1/dis13_group8/mtqplayer/songs/";

}

Song SongList::getSong(int title) {

	Song beach("Surfin' USA", "Beach Boys", "lustigkeit", "surfin.mp3");
	Song parov("Cat Groove", "Parov Stelar", "Elektro Swing", "catgroove.mp3");
	Song chubby("Let's Twist Again", "Chubby Checker", "Twist", "letstwistagain.mp3");

	if (title == 0) {
		return beach;
	} else if (title == 1) {
		return parov;
	} else if (title == 2) {
		return chubby;
	} else {
		return chubby;
	}
}


	/*Song nirv("Come as you are", "Nirvana", "Grungy Grunge", "nirvana.ogg");
	Song beach("Surfin USA" , "Beach Boys", "Surfer Mucke", "surfin.mp3");
	Song nirv("Come as you are", "Nirvana", "Grungy Grunge", "nirvana.ogg");
	Song acdc("Back in Black", "ACDC", "Hard Rock", "acdc.ogg");

	songs.push_back(beach);
	songs.push_back(nirv);
	songs.push_back(acdc);
}

Song SongList::getTestSong()
{
	return songs.front();
}
*/

Song SongList::getAnotherTestSong()
{
	return songs.back();
}

string SongList::getFullPath(Song s)
{
	return basePath + s.getFilename();
}

