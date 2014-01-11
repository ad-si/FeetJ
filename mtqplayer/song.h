#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song
{
	public:
		Song(string title, string artist, string genre, string filename);
		string getTitle();
		string getArtist();
		string getGenre();
		string getFilename();


	private:
		string title;
		string artist;
		string filename;
		string genre;
};

#endif // SONG_H
