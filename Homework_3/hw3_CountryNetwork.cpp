/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "hw3_CountryNetwork.hpp"
#include <string>
using namespace std;


Country* head; //ask whether i need this or not
/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
	head = NULL;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
	Country *node = new Country();
	node->name = countryName;
	node->next = NULL;

	if (previous == NULL)
	{
		node->next = head;
		head = node;
		cout << "adding: " << countryName << " (HEAD)" << endl;

	}
	else if (previous->name == "First")
	{
		node->next = head;
		head = node;
		cout << "adding: " << countryName << " (HEAD)" << endl;

	}
	else
	{
		Country *tmp = head;
		while (tmp->name != previous->name)
		{
			tmp = tmp->next;
		}
		cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;

		if (tmp->next != NULL)
		{
			node->next = tmp->next;
		}
		tmp->next = node;
	}
	//If you are adding at the beginning use this:

	//otherwise use this:
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
	Country *previous = NULL;
	string countryArray[] = {"United States", "Canada", "Brazil", "India", "China", "Australia"};
	for (int i = 0; i < 6; i++)
	{
		insertCountry(previous, countryArray[i]);
		if (i == 0)
		{
			previous = head;
		}
		else
		{
			previous = previous->next;
		}
	}
}

/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
	Country *node = head;
	if (head == NULL)
	{
		//node->name = "NULL";
		return NULL;
	}
	while (countryName != node->name && node->next != NULL)
	{
		node = node->next;
	}
	if (countryName != node->name && node->next == NULL)
	{
		node = new Country();
		node->name = "NULL";
	}
	return node;
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
	if (head == NULL)
	{
		cout << "Empty list" << endl;
	}
	else
	{
		Country *search = NULL;
		search = searchNetwork(receiver);
		if (search->name != "NULL")
		{
			Country *node = head;
			while (node->name != receiver)
			{
				node->message = message;
				node->numberMessages += 1;
				cout << node->name << " [# messages received: " << node->numberMessages << "] received: " << node->message << endl;
				node = node->next;

				//return node;
			}
			if (node->name == receiver)
			{
				node->message = message;
				node->numberMessages += 1;
				cout << node->name << " [# messages received: " << node->numberMessages << "] received: " << node->message << endl;
				node = node->next;
			}

		}
		else
		{
			cout << "Country not found" << endl;		}
	}
}


/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    Country *node = head;
	int count = 0;
	cout << "== CURRENT PATH ==" << endl;
	while (node != NULL)
	{
		cout << node->name << " -> ";
		node = node->next;
		count++;
	}
	if (count != 0)
	{
		cout << "NULL" << endl;
		cout << "===" << endl;

	}
	else
	{
		cout << "nothing in path" << endl;
		cout << "===" << endl;
	}
}
