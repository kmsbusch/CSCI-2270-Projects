#pragma once
#include "Album.h"
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;



class Artist
{
public:
	Artist();
	Artist(string);
	void setName(string);
	string getName();

	//void setGenre(string);
	//string getGenre();

	void addAlbum(Album*);
	//bool albumExists(string);
	Album* getAlbum(string);

	void addSong(string, Song*);
	Song* searchSong(string);
	Album* albumBySong(string);
	

	void printAlbums();


	//void addVertex(string name);
	//void addGenre(string artistOne, string artistTwo);
	//void displayGenres();


private:
	string name;
	//string genre;
	vector<Album*> albums;


};
