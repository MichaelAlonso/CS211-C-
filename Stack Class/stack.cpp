#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;

Stack::Stack()
{
  top = -1; //this is going to set it to -1 (stack is empty)
}

/**************************
this is going to check if it is empty

 *************************/

bool Stack::isEmpty()const
{
  if(top == -1)
    return true;
  return false;
}

/************************
This is going to check if the function is full or not

 ***********************/

bool Stack::isFull()const
{
  if(top == MAX - 1)
    return true;
  return false;

}

/**************************

This is the function that is going to push
and if it is full then displays stackoverflow

 *************************/

void Stack::push(el_t el)
{
  if(isFull() == true)
    {
      stackError("Stack Overflow");
    }
  top++;
  names[top] = el;
}

/************************
This function is going to pop and if isEmpty is true
then it will display stack overflow

 ***********************/

el_t Stack::pop()
{
  if(isEmpty() == true)
    {
      stackError("Stack Overflow");
      exit(1);
    }
  return names[top--];
}

/***************************
this function is going to get topElem
and display the message if there is no one

 **************************/
el_t Stack::topElem()const
{
  if(isEmpty() == true)
    {
      cout << "Cannot get top Elem. Stack is Empty" << endl;
    }
  return names[top];
}
/**************************
This is going to clear whatever it is and display
this message if it is true if empty

 *************************/

void Stack::clearIt()
{
  if(isEmpty() == true)
    {
      cout << "Cannot  clear stack. Stack is Empty" << endl;
    }
  top = -1; //set the status back to empty
}

/*************************
Pretty much going to display a error message whatever deciding to put in
the parameter

 *************************/

void Stack::stackError(string errorMessage)const
{
  cout << errorMessage << endl;
  exit(1);
}

/************************************
going to display whatever we use it for

*************************************/

void Stack::displayAll()const
{
  for(int i = top; i > -1; i--) //we stop at -1 so then we dont access -1 index
    {
      cout << names[i] << endl;
    }
}
