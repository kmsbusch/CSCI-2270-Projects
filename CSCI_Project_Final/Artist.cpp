#include "Artist.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

Artist::Artist()
{
	//Artist artist;
	name = "";
	//genre = "";
	for (int i = 0; i < albums.size(); i++)
	{
		albums[i] = new Album();
	}

}

Artist::Artist(string name)
{
	
	this->name = name;
//	this->genre = genre;

}

void Artist::setName(string name)
{
	
	this->name = name;
}

string Artist::getName()
{
	
	return name;
}

/*
void Artist::setGenre(string genre)
{
	
	this->genre = genre;
}

string Artist::getGenre()
{
	
	return genre;
}
*/


void Artist::addAlbum(Album* album)
{
	for (unsigned int i = 0; i < albums.size(); i++)
	{
		if (name == albums[i]->getName())
		{
			return;
		}
	}
	albums.push_back(album);
}

Album* Artist::getAlbum(string albumName)
{
	for (unsigned int i = 0; i < albums.size(); i++)
	{
		if (albums[i]->getName() == albumName)
		{
			return albums[i];
		}
	}
	return NULL;
}

void Artist::addSong(string albumName, Song* song)
{
	Album* album = getAlbum(albumName);
	album->addSong(song);
}

Song* Artist::searchSong(string songName)
{
	for (unsigned int i = 0; i < albums.size(); i++)
	{
		Songlist* songlist = albums[i]->getList();
		Song* song = songlist->findSong(songName);
		if (song->name != songName)
		{
			while (song->next != NULL)
			{
				song = song->next;
			}
		}
		else
		{
			return song;
		}
	}
}

Album* Artist::albumBySong(string songName)
{
	for (unsigned int i = 0; i < albums.size(); i++)
	{
		Songlist* songlist = albums[i]->getList();
		Song* song = songlist->findSong(songName);
		if (song->name != songName)
		{
			while (song->next != NULL)
			{
				song = song->next;
			}
		}
		else
		{
			return albums[i];
		}
	}
	return NULL;
}


void Artist::printAlbums()
{
	cout << name << "'s Albums: " << endl;
	cout << "-------------------------------------" << endl;
	for (unsigned int i = 0; i < albums.size(); i++)
	{
		cout << i + 1 << ". " << albums[i]->getName() << endl;
	}
	cout << "-------------------------------------" << endl;
}