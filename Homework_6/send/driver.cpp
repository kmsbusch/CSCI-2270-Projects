//#include "MovieTree.cpp"
#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;


void menu()
{
	cout << "======Main Menu======" << endl;
	cout << "1. Find a movie" << endl;
	cout << "2. Query movies" << endl;
	cout << "3. Print the inventory" << endl;
	cout << "4. Average Rating of movies" << endl;
	cout << "5. Quit" << endl;
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{

		MovieTree tree;
		//Read in movies from file and put them into tree
		ifstream fs;//(argv[2]);
		string fileName = argv[1];
		string newLine = "";
		fs.open(fileName);
		if (fs.is_open())
		{
			while (getline(fs, newLine))
			{
				stringstream ss(newLine);
				//ss << newLine;
				string temp = "";

				getline(ss, temp, ',');
				int ranking = stoi(temp);
				
				getline(ss, temp, ',');
				string title = temp;

				getline(ss, temp, ',');
				int year = stoi(temp);

				getline(ss, temp, ',');
				float rating = stof(temp);

				tree.addMovieNode(ranking, title, year, rating);
			}

		}

		//Actual driver
		string line = "";
		bool isQuit = false;
		while (!isQuit)
		{
			menu();
			getline(cin, line);
			int menuChoice = stoi(line);
			switch(menuChoice)
			{
				case 1:
				{
					cout << "Enter title:" << endl;

					string movieName = "";
					getline(cin, movieName);

					tree.findMovie(movieName);
					break;
				}
				case 2:
				{
					string input1 = "";
					string input2 = "";

					cout << "Enter minimum rating:" << endl;
					getline(cin, input1);
					float minRating = stof(input1);					

					cout << "Enter minimum year:" << endl;
					getline(cin, input2);
					int minYear = stoi(input2);

					tree.queryMovies(minRating, minYear);
					break;
				}
				case 3:
				{
					tree.printMovieInventory();
					break;
				}
				case 4:
				{
					tree.averageRating();
					break;
				}
				case 5:
				{
					cout << "Goodbye!" << endl;
					isQuit = true;
					break;
				}
				default:
				{
					break;
				}
			}
		}
	}
	else
	{
		cout << "Not enough arguments" << endl;
		return 0;
	}
}
