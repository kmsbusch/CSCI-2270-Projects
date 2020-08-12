/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/
#include "ProducerConsumer.cpp"
#include "ProducerConsumer.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
	ProducerConsumer pc;
	string line;
	bool isQuit = false;
	while (!isQuit)
	{
		menu();
		getline(cin, line);
		int menuChoice = stoi(line);
		switch (menuChoice)
		{
			case 1:
			{ 
				cout << "Enter the number of items to be produced:" << endl;
				
				string ITEM_NO;				
				getline(cin, ITEM_NO);
				int NUM_ITEMS = stoi(ITEM_NO);
				for (int i = 1; i < NUM_ITEMS + 1; i++)
				{
					cout << "Item" << i << ":" << endl;
					string produce;
					getline(cin, produce);
					pc.enqueue(produce);
					break;
				}


			}
			case 2:
			{
				string deQ;
				cout << "Enter the number of items to be consumed:" << endl;
				getline(cin, deQ);
				int deQNum = stoi(deQ);
				for (int i = 0; i < deQNum; i++)
				{
					if (pc.queueSize() == 0)
					{
						cout << "No more items to consume from queue" << endl;
						break;
					}
					else
					{
						string consumed = pc.peek();
						pc.dequeue();
						cout << "Consumed: " << consumed << endl;
					}
				}
				break;
			}
			case 3:
			{
				cout << "Number of items in the queue:" << pc.queueSize() << endl;
				isQuit = true;
				break;
			}
		}
	}

}
