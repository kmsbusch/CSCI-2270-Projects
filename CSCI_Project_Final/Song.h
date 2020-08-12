#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include<iostream>

using namespace std;

struct Song
{
	Song();
	void setTime(int);
	void printSongInfo();
	Song(string, int, int, Song*);
	string name = "";
	//double rating = 0.0;
	int minutes = 0;
	int seconds = 0;
	Song* next = NULL;
};

class Songlist
{
public:
	//void printSongsBefore();
	Songlist();
	Song* findSong(string);
	void insertSong(Song*);
	//void setHead();
	Song* getHead();
	int getNumSongs();

	
	
private:
	Song* head;
	int numSongs = 0;

};