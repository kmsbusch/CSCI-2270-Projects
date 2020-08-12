#include <iostream>
#include "QUEUEST.hpp"
using namespace std;


Queue::Queue()
{

}
Queue::~Queue()
{
  while(!isEmpty())
    dequeue();
}

/**
* This function will create the queue of size cap
* parameter: int cap
* return void
**/
void Queue:: initialiseQueue(int cap)
{
  primary.initialise(cap);
  secondary.initialise(cap);
}

/**
* This function will enqueue the argument num
* parameter: int num
* return void
**/
void Queue:: enqueue(int num){
    if(isFull())
    {
      cout<< " Queue is full. Can not enqueue"<<endl;
      return;
    }
    primary.push(num);
}
/**
* This function will dequeue from the queue.
* parameter: None
* return the dequeued value
* TODO: Implement this function
**/
int Queue:: dequeue()
{
  int num1; //storage number
  int num2; //number that is dequeued
  if (!primary.isEmpty()) //if stack isn't empty
  {
    while(!primary.isEmpty()) // while there is still something in primary stack
    {
      num1 = primary.peek(); //store value of top of stack

      secondary.push(num1); //push value from top of 1st stack to bottom of 2nd stack

      primary.pop(); //pop from first stack

    } //once 1st stack is empty
    num2 = secondary.peek(); //take top of 2nd stack, store to return as dequeue value

    secondary.pop(); //take dequeued value out of stack

    while (!secondary.isEmpty()) //move everything back into first stack in original order
    {
      num1 = secondary.peek(); //store top of 2nd stack

      primary.push(num1); //put top of 2nd stack into bottom of 1st stack
      
      secondary.pop(); //remove from 2nd stack
    }
    return num2;
  }
  else //if Queue is empty, take this case.
  {
    cout << "Queue is empty. Can not dequeue" << endl;
    return -999;
  }
}
/**
* returns true if queue is full
**/
bool Queue:: isFull(){
  return primary.isFull();
}

/**
* returns true if queue is full.
**/
bool Queue:: isEmpty(){
  return primary.isEmpty();
}
