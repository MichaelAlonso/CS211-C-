#ifndef LQUEUE_H
#define LQUEUE_H
#include <string>
typedef int el_t;
using namespace std;

struct Node {
  el_t elem;
  Node* next;
};

class LQueue {
 private:
  Node* front;
  Node* rear;
  int count;
  void queueError(string errorMessage);
  void printAllReverse(Node* p);
 public:
  LQueue();
  ~LQueue();
  
  void addRear(el_t);
  el_t deleteFront();
  bool isEmpty();
  void displayAll();
  void printAllReverse();
};

#endif
