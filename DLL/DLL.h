#ifndef DLL_H //instead of LL_H it is noe DLL_H
#define DLL_H
#include <string>

typedef int el_t; //from the last hw assigntment change it back to int
using namespace std;

struct Node {
  el_t elem;
  Node* next;
  Node* prev; //this is the new Node that we are adding
};

class DLL //this is now DLL so we change everything from LL to DLL
{
 private:
  Node* front;
  Node* rear;
  int count;
  void llError(string errorMessage);

 public:
  DLL();
  ~DLL();
  
  void addRear(el_t el);
  el_t deleteFront();
  bool isEmpty();
  void displayAll();
  
  //the functions for the next part of the lab using LL
  el_t deleteRear();
  void addFront(el_t el); 
  DLL(const DLL& source);

  //moreOnLL functions
  bool search(el_t e);
  void deleteNode(el_t e);
  void deleteNodes(el_t e); //this is extra credit if i have time ill work on it
  void addInOrderAscend(el_t e);
  void addInOrderDescend(el_t e); //this is extra credit if i have time ill work on it

  //this is the new function we are adding for the lab DLL
  void printAllReverseDLL();
};

#endif
