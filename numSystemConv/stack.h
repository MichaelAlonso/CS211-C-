#ifndef STACK_H
#define STACK_H
#include <string>

using namespace std;
typedef int el_t;
const int MAX = 30;

class Stack
{

 private:
  el_t names[MAX];
  int top; 
  void stackError(string errorMessage)const;
 public:
  Stack(); //this is going to be our default constructor
  bool isEmpty()const;
  bool isFull()const;
  void push(el_t item);
  el_t pop();
  el_t topElem()const;
  void clearIt();
  void displayAll()const;
};

#endif
