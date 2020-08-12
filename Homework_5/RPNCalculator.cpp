// CS2271 Fall 2019
// Author: Kevin Busch
// Homework 5
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "RPNCalculator.hpp"
using namespace std;

///Operand* stackHead;

//Constructor - set the stackHead pointer to NULL
RPNCalculator::RPNCalculator()
{
	stackHead = NULL;
}

//Destructor - pop everyting off the stack and set stackHead to NULL
RPNCalculator::~RPNCalculator()
{
	//
	if(!isEmpty())
	{
		while(!isEmpty())
		{
			pop();
		}
		stackHead = NULL;
	}
	//do i need an else?
}

//Returns true if the stack is empty (stackHead = NULL) false otherwise
bool RPNCalculator::isEmpty()
{
	if (stackHead == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Insert a new node with number onto the top of the stack (beginning of linklst)
void RPNCalculator::push(float num)
{
    Operand* temp = new Operand;
    temp->number = num;
	temp->next = stackHead;
	stackHead = temp;
	//stackHead->number = num;
	//stackHead = num;
	//line above might be wrong
}

void RPNCalculator::pop()
{
	if (isEmpty())
	{
		cout << "Stack empty, cannot pop an item." << endl;
		return;
	}
	else
	{
		Operand* temp;
		temp = stackHead;
		stackHead = stackHead->next;
		delete temp;
		//might need return
	}
}

//If stack is empty, print "Stack empty, cannot peek." & return NULL. Else return pointer to top of stack
Operand* RPNCalculator::peek() 
{
	if (isEmpty())
	{
		cout << "Stack empty, cannot peek." << endl;
		return NULL;
	}
	else
	{
		return stackHead;
	}
}


/*
* Perform operation (either + or *) on top 2 nums in stack. Return val indicates if operation was successful.
* If symbol isn't + or * print "err: invalid operation", return false
* Store floats from top 2 elements of stack in local variables and pop them
* Before getting each element check stack not empty. If empty, cout error & return false
* After popping first, if list is empty, pring error, push first back on to stack with push function, return false.
*/
bool RPNCalculator::compute(string symbol)
{
	Operand* num1;
	Operand* num2;
	float val1;
	float val2;
	float num3;
	if (symbol != "*" && symbol != "+")
	{
		cout << "err: invalid operation" << endl;
		return false;
	}
	else
	{
		if (isEmpty())
		{
			cout << "err: not enough operands" << endl;
			return false;
		}
		else
		{
			num1 = peek();
			val1 = num1->number;
			//cout << "val1: " << val1 << endl;
			pop();


			if (isEmpty())
			{
				push(val1);
				cout << "err: not enough operands" << endl;
				return false;
			}
			else
			{
				num2 = peek();
				val2 = num2->number;
				//cout << "val2: " << val2 << endl;
				pop();
				if (symbol == "+")
				{
					num3 = val1 + val2;
					//cout << "num3: " << num3 << endl;
					push(num3);
				}
				else if (symbol == "*")
				{
					num3 = val1 * val2;
					//cout << "num3: " << num3 << endl;
					push(num3);
				}
			}
		}
		
	}
	
}