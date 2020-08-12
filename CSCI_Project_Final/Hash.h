#pragma once
#include "Artist.h"
#include "Album.h"
#include "Song.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

struct node
{
	node()
	{
		key = "";
		next = NULL;
		artistNode = NULL;
	}
	string key;
	struct node* next;
	Artist* artistNode;
};

class HashTable
{
public:
	HashTable();  // Constructor (had int bsize in brackets)
	void loadDefaultSetup();
	int hashFunction(string key); // hash function to map values to key
	node* searchItem(string key);
	void insertItem(string, Artist*); // inserts a key into hash table
	void printTable();
	Artist* searchArtist(string);
	vector<string> readLine(string);
	Album* findAlbum(string);
	void findSong(string);
	//Album* searchAlbum(string);

private:
	//Artist* artist;
	node* createNode(string key, Artist* artist);
	const int tableSize = 26;  // No. of buckets (linked lists)
	node** table; // Pointer to an array containing buckets
};



