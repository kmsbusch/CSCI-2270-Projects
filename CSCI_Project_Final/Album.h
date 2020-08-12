#pragma once
#include "Song.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

class Album
{
public:
	Album();
	Album(string, string, int);
	void setName(string);
	string getName();

	void setGenre(string);
	string getGenre();

	void setYear(int);
	int getYear();

	void setList(Songlist*);
	Songlist* getList();

	void addSong(Song*);



	void printSongs();


	//void addVertex(string name);
	//void addGenre(string artistOne, string artistTwo);
	//void displayGenres();


private:
	string name;
	string genre;
	int year;
	Songlist* songlist;
};