#ifndef LL_T_H
#define LL_T_H
#include <iostream> // print error message
#include <cstdlib> // exit(1);
#include <string> // string error
#include <cmath> //you change this to LL instead of it being lqueue.h
using namespace std;

template <class T>
struct Node
{
  //element for this node will be an integer             
  T elem;
  //this is the pointer that will be leading to the next node
  Node<T>* next;
};

template <class T>
class LL
{
 private:
  Node<T>* front;
  Node<T>* rear;
  int count;
  //void llError(string msg);
  void printAllReverse(Node<T>* p);
  //the public will be where we will be calling for our functions
 public:
  //this is going to be the constructor             
  LL();
  //This will be the destructor
  ~LL();
  void addRear(const T& el);
  T deleteFront();
  bool isEmpty();
  void displayAll();
  void addFront(const T& el);
  T deleteRear();
  void deleteNode(const T& e);
  bool search(const LL<T>& e);
  LL(const LL<T>& source);
  void addInOrderAscend(const T& e);
  void printAllReverse();
  Node<T>* getFront();
  Node<T>* getRear();
  Node<T>* getNext(Node<T>*& p);
  class underflow{};
};




//also make sure to change all of these to LL, EX: LQueue::LQueue() -> LL::LL()
template <class T>
LL<T>::LL() 
{
  front = NULL;
  rear = NULL;
  count = 0;
}

//same thing here EX: LQueue::~LQueue() -> LL::~LL()
template <class T>
LL<T>::~LL() 
{
  while(!isEmpty())
    {
      deleteFront();
    }
}

/*
template <class T>
void LL<T>::llError(string errorMessage) 
{
  cout << errorMessage << endl;
}
*/

template <class T>
bool LL<T>::isEmpty() 
{
  if(front == NULL && rear == NULL && count == 0) //count == 0 is new addition 
    {
      return true;
    }
  else
    return false;
}

template <class T>
void LL<T>::addRear(const T& el) 
{
  if(isEmpty())
    {
      front = rear = new Node<T>;
      front -> elem = el;
    }
  else
    {
      rear -> next = new Node<T>;
      rear = rear -> next;
      rear -> elem = el;
      rear -> next = NULL;
    }
  count++;
}

template <class T>
T LL<T>::deleteFront() 
{ 
  if(isEmpty())
    {
      throw underflow();
      //llError("The Queue is Empty. Can't be Deleted");
      //return -1;
    }
  else if(count == 1)
    {
      T element = front -> elem;
      delete front;
      front = rear = NULL;
      count--;
      return element;
    }
  else
    {
      Node<T>* next = front -> next;
      T element = front -> elem;
      delete front;
      front = next;
      count--;
      return element;
    }
}

template <class T>
void LL<T>::displayAll() 
{
  if(isEmpty()) 
    {
    cout << "[Empty]" << endl;
    }
  else
    {
      Node<T> *p;
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
template <class T>
T LL<T>::deleteRear()
{
  if(isEmpty())
    {
      throw underflow();
      //llError("[Error: List is Empty.]");
    }
  else if(count == 1 && front == rear)
    {
      T old = rear -> elem;
      delete rear;
      front = rear = NULL;
      count--;
      return old;
    }
  else
    {
      Node<T>* p = new Node<T>;
      T old = rear -> elem;
      //delete rear;
      for(p = front; p -> next != rear; p = p -> next);
      delete rear;
      rear = p;
      rear -> next = NULL;
      count--;
      return old;
    }
}

template <class T>
void LL<T>::addFront(const T& el)
{
  if(isEmpty())
    {
      front = rear = new Node<T>;
      rear -> elem = el;
      rear -> next = NULL; //new adddition
    }
  else
    {
      Node<T>* p = new Node<T>;
      p -> elem = el;
      p -> next = front;
      front = p;
    }
  count++;
}

template <class T>
LL<T>::LL(const LL<T>& source)
{
  this -> front = this -> rear = NULL;
  this -> count = 0;
  Node<T>* p = source.front;
  while(p != NULL)
    {
      this -> addRear(p -> elem);
      p = p -> next;
    }
}

//*********************** These are the other functions that are due for the upcoming lab ******************************8
template <class T>
bool LL<T>::search(const LL<T>& e)
{
  int na = 0;
  Node<T>* temp = front;
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

template <class T>
void LL<T>::deleteNode(const T& e)
{
  Node<T>* pre;
  Node<T>* del;
  if(isEmpty())
    throw underflow();
    //return;
    //else
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

template <class T>
void LL<T>::addInOrderAscend(const T& e)
{
  Node<T>* p = front;
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
	  Node<T>* newNode = new Node<T>;
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

template <class T>
void LL<T>::printAllReverse()
{
  printAllReverse(front);
}

template <class T>
void LL<T>::printAllReverse(Node<T>* p)
{
  if(p == NULL)
    return;
  else
    {
      printAllReverse(p -> next);
      cout << p -> elem;
    }
}

#endif
