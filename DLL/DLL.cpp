#include <iostream> // print error message
#include <cstdlib> // exit(1);
#include <string> // string error
#include <cmath>
#include "DLL.h" //you change this to LL instead of it being lqueue.h
using namespace std;

//pretty much what we did in DLL.h change all LL to DLL
//also make sure to change all of these to LL, EX: LQueue::LQueue() -> LL::LL()
DLL::DLL() 
{
  front = NULL;
  rear = NULL;
  count = 0;
}

//same thing here EX: LQueue::~LQueue() -> LL::~LL()
DLL::~DLL() 
{
  while(!isEmpty())
    {
      deleteFront();
    }
}

void DLL::llError(string errorMessage) 
{
  cout << errorMessage << endl;
}

bool DLL::isEmpty() 
{
  if(front == NULL && rear == NULL) //count == 0 is new addition 
    {
      return true;
    }
  else
    return false;
}

//this function we are just adding some new lines
void DLL::addRear(el_t el) 
{
  if(isEmpty())
    {
      front = rear = new Node;
      front -> elem = el;
      rear -> prev = rear -> next = NULL; //this is the new line we added
    }
  else
    {
      rear -> next = new Node;
      rear -> next -> prev = rear; //this is also a new line we added
      rear = rear -> next;
      rear -> elem = el;
      rear -> next = NULL;
    }
  count++;
}


el_t DLL::deleteFront() 
{ 
  if(isEmpty())
    {
      llError("The Queue is Empty. Can't be Deleted");
      // return -1; may have to change this
    }
  else if(count == 1)
    {
      el_t element = front -> elem;
      delete front;
      front = rear = NULL;
      count--;
      return element;
    }
  else
    {
      //Node* next = front -> next; might have to delete this
      el_t element = front -> elem;
      front = front -> next;
      delete front -> prev;
      front -> prev = NULL;
      count--;
      return element;
    }
}

void DLL::displayAll() 
{
  if(isEmpty()) 
    {
    cout << "[Empty]" << endl;
    }
  else
    {
      Node *p;
      p = front;
      while(p != NULL) 
	{
	  cout << p -> elem << " ";
	  p = p -> next;
	}
    }
  cout << endl; //may mess up the display but ill see and change it if needed
}

//********************************* These functions are from the first LL Lab ***************************************
el_t DLL::deleteRear()
{
  if(isEmpty())
    {
      llError("[Error: List is Empty.]");
    }
  else if(count == 1 /*&& front == rear*/)
    {
      el_t old = rear -> elem;
      delete rear;
      front = rear = NULL;
      count--;
      return old;
    }
  else
    {
      //Node* p = new Node; //might have to delete this not sure yet
      el_t old = rear -> elem;
      rear = rear -> prev;
      //delete rear;
      //for(p = front; p -> next != rear; p = p -> next);
      delete rear -> next;
      //rear = p;
      rear -> next = NULL;
      count--;
      return old;
    }
}

void DLL::addFront(el_t el)
{
  if(isEmpty())
    {
      front = rear = new Node;
      rear -> elem = el;
      //rear -> next = NULL; //new adddition
      front -> prev = front -> next = NULL;
    }
  else
    {
      /*Node* p = new Node;
      p -> elem = el;
      p -> next = front;
      front = p;
      */
      front -> prev = new Node;
      front -> prev -> elem = el;
      front -> prev -> next = front;
      front -> prev -> prev = NULL;
      front = front -> prev;
    }
  count++;
}

DLL::DLL(const DLL& source)
{
  this -> front = this -> rear = NULL;
  this -> count = 0;
  Node* p = source.front;
  while(p != NULL)
    {
      this -> addRear(p -> elem);
      p = p -> next;
    }
}

//*********************** These are the other functions that are due for the upcoming lab ******************************8
bool DLL::search(el_t e)
{
  //int na = 0;
  Node* temp = front;
  while(temp != NULL)
    {
      // na++;
      if(temp -> elem == e)
	return true;
      temp = temp -> next;
    }
  return false;
}

void DLL::deleteNode(el_t e)
{
  //Node* pre;
  Node* del;
  if(isEmpty())
    return;
  else if(front -> elem == e)
    {
      deleteFront();
    }
  else if(rear -> elem == e)
    {
      deleteRear();
    }
  else
    {
      for(del = front -> next; del != NULL && del -> elem != e; del = del -> next);
      if(del != NULL)
	{
	  del -> prev -> next = del -> next;
	  del -> next -> prev = del -> prev;
	  delete del;
	  count--;
	}
    }
}

void DLL::addInOrderAscend(el_t e)
{
  Node* p = front;
  if(front == NULL && rear == NULL)
    addFront(e);
  else
    {
      if(e < front -> elem)
	{
	  addFront(e);
	}
      else if(e > rear -> elem)
	{
	  addRear(e);
	}
      else
	{
	  Node* newNode = new Node;
	  newNode -> elem = e;
	  Node* n;
	  while(p -> next != NULL && p -> next -> elem < e)
	    {
	      p = p -> next;
	    }
	  n = p -> next;
	  newNode -> next = n;
	  newNode -> prev = p;
	  n -> prev = newNode;
	  p -> next = newNode;
	  count++;
	}
    }
}

/*********************

This is going to output elements inside the heap memory and display the functions using next node

***********************/
void DLL::printAllReverseDLL()
{
  if(isEmpty())
    cout << " [Empty] " << endl;
  else
    {
      Node* current = rear;
      while(current != NULL)
	{
	  cout << current -> elem << " ";
	  current = current -> prev;
	}
    }
}
