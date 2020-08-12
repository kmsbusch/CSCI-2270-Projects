#include "Album.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

Album::Album()
{
	genre = "";
	name = "";
	year = 0;
}

Album::Album(string name, string genre, int year)
{
	
	this->name = name;
	this->genre = genre;
	this->year = year;
}

void Album::setName(string name)
{
	this->name = name;
}

string Album::getName()
{
	return name;
}

void Album::setGenre(string genreName)
{
	this->genre = genreName;
}

string Album::getGenre()
{
	return genre;
}

void Album::setYear(int year)
{
	this->year = year;
}

int Album::getYear()
{
	return year;
}

void Album::setList(Songlist* list)
{
	this->songlist = list;
}

Songlist* Album::getList()
{
	//Songlist song;
	return songlist;
}

void Album::addSong(Song* song)
{
	songlist->insertSong(song);
}

void Album::printSongs()
{
	Song* song = songlist->getHead();
	cout << name << "'s Songs: " << endl;
	cout << "-------------------------------------" << endl;

	for (int i = 0; i < songlist->getNumSongs(); i++)
	{
		cout << i + 1 << ". " << song->name << endl;
		song = song->next;
	}
	cout << "-------------------------------------" << endl;
}