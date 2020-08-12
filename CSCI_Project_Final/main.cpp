#include "Hash.h"
#include "Artist.h"
#include "Album.h"
#include "Song.h"
#include <cstdlib>

#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;


void menuASCII()
{
	string string1 = R"( ___ ___ _____ _   _  _   _ )";
	string string2 = R"(|  \/  ||  ___| \ | || | | |)";
	string string3 = R"(| .  . || |__ |  \| || | | |)";
	string string4 = R"(| |\/| ||  __|| . ` || | | |)";
	string string5 = R"(| |  | || |___| |\  || |_| |)";
	string string6 = R"(\_|  |_/\____/\_| \_/ \___/ )";

	cout << string1 << endl;
	cout << string2 << endl;
	cout << string3 << endl;
	cout << string4 << endl;
	cout << string5 << endl;
	cout << string6 << endl;
}

void displayMenu()
{
	cout << "     Select an option:" << endl;
	cout << "========Main Menu==========" << endl;
	cout << " 1. View Artists " << endl;
	cout << " 2. Search Artist By Name " << endl;
	cout << " 3. Search Albums By Name " << endl;
	cout << " 4. Search Songs By Name " << endl;
	cout << " 5. Help" << endl;
	cout << " 6. Quit " << endl;
	cout << "-------------------------" << endl;
	cout << "=> ";
}

void driver()
{
	HashTable hashtable = HashTable();
	hashtable.loadDefaultSetup();
	bool quit = false;
	string line;

	menuASCII();
	while (!quit)
	{
		displayMenu();
		getline(cin, line);
		if (isdigit(line[0]))
		{
			int menuChoice = stoi(line);
			switch (menuChoice)
			{
				case 1: //Search Album? Need to ask dad how to do this in a not terrible way
				{
					hashtable.printTable();
					break;
				}
				case 2: //Search Artist
				{
					cout << "Please enter an artist to search the database for: " << endl;
					cout << "=> ";
					string userSearch = "";
					getline(cin, userSearch);

					Artist* artist = hashtable.searchArtist(userSearch);
					if (artist != NULL)
					{
						cout << "search got: " << artist->getName() << endl;
						artist->printAlbums();
						cout << "If you would like to view an album, please type it's name. Otherwise, type quit to go back." << endl;
				

						bool quit = false;
						while (!quit)
						{
							cout << "=> ";

							string albumSearch = "";
							getline(cin, albumSearch);

							if (albumSearch == "quit" || albumSearch == "QUIT" || albumSearch == "Quit")
							{
								quit = true;
								break;
							}

							Album* album = artist->getAlbum(albumSearch);
							if (album != NULL)
							{
								album->printSongs();
								break;
							}
							else
							{
								cout << "Album not found. Please try again or type quit to go back." << endl;
							}
						}
					}
					else
					{
						cout << "Artist not found. Please try again or type quit to go back." << endl;
					}

					break;
				}
				case 3: //Search Album? Need to ask dad how to do this in a not terrible way
				{
					cout << "Please type the name of an album you would like to search for: " << endl;
					cout << "=> ";
					string albumSearch = "";
					getline(cin, albumSearch);
					Album* album = hashtable.findAlbum(albumSearch);
					if (album != NULL)
					{
						album->printSongs();
					}
					else
					{
						cout << "Album not found. Please try again or type quit to go back." << endl;
					}
					break;
				}
				case 4: //Search Song
				{
					cout << "Please type the name of a song you would like to search for: " << endl;
					cout << "=> ";
					string songSearch = "";
					getline(cin, songSearch);
					hashtable.findSong(songSearch);
					break;
				}
				case 5: //More Information
				{
					cout << "This program constructs a database of artists and their music for a user to search through. User can search for artists, albums, or songs." << endl;
					break;
				}
				case 6: //Quit
				{
					cout << "Thank you for using the program, have a good day! :>" << endl;
					quit = true;
					break;
				}
				default:
				{
					cout << "Invalid choice, please choose one of the numbers from the menu." << endl;
					break;
				}

			}
		}
		else
		{
			cout << "Invalid input, please try one of the numbers corresponding to the menu options." << endl;
		}
		
		

	}
}

int main(int argc, char* argv[])
{
	/*
	displayMenu();
	Artist* acdc = new Artist();
	acdc->setName("ACDC");
	acdc->setGenre("Rock");


	
	Songlist* songlist = new Songlist();
	album1.setList(songlist);
	album1.setName("Album1");
	album1.setGenre("Rock");
	
	Song* song1 = new Song();
	song1->minutes = 3;
	song1->seconds = 22;
	song1->rating = 8.3;
	song1->name = "song1";

	Song* song2 = new Song();
	song2->minutes = 2;
	song2->seconds = 19;
	song2->rating = 7.6;
	song2->name = "song2";

	Song* song3 = new Song();
	song3->minutes = 3;
	song3->seconds = 23;
	song3->rating = 5.4;
	song3->name = "song3";

	Song* song4 = new Song();
	song4->minutes = 2;
	song4->seconds = 13;
	song4->rating = 4.1;
	song4->name = "song4";

	Song* song5 = new Song();
	song5->minutes = 4;
	song5->seconds = 58;
	song5->rating = 8.1;
	song5->name = "song5";

	Song* song6 = new Song();
	song6->minutes = 1;
	song6->seconds = 21;
	song6->rating = 5.5;
	song6->name = "song6";

	//cout << "1" << endl;
	album1.addSong(song1);
	//cout << "2" << endl;
	album1.addSong(song2);
	//cout << "3" << endl;
	album1.addSong(song3);
	//cout << "4" << endl;
	album1.addSong(song4);
	//cout << "5" << endl;
	album1.addSong(song5);
	//cout << "6" << endl;
	album1.addSong(song6);
	
	
	//have to insert all the songs before setHead...


	
	

	acdc.addAlbum(album1);
	

	Album album2 = Album("Album2", "Rock", 2000);
	acdc.addAlbum(album2);
	
	Album album3 = Album("Album3", "Rock", 2000);
	acdc.addAlbum(album3);
	
	acdc.printAlbums();
	album1.printSongs();
	songlist->printSongInfo(song1);

	acdc.searchSong("song1");
	*/

	/*
	Album album2 = Album("Album2", "Rock", 2000);
	Songlist* songlist = new Songlist();
	album2.setList(songlist);
	acdc->addAlbum(album2);

	Song* song1 = new Song();
	song1->minutes = 3;
	song1->seconds = 22;
	song1->rating = 8.3;
	song1->name = "song1";

	acdc->addSong("Album2",song1);

	hashtable.insertItem("ACDC", acdc);
	*/

	//Artist* testConfirm = hashtable.searchArtist("Daft Punk");
	//cout << "search got: " << testConfirm->getName() << endl;
	//testConfirm->printAlbums();
	//Album* testAlbum = testConfirm->getAlbum("Alive 2007");
	//testAlbum->printSongs();
	
	/*
	HashTable hashtable = HashTable();
	hashtable.loadDefaultSetup();

	Artist* testConfirm1 = hashtable.searchArtist("Kanye West");
	cout << "search got: " << testConfirm1->getName() << endl;
	testConfirm1->printAlbums();
	Album* testAlbum1 = testConfirm1->getAlbum("Graduation");
	testAlbum1->printSongs();
	hashtable.findSong("Fresh");
	hashtable.findSong("k");
	*/
	

	driver();


}

