#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void menu()
{
	cout << "======Main Menu======" << endl;
	cout << "1. Print the inventory" << endl;
	cout << "2. Delete a movie" << endl;
	cout << "3. Quit" << endl;
}

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		MovieTree tree;
		//Read in movies from file and put them into tree
		ifstream fs;//(argv[2]);
		string fileName = argv[1];
		string line = "";
		fs.open(fileName);
		if (fs.is_open())
		{
			while (getline(fs, line))
			{
				stringstream ss(line);
				//ss << line;
				string temp = "";

				getline(ss, temp, ',');
				int ranking = stoi(temp);
				
				getline(ss, temp, ',');
				string title = temp;

				getline(ss, temp, ',');
				int year = stoi(temp);

				getline(ss, temp, ',');
				float rating = stof(temp);

				tree.addMovie(ranking, title, year, rating);
			}
		}
		//Actual driver
		string choice = "";
		bool isQuit = false;
		while (!isQuit)
		{
			menu();
			getline(cin, choice);
			int menuChoice = stoi(choice);
			switch(menuChoice)
			{
				case 1:
				{
					tree.printMovieInventory();
					break;
				}
				
				case 2:
				{
					string titleName = "";
					cout << "Enter a movie title:" << endl;
					getline(cin, titleName);
					//delete movie 
					tree.deleteMovie(titleName);
					break;
				}
				case 3:
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
	}

}