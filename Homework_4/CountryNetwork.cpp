/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CountryNetwork.hpp"
using namespace std;

Country* head;
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
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
	if (head != NULL)
	{
		return false;
	}
	else 
	{
		return true;
	}
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
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName) 
{
	Country *node = head;
	if (node->name != countryName && node != NULL)
	{
		
		Country* search = searchNetwork(countryName);
		if (search != NULL)
		{
			while(node->next != search)
			{
				node = node->next;

			}
			node->next = node->next->next;
			delete search;
		}
		else
		{
			cout << "Country does not exist." << endl;
		}
	}
	else
	{
		head = node->next;
		delete node;
	}
	
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
	Country *node = head;
	if (head != NULL)
	{
		while (node->next != NULL && head != NULL)
		{	
			node = head;
			//string name = node->name;
			cout << "deleting: " << node->name << endl;
			deleteCountry(node->name);
		}
		if (head == NULL)
		{
			//cout << "deleting: " << node->name << endl;
			//head = node->next;
			//delete node;
			cout << "Deleted network" << endl;
		}
	}
	else
	{
		return;
	}

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
 * @see insertCountry, deletecountry
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
 * Purpose: Rotate the linked list i.e. move 'n' elements from
 * the back of the the linked to the front in the same order.
 * @param number elements to be moved from the end of the list to the beginning
 * @return none
 */
void CountryNetwork :: rotateNetwork(int n) 
{	
	if (head != NULL)
	{
		Country *count = head;
		int k = 0;
		while (count->next != NULL)
		{
			count = count->next;
			k++;
		}
		if (n <= k)
		{
			int i = 0;
			while (i < n)
			{
				Country *node = head;
				Country *temp = head;
				head = head->next;
				while (node->next != NULL)
				{
					node = node->next;
				}
				node->next = temp;
				temp->next = NULL;
				i++;
			}
			cout << "Rotate Complete" << endl;
		}
		else
		{
			cout << "Rotate not possible" << endl;
		}
	}
	else
	{
		cout << "Linked List is Empty" << endl;
	}
	

}

/*
 * Purpose: reverse the entire network
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork() 
{
	Country *current = head;
	Country *prev = NULL, *next1 = NULL;
	while (current != NULL)
	{
		next1 = current->next;
		current->next = prev;

		prev = current;
		current = next1;
	}
	head = prev;
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
