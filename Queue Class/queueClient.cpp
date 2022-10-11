/*********************************************************
Template provided by Kazumi Slott

Name: Michael Alonso Ambrocio
This client tests the queue class memeber functions.
********************************************************/
#include <iostream>
using namespace std;
#include "queue.h" //this is going to get the queue.h file

//Using the functions that are made
void showMenu();
void addElem(Queue& q);
void removeElem(Queue& q);


int main()
{
  int input; //integer for our input
  Queue q; //our q for Queue
  el_t el; //char for right now
  
  do{
    showMenu(); //Showing the menu function
    cout << "Selection: ";
    cin >> input; //the input that they put for their option
    switch(input)
      {
      case(1):
	addElem(q); //adding the element
	break;
      case(2):
	removeElem(q); //removing the element
	break;
      case(3):
	cout << q.getFront() << endl; //getting the number that is front
	break;
      case(4):
	q.goBack(); //putting what in the back
	break;
      case(5):
	cout <<q.getSize() << endl; //getting the getsize
	break;
      case(6):
	q.displayAll(); //displaying all that is in at the moment
	break;
      case(7):
	break; //the end of the program
      default:
	cout << "Invalid Input try again" << endl;
	cin.clear();
	cin.ignore();
	break;
      }
	
  }while(input != 7);
  
  return 0;
}


void showMenu()
{
  cout << "1: add a new element" << endl; //(testing add(), isFull())
  cout << "2: remove an element" << endl; // (testing remove(), isEmpty())
  cout << "3: check the front element" << endl; //(testing getFront(), isEmpty())
  cout << "4: go back to the rear" << endl; //(testing goToBack())
  cout << "5: get the number of elements in the queue" << endl; //(testing getSize()) 
  cout << "6: display all the elements in the queue" << endl; //(testing displayAll()) 
  cout << "7: quit program" << endl;
}


/****************************************

This is going to add the element

 ****************************************/
void addElem(Queue& q)
{
  if(q.isFull() == true) //if isFull is true
    {
      cout << "Can't add the queue is full" << endl;
      return;
    }
  char ch;
  cout << "Enter new Element: "; //this is to add a new character
  cin >> ch;
  q.add(ch); //using our add function
}

/****************************************

This is to be able to remove the elem

*****************************************/
void removeElem(Queue& q)
{
  if(q.isEmpty() == true) //if the empty is true
    {
      cout << "Can't remove elements because it is empty" << endl;
      return;
    }
  char removedElement = q.remove(); //using our function that we made in queue.cpp
  cout << removedElement << " has been removed from the queue" << endl;
}
