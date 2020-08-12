#include "Song.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

Songlist::Songlist()
{
	head = NULL;
}

Song::Song()
{
	string name = "";
	//float rating = 0.0;
	int minutes = 0;
	int seconds = 0;
	Song* next = NULL;
}

Song::Song(string name, int minutes, int seconds, Song* next)
{
	this->name = name;
	//this->rating = rating;
	this->minutes = minutes;
	this->seconds = seconds;
	this->next = NULL;
}

void Song::printSongInfo()
{
	//Song* song = new Song();
	//cout << name << ": " << endl;
	cout << "-------------------------------------" << endl;
	cout << "Length - " << minutes << ":" << seconds << endl;
	//cout << "Rating - " << rating << endl;
	cout << "Next song on the album - " << next->name << endl;
	cout << "-------------------------------------" << endl;
}

Song* Songlist::findSong(string songName)
{
	Song* song = head;
	while (song->name != songName && song->next != NULL)
	{
		song = song->next;
	}
	return song;
}

void Songlist::insertSong(Song* node)
{
	this->numSongs++;
	//Song* idk = findSong(node->name);
	//Song* node = new Song();
	Song* temp = head; //this is always resetting to null, not sure why

	node->next = NULL;

	if (temp == NULL)
	{
		head = node;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = node;


	}
}

int Songlist::getNumSongs()
{
	return numSongs;
}

Song* Songlist::getHead()
{
	//Songlist song;
	return head;
}

void Song::setTime(int totalSeconds)
{
	this->minutes = totalSeconds / 60;
	this->seconds = totalSeconds % 60;
}