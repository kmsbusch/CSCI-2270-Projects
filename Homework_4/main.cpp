/****************************************************************/
/*                   Assignment 4 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/
//#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CountryNetwork.hpp"
// you may include more libraries as needed

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
    // Object representing our network of cities.
    // (Linked list representation is in CountryNetwork)
    CountryNetwork CountryNet;
    string line;
	bool isQuit = false;
	while (!isQuit)
	{
		

		displayMenu();
		getline(cin, line);
		int menuChoice = stoi(line);

		//will probably need to write an edge case for incorrect inputs as an if statement here
		switch (menuChoice)
		{
			case 1:
			{
				CountryNet.loadDefaultSetup();
				CountryNet.printPath();
				//cout << endl;
				break;
			}
            case 2:
            {
				CountryNet.printPath();
                break;
            }
            case 3:
            {
				Country *prevCountry;
				string newCountry;
				string previous;	

				cout << "Enter a new country name:" << endl;
				getline(cin, newCountry);
				cout << "Enter the previous country name (or First):" << endl;
				getline(cin, previous);
				prevCountry = CountryNet.searchNetwork(previous);
				if (previous == "First")
				{
					prevCountry->name = "First";
					CountryNet.insertCountry(prevCountry, newCountry);
					CountryNet.printPath();
				}
				else if (prevCountry->name != "NULL")
				{
					CountryNet.insertCountry(prevCountry, newCountry);
					CountryNet.printPath();
				}
				else
				{
					cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
					while (prevCountry->name == "NULL")
					{
						getline(cin, previous);
						prevCountry = CountryNet.searchNetwork(previous);

					}
					CountryNet.insertCountry(prevCountry, newCountry);
					CountryNet.printPath();
					cout << endl;

				}
				break;
                
            }
            case 4:
            {
                string deleteC;
                cout << "Enter a country name: " << endl;
                getline(cin, deleteC);
                CountryNet.deleteCountry(deleteC);
                CountryNet.printPath();
                break;

            }
            case 5:
            {
                CountryNet.reverseEntireNetwork();
                CountryNet.printPath();
                break;

            }
            case 6:
            {
                string choice;
                cout << "Enter the count of values to be rotated: " << endl;
                getline(cin, choice);             
                int num = stoi(choice);
                CountryNet.rotateNetwork(num);
                CountryNet.printPath();
                break;
            }
            case 7:
            {
                cout << "Network before deletion" << endl;
                CountryNet.printPath();
                CountryNet.deleteEntireNetwork();
                cout << "Network after deletion" << endl;
                CountryNet.printPath();
                break;
                

            }
            case 8:
            {
                //bool isClean = CountryNet.isEmpty();
                cout << "Quitting... cleaning up path: " << endl;
                CountryNet.printPath();
                CountryNet.deleteEntireNetwork();
                //CountryNet.printPath();
                if (CountryNet.isEmpty())
                {
                    cout << "Path cleaned" << endl;
                }
                else
                {
                    cout << "Error: Path NOT cleaned" << endl;
                }
                cout << "Goodbye!" << endl;
                isQuit = true;
                break;
            }
            default:
            {
                cout << endl;
                break;
            }
        }
    }
}

/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network" << endl;
    cout << " 6. Rotate Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}