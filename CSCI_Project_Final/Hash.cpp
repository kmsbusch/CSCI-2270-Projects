#include "Hash.h"
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

vector<string> HashTable::readLine(string lineIn)
{
	vector<string> lineInformation;
	string artistName = "";
	string albumName = "";
	string albumYear = "";
	string songName = "";
	string songTime = "";

	stringstream ss(lineIn);

	
	getline(ss, artistName, ',');
	lineInformation.push_back(artistName);
	getline(ss, albumName, ',');
	lineInformation.push_back(albumName);
	getline(ss, songName, ',');
	lineInformation.push_back(songName);
	getline(ss, albumYear, ',');
	lineInformation.push_back(albumYear);
	getline(ss, songTime, ',');
	lineInformation.push_back(songTime);
	
	return lineInformation;
}

node* HashTable::createNode(string key, Artist* artist)
{
	node* nw = new node;
	nw->key = key;
	nw->next = NULL;
	nw->artistNode = artist;
	return nw;
}

HashTable::HashTable() // had int bsize in parentheses
{
	//this->tableSize = bsize;
	table = new node * [tableSize];
	for (int i = 0; i < tableSize; i++)
		table[i] = nullptr;
}


void HashTable::loadDefaultSetup()
{

	string line = "";
	ifstream fs;
	fs.open("Data.csv");

	Album* album = new Album();
	Songlist* songlist = new Songlist(); //maybe move outside
	while (getline(fs, line))
	{
		vector<string> currentLine = readLine(line);

		Artist* artist = searchArtist(currentLine[0]); //look for artist in hashtable
		
		if (artist == NULL)
		{
			album = new Album();       
			Songlist* songlist = new Songlist(); //maybe move outside
			artist = new Artist();
			artist->setName(currentLine[0]);

			Song* song = new Song(); //every line is a new song, so this happens every line
			int totalTime = stoi(currentLine[4]);
			song->setTime(totalTime);
			song->name = currentLine[3];

			album->setName(currentLine[1]);
			int yearNum = stoi(currentLine[2]);
			album->setYear(yearNum);

			album->setList(songlist);
			artist->addAlbum(album);
			artist->addSong(album->getName(), song);

			this->insertItem(currentLine[0], artist);
		}
		else
		{
			Song* song = new Song(); //every line is a new song, so this happens every line
			if (artist->getAlbum(currentLine[1]) == NULL)
			{
			
				album = new Album();
				songlist = new Songlist();
				int totalTime = stoi(currentLine[4]);
				song->setTime(totalTime);
				song->name = currentLine[3];

				album->setList(songlist);
				album->setName(currentLine[1]);
				int yearNum = stoi(currentLine[2]);
				album->setYear(yearNum);
				artist->addAlbum(album);
				artist->addSong(album->getName(), song); //func takes album string name and song* object
			

			}
			else
			{
				int totalTime = stoi(currentLine[4]);
				song->setTime(totalTime);
				song->name = currentLine[3];
				artist->addSong(album->getName(), song); //func takes album string name and song* object
			}
		}

	}
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//function to calculate hash function
int HashTable::hashFunction(string key)
{
	int keyValue = 0;
	for (unsigned int i = 0; i < key.size(); i++)
	{
		keyValue += char(key[i]);
	}
	return (keyValue % tableSize);
}

//function to search
node* HashTable::searchItem(string key)
{
	//Compute the index by using the hash function
	int index = hashFunction(key);
	node* temp = table[index];
	if (temp == NULL)
	{
		return NULL;
	}
	else
	{
		while (temp->next != NULL)
		{
			if (temp->key == key)
			{
				return temp;
			}
			else
			{
				temp = temp->next;
			}
		}
		return NULL;
	}
}

Artist* HashTable::searchArtist(string artistName)
{
	int index = hashFunction(artistName);
	node* temp = table[index];
	if (temp == NULL)
	{
		return NULL;
	}
	else
	{
		for (int i = 0; i < tableSize; i++)
		{

			if (temp->artistNode->getName() == artistName)
			{
				return temp->artistNode;
			}
			else if (temp->next != NULL)
			{
				temp = temp->next;
			}
		}
		temp->artistNode = NULL;
		return temp->artistNode;
	}
}

//function to insert
void HashTable::insertItem(string key, Artist* artist)   // ask dad, i think this is just creating LL of the same artist to itself currently. need to change implementation in setup
{
	node* search = searchItem(key);
	if (search == NULL)
	{
		int index = hashFunction(key);
		node* nw = createNode(key, artist);
		if (table[index] == NULL)
		{
			table[index] = nw;
		}
		else
		{
			nw->next = table[index];
			table[index]->next = nw;
		}
		// Use the hash function on the key to get the index/slot,
		// create a new node with the key and insert it in this slot's list
	}
	else 
	{
		node* nw = createNode(key, artist);
		while (search->next != NULL)
		{
			if (search->artistNode->getName() == nw->artistNode->getName())
			{
				break;
			}
			else
			{
				search = search->next;
			}
		}
		search->next = nw;
		nw->next = NULL;
	}
}

Album* HashTable::findAlbum(string albumName)
{
	int index = 0;
	while (index < 26) //make sure i know how to do elementary math, this might not work
	{
		node* temp = table[index];
		if (temp != NULL)
		{
			while (temp->next != NULL && temp->artistNode->getAlbum(albumName)->getName() != albumName)
			{
				temp = temp->next;
			}
			if (temp->artistNode->getAlbum(albumName) != NULL)
			{
				if (temp->artistNode->getAlbum(albumName)->getName() == albumName)
				{
					return temp->artistNode->getAlbum(albumName);
				}
			}
		}
		index++;
	}
	return NULL;
	//}
}

void HashTable::findSong(string songName)
{
	int index = 0;
	while (index < 26) //make sure i know how to do elementary math, this might not work
	{
		node* temp = table[index];
		if (temp != NULL)
		{
			while (temp->next != NULL && temp->artistNode->searchSong(songName)->name != songName)
			{
				temp = temp->next;
			}
			if (temp->artistNode->searchSong(songName)->name == songName)
			{
				cout << temp->artistNode->searchSong(songName)->name << " by " << temp->artistNode->getName() << endl;
				cout << "-------------------------------------" << endl;
				cout << "Album: " << temp->artistNode->albumBySong(songName)->getName() << endl;
				cout << "Length - " << temp->artistNode->searchSong(songName)->minutes << ":" << temp->artistNode->searchSong(songName)->seconds << endl;
				//cout << "Rating - " << rating << endl;
				cout << "Next song on the album - " << temp->artistNode->searchSong(songName)->next->name << endl;
				cout << "-------------------------------------" << endl;
				//temp->artistNode->searchSong(songName)->printSongInfo();
				return;
				//return song;
					//temp->artistNode->searchSong(songName);
			}
		}
		index++;
	}
	//return NULL;
	cout << "Error: Song not found." << endl;
	
}

/*
Album* HashTable::searchAlbum(string albumName)
{

}
*/


//TODO Complete this function
// function to display hash table
void HashTable::printTable()
{
	for (int i = 0; i < tableSize; i++) 
	{
		node* temp = table[i];
		cout << i << " ||" ;
		if (temp != NULL)
		{
			cout << temp->artistNode->getName();
			while (temp->next != NULL)
			{
				temp = temp->next;
				cout << temp->artistNode->getName();

			}
			cout << endl;

		}
		else
		{
			cout << " *" << endl;
		}
		//TODO
	}

}