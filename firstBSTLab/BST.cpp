#include <iostream>
#include <cstdlib> //for rand()
#include "LL.h"
using namespace std;

typedef int el_t;

class node
{
  friend class BST;
private:
  el_t elem;
  node* right;
  node* left;
public:
  node(el_t e){elem = e; right = NULL; left = NULL;}; //implement the constructor inside the class definition
};

class BST
{
private:
  node* root;
  void insertNode(node*&, el_t);
public:
  BST();
  void insertNode(el_t);
  bool search(el_t e);
};

BST::BST()
{
  root = NULL;
}

void BST::insertNode(el_t e)
{
  insertNode(root, e);
}

void BST::insertNode(node*& p, el_t e)
{
  if(p == NULL)
    p = new node(e);
  else if(e < p->elem)
    insertNode(p->left, e);
  else
    insertNode(p->right, e);
}

bool BST::search(el_t e)
{
  //Don't use recursion. Use a loop.
  //You want to know how many times it loops to find e.
  //declare a counter. 
  node* temp = root;
  int count = 0;
  while(temp != NULL)
    {
      count++;
      if(temp -> elem == e)
	{
	  cout << count << " nodes checked \n FOUND" << endl;
	  return true;
	}
      else if(e < temp -> elem)
	temp = temp -> left;
      else if(temp -> elem < e)
	temp = temp -> right;
    }
  cout << count << " nodes checked \n NOT FOUND" << endl;
  return false;
  //display the counter
}

int main()
{
  srand(time(0)); //you need to include cstdlib
  BST b;
  
  LL l;
  int key;
  cout << "What number do you want to search for? ";
  cin >> key;

  for(int i = 0; i < 10000; i++)
    {
      int random = rand() % 10000 + 1;
      b.insertNode(random);
      l.addRear(random);
    }

  cout << "BST *************************" << endl;
  b.search(key);

  cout << "LL************************" << endl;
  l.search(key);

  return 0;
}
