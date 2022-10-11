#ifndef QUEUE_H //This is how we start when we use our .h file
#define QUEUE_H //this as well we use when we start
#include <string>

typedef char el_t;
const int MAX = 5;

//This is our class that and the name is Queue
class Queue
{
 private:
  el_t elem[MAX];
  int rear; //our rear is a int
  int front; //the front is a int
  int count; //the count is a int
 public:
  Queue(); //this is for our count, front, and count set to 0
  bool isFull()const; //to check if it is full
  bool isEmpty()const; //check to see if it is empty
  void add(el_t element); //this is going to add
  void queueError(std::string errorMessage)const; //this is to display a error message 
  el_t remove(); //going to remove the number in the queue
  el_t getFront()const; //get the number that is front
  void goBack(); //going to put the number back
  int getSize()const; //going to get the size of
  void displayAll()const; //going to display all
};

#endif //this is for the end of the program
