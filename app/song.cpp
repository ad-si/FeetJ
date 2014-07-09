#include "song.h"

Song::Song(string title, string artist, string genre, string filename)
{
	this->artist = artist;
	this->title = title;
	this->genre = genre;
	this->filename = filename;
}

string Song::getTitle()
{
	return this->title;
}

string Song::getArtist()
{
	return this->artist;
}

string Song::getGenre()
{
	return this->genre;
}

string Song::getFilename()
{
	return this->filename;
}
