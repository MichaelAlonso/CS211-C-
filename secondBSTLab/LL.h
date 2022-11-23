#ifndef LL_H
#define LL_H
#include <string>

using namespace std;
typedef int el_t; //make sure to change it back to int 
struct Node {
  el_t elem;
  Node* next;
};

class LL 
{
 private:
  Node* front;
  Node* rear;
  int count;
  void llError(string errorMessage);

 public:
  LL();
  ~LL();
  
  void addRear(el_t el);
  el_t deleteFront();
  bool isEmpty();
  void displayAll();
  
  //the functions for the next part of the lab using LL
  el_t deleteRear();
  void addFront(el_t el); 
  LL(const LL& source);

  //moreOnLL functions
  bool search(el_t e);
  void deleteNode(el_t e);
  void deleteNodes(el_t e); //this is extra credit if i have time ill work on it
  void addInOrderAscend(el_t e);
  void addInOrderDescend(el_t e); //this is extra credit if i have time ill work on it
};

#endif
