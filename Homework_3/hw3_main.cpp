/****************************************************************/
/*                   Assignment 3 Driver File                   */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "hw3_CountryNetwork.hpp"
using namespace std;
// you may include more libraries as needed
// declarations for main helper-functions
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
				//cout << " 1. Build Network " << endl;
				//This option calls the loadDefaltSetup func, then the printPath func.
			
				CountryNet.loadDefaultSetup();
				CountryNet.printPath();
				//cout << endl;
				break;
			}
			case 2:
			{	
				//cout << " 2. Print Network Path " << endl;
				//calls printPath
				CountryNet.printPath();
				//cout << "== CURRENT PATH ==" << endl;
				//cout << "nothing in path" << endl;
				
				//cout << endl;
				break;
			}
			case 3:
			{
				string country;
				string msg;
				cout << "Enter name of the country to receive the message: " << endl;
				getline(cin, country);
				cout << "Enter the message to send: " << endl;
				cout << endl;
				getline(cin, msg);
				CountryNet.transmitMsg(country, msg);
				//{

					//need to write edge case statements
					//Country *cntry = NULL;
					//cout << endl;
					//cntry = CountryNet.searchNetwork(country);
					//if (cntry != NULL)
					//{
					//	CountryNet.transmitMsg(country, msg);

					//}
					//else if (cntry->name == "NULL")
					//{
					//	//CountryNet.searchNetwork
					//	cout << "Country not found" << endl;
					//}
					//else
					//{
					//	CountryNet.transmitMsg(country, msg);
					//}
				//}
				break;
			}
			case 4:
			{
				//prompt two inputs: name of new country to add (newCountry) and name of a country already in the network (previous), which precedes new country. Use member func searchNetwork and insertCountry to insert right after previous. 
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
				cout << endl;
				break;
			}
			case 5:
			{
				cout << "Quitting..." << endl;
				cout << "Goodbye!" << endl;
				isQuit = true;
				break;
			}
			default:
			{
				cout << "default" << endl;
			}
		}

	}

    return 0;
}



/*
 * Purpose; displays a menu with options
 */
void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
	//This option calls the loadDefaltSetup func, then the printPath func.
    cout << " 2. Print Network Path " << endl;
	//calls printPath
    cout << " 3. Transmit Message " << endl;
	//prompt two inputs: messg to send, and name of country to receive messg (use getline). pass message and country name to transmitMsg. Add newline after messg is collectedand before output is printed.
    cout << " 4. Add Country " << endl;
	//prompt two inputs: name of new country to add (newCountry) and name of a country already in the network (previous), which precedes new country. Use member func searchNetwork and insertCountry to insert right after previous. 
    cout << " 5. Quit " << endl;

    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
