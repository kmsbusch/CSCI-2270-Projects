// CS2271 Fall 2019
// Author: Kevin Busch
// Homework 5
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ProducerConsumer.hpp"
using namespace std;


//dont understand this error
ProducerConsumer::ProducerConsumer()
{
	queueFront = 0;
	queueEnd = 0;
	//counter = 0; 
	//should i do this?
}

//Return true if the queue is empty, false otherwise
bool ProducerConsumer::isEmpty()
{
	if (counter == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Return true if the queue is full, false otherwise
bool ProducerConsumer::isFull()
{
	if (counter == 20)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//If queue isn't full, add item to end of Q and modify queueFront or queueEnd if needed, else print error message
void ProducerConsumer::enqueue(string item)
{
	if (isFull())
	{
		cout << "Queue full, cannot add new item" << endl;
	}
	else if (queueFront == 0)
	{
		queue[queueEnd] = item;
		queueEnd++;
		counter++;
	}
	else if (queueEnd >= SIZE - 1 && queueFront != 0) //not taking this case - counter was qEnd
	{
		queueEnd = 1;
		queue[queueEnd] = item;
		counter++;
		//should this ^ be incrementing
	}
	else //why is this the same as the case for qFront == 0
	{
		queue[queueEnd] = item;
		//line below was above before
		queueEnd++;
		counter++;
	}
	//cout << "reee" << endl;
}

//Remove first item from Q if not empty, modify qFront or qEnd if needed, else print error.
void ProducerConsumer::dequeue()
{
	if (isEmpty())
	{
		cout << "Queue empty, cannot dequeue an item" << endl; 
	}
	//queue[queueFront] = "";
	counter--;
	//if (queueFront == queueEnd)
	//{
		// queueFront = 0;
		// queueEnd = 0;
		//counter = 0;
	//}
	if (queueFront == SIZE - 1)
	{
		queueFront = 0;
	}
	else
	{
		queueFront++;
	}
	//cout << "test" << endl;
}

//Return number of items in queue
int ProducerConsumer::queueSize()
{
	return counter;
}

//If Q empty, print error and return empty string, else return first item in queue
string ProducerConsumer::peek()
{
	if (isEmpty())
	{
		cout << "Queue empty, cannot peek" << endl;
		return "";
	}
	else
	{
		//idk what is wrong with this / what i should do with it
		return queue[queueFront];
	}
}

