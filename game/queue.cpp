#include <iostream>
#include <string>
#include <cstdlib>

#include "queue.h" //this is using our queue.h file that we made
using namespace std;

/***************************************
This is setting up the the things we have in private and then setting them all up to 0
but not the rear 
 **************************************/
Queue::Queue()
{
  rear = -1; //The front is going to be in front of rear when the stack to be empty
  front = 0; //set to 0
  count = 0; //set to 0
}

/***************************************

This is going to be function that is going to check for if it is full 

 ***************************************/
bool Queue::isFull()const
{
  if(count == MAX)
    {
      return true; //if count is to MAX then it is true that it is full
    }
  return false; //if it is not then it is not full yet
}

/****************************************

This is going to check if it is empty 

****************************************/
bool Queue::isEmpty()const
{
  if(count == 0)
    {
      return true; //if it is at 0 then it is true
    }
  return false; //more than 0 then it is not empty
}

/***************************************

This is going to send a error message if it doesnt work

 ***************************************/
void Queue::queueError(string errorMessage) const
{
  cout << errorMessage << endl;
  exit(1);
}

/***************************************

this function is going to add 

 **************************************/
void Queue::add(el_t element)
{
  if(isFull() == true)
    {
      queueError("Queue Overflow can not add anymore"); //display the error message
    }
  rear = (rear + 1) % MAX;
  elem[rear] = element;
  count++; //This is going to increase the number of elements found inside the array
}

/********************************

This is going to remove 

*********************************/

el_t Queue::remove()
{
  if(isEmpty() == true)
    {
      queueError("Queue Underflow cant remove whats not there");
    }
  el_t elret = elem[front];
  front = (front + 1) % MAX; //use to change to the new front
  count--; //going to decrease the numbers in element
  return elret;
}

/********************************

This is going to get the front number in the queue

*********************************/
el_t Queue::getFront()const
{
  if(isEmpty() == true)
    {
      cout << "Queue is empty" << endl;
    }
  return elem[front];
}

/*************************************

When it moves the number to the back

 ************************************/
void Queue::goBack()
{
  if(isEmpty() == true)
    {
      queueError("Queue Underflow there are no numbers to put back");
    }
  add(remove());
}

int Queue::getSize()const
{
  return count;
}

/*********************************

 *MAKE SURE TO HAVE THIS BEFORE DISPLAY ALL

This is our ostream operator that is going to be used for game.cpp
and is to show an expr struct (e.g. 5 + 8) before displayAll()

 *********************************/

ostream& operator <<(ostream& out, const expr& x)
{
  //this is going to call the three things we had in the new struct expr
  out << x.oprd1 << " " << x.oprt << " " << x.oprd2;
  return out;
}

/*********************************

This is going to display all that we have

 *******************************/

void Queue::displayAll()const
{
  int index = front;
  for(int i = 0; i < count; i++)
    {
      cout << elem[index] << " ";
      index = (index + 1) % MAX;
    }
  cout << endl;
}
