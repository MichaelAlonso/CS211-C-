#include <iostream> // print error message
#include <cstdlib> // exit(1);
#include <string> // string error
#include <cmath>
#include "LL.h" //you change this to LL instead of it being lqueue.h
using namespace std;

//also make sure to change all of these to LL, EX: LQueue::LQueue() -> LL::LL()
LL::LL() 
{
  front = NULL;
  rear = NULL;
  count = 0;
}

//same thing here EX: LQueue::~LQueue() -> LL::~LL()
LL::~LL() 
{
  while(!isEmpty())
    {
      deleteFront();
    }
}

void LL::llError(string errorMessage) 
{
  cout << errorMessage << endl;
}

bool LL::isEmpty() 
{
  if(front == NULL && rear == NULL && count == 0) //count == 0 is new addition 
    {
      return true;
    }
  else
    return false;
}

void LL::addRear(el_t el) 
{
  if(isEmpty())
    {
      front = rear = new Node;
      front -> elem = el;
    }
  else
    {
      rear -> next = new Node;
      rear = rear -> next;
      rear -> elem = el;
      rear -> next = NULL;
    }
  count++;
}


el_t LL::deleteFront() 
{ 
  if(isEmpty())
    {
      llError("The Queue is Empty. Can't be Deleted");
      //return -1;
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
      Node* next = front -> next;
      el_t element = front -> elem;
      delete front;
      front = next;
      count--;
      return element;
    }
}

void LL::displayAll() 
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
el_t LL::deleteRear()
{
  if(isEmpty())
    {
      llError("[Error: List is Empty.]");
    }
  else if(count == 1 && front == rear)
    {
      el_t old = rear -> elem;
      delete rear;
      front = rear = NULL;
      count--;
      return old;
    }
  else
    {
      Node* p = new Node;
      el_t old = rear -> elem;
      //delete rear;
      for(p = front; p -> next != rear; p = p -> next);
      delete rear;
      rear = p;
      rear -> next = NULL;
      count--;
      return old;
    }
}

void LL::addFront(el_t el)
{
  if(isEmpty())
    {
      front = rear = new Node;
      rear -> elem = el;
      rear -> next = NULL; //new adddition
    }
  else
    {
      Node* p = new Node;
      p -> elem = el;
      p -> next = front;
      front = p;
    }
  count++;
}

LL::LL(const LL& source)
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
bool LL::search(el_t e)
{
  int na = 0;
  Node* temp = front;
  while(temp != NULL)
    {
      na++;
      if(temp -> elem == e)
	{
	  cout << na << " nodes checked \n found";
	  cout << endl; //may look weird if it does then delete this
	  return true;
	}
      temp = temp -> next;
    }
  cout << na << "nodes checked \n not found";
  cout << endl; //again if looked weird then delete this
  return false;
}

void LL::deleteNode(el_t e)
{
  Node* pre;
  Node* del;
  if(isEmpty())
    return;
  else
    for(pre = front, del = front -> next; del != NULL && del -> elem != e; pre = del, del = del -> next);
  if(del != NULL)
    {
      pre -> next = pre -> next -> next;
      delete del;
      count--;
    }
  else if(pre == front || front -> elem == e)
    {
      deleteFront();
    }
  else
    {
      return;
    }
}

void LL::addInOrderAscend(el_t e)
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
	  while(p -> next != NULL && p -> next -> elem < e)
	    {
	      p = p -> next;
	    }
	  newNode -> next = p -> next;
	  p -> next = newNode;
	  count++;
	}
      
    }
}
