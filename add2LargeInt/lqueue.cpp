#include <iostream> // print error message
#include <cstdlib> // exit(1);
#include <cmath>
#include <string> // string error
#include "lqueue.h"

using namespace std;
/******************
This is going to be the constructor where our values will start and allow to use in theprivate so it can be used to access the other functin      
*****************/

LQueue::LQueue() 
{
  front = NULL; //the value that is going to be used in the front
  rear = NULL; //almost the same as front except its the rear
  count = 0; //make sure it knows the count of front and rear change
}

/***************                        
This will be the destructor and its going to be claled automatically for when the classis destroyed         
**************/

LQueue::~LQueue() 
{
  while(!isEmpty()) //this is going to be here for when there are nodes in the memory
    {
      deleteFront(); //is going to delete the front node                   
    }
}

/****************************************
This is going to be the error to display the message                        
******************************************/

void LQueue::queueError(string errorMessage)
{
  cout << errorMessage << endl;
}

/*****************************
To verify if it is empty or not
*******************************/

bool LQueue::isEmpty() 
{
  //if it is empty
  if(front == NULL && rear == NULL) 
    {
    return true;
    }
  else //if there is anything inside
    return false;
}

/*************************** 
This is going to add elements from the rear side of the queue and to see if there is any nodes that will be added, front and rear is going to be used to start and end
***************************/

void LQueue::addRear(el_t el)
{
  //this is going to be used if there are no nodes inside yet
  if(isEmpty())
    {
      front = rear = new Node;
      front -> elem = el;
    }
  else //if there is nodes
    {
      //this is going to add an extra
      rear -> next = new Node;
      //where it will be located
      rear = rear -> next;
      //this is going to be needed to make sure it is inside the element
      rear -> elem = el;
      //the final place where it ends
      rear -> next = NULL;
    }
  //once it is all completed              
  count++;
}

/***********************
will allow the element on front to be found and deleted when called for
************************/

el_t LQueue::deleteFront()
{
  //this is going to use the empty function
  if(isEmpty())
    {
      queueError("The queue is empty. Cannot be deleted");
      //return the number because it is not being used and it is below the count
      return -1;
    }
  //if there is one node or when a node is entered
  else if(count == 1)
    {
      el_t element = front -> elem;
      //it can delete the rear
      delete front;
      //to prevent the memory
      front = rear = NULL;
      //once deleted the heap memory is going to be shorter
      count--;
      return element;
    }
  else //if there is more than one node
    {
      Node* next = front -> next; //node after first node
      el_t element = front -> elem;
      delete front;
      //this is going to make front move down
      front = next;
      count --;
      return element;
    }
}

/***************************
Will be used to output what is inside and allow to know if what we have inside
****************************/

void LQueue::displayAll() 
{
  //if there is no node
  if(isEmpty())
    cout << "[empty]" << endl;
  else //if there are anything inside        
    {
      Node* p;
      p = front;
      //this is when the p is going to the end of the node
      while(p != NULL)
        {
          cout << p -> elem << "";
          p = p -> next;
        }
    }
}

/************************* 
This function is going to be used if there are going to be no nodes for the parameter and is in the public function so it will be accessed and output the numbers
***************************/

void LQueue::printAllReverse()
{
  printAllReverse(front);
}

/************************* 
This function is going to be able to output, but because we have the node, it will be easily accessed since there is a front inside of the function                        
*************************/

void LQueue::printAllReverse(Node* p)
{
  if(p == NULL) //this will be so when p no longer get anywhere else to go inside
    return;
  else //is there more nodes that need to be added
    {
      printAllReverse(p -> next); //this is so to move p to the next              
      cout << p -> elem; //it will be able to store the element of where p is going to be located
    }
}
