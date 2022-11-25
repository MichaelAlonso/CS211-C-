#include <iostream>
#include <cstdlib> //for rand()
#include "LL.h"
#include <fstream>
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
  void inOrderPrint(node* p);
  void preOrderPrint(node* p);
  void postOrderPrint(node* p);
  void destroy(node* p);
  int getMaxLength(node* p);
  bool searchRec(node* p, el_t e);
  int getNumNodesBetween(node* p, el_t min, el_t max);
  void printNodesBetween(node* p, el_t min, el_t max);
public:
  BST();
  ~BST();
  void insertNode(el_t);
  bool search(el_t e);
  void inOrderPrint();
  void preOrderPrint();
  void postOrderPrint();
  int getMaxLength();
  bool searchRec(el_t e);
  int getNumNodesBetween(el_t min, el_t max);
  void printNodesBetween(el_t min, el_t max);
};

BST::BST()
{
  root = NULL;
}

BST::~BST()
{
  destroy(root);
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

void BST::inOrderPrint()
{
  inOrderPrint(root);
}

void BST::inOrderPrint(node* p)
{
  if(p == NULL)
    return;
  inOrderPrint(p -> left);
  cout << p -> elem << "-->";
  inOrderPrint(p -> right);

}

void BST::preOrderPrint()
{
  preOrderPrint(root);
}

void BST::preOrderPrint(node* p)
{
  if(p == NULL)
    return;
  cout << p -> elem << "-->";
  preOrderPrint(p -> left);
  preOrderPrint(p -> right);
}

void BST::postOrderPrint()
{
  postOrderPrint(root);
}

void BST::postOrderPrint(node* p)
{
  if(p == NULL)
    return;
  postOrderPrint(p -> left);
  postOrderPrint(p -> right);
  cout << p -> elem << "-->";
}

void BST::destroy(node* p)
{
  if(p == NULL)
    return;
  destroy(p -> left);
  destroy(p -> right);
  cout << p -> elem << "-->";
  delete p;
}

int BST::getMaxLength()
{
 return getMaxLength(root);
}

int BST::getMaxLength(node* p)
{
  if(p == NULL)
    return 0;
  else
    {
      int num1;
      int num2;
      num1 = getMaxLength(p -> left) + 1;
      num2 = getMaxLength(p -> right) + 1;
      if(num1 >= num2)
	return num1;
      if(num1 <= num2)
	return num2;
    }
}

bool BST::searchRec(el_t e)
{
  return searchRec(root, e);
}

bool BST::searchRec(node* p, el_t e)
{
  if(p == NULL)
    return false;
  else
    {
      if(p -> elem == e)
	return true;
      else if(e < p -> elem)
	searchRec(p -> left, e);
      else if(e > p -> elem)
	searchRec(p -> right, e);
    }
}

int BST::getNumNodesBetween(el_t min, el_t max)
{
  return getNumNodesBetween(root, min, max);
}

int BST::getNumNodesBetween(node* p, el_t min, el_t max)
{
  if(p == NULL)
    return 0;
  else if(p -> elem > min && p -> elem < max) //this is going to count root and numbers from left to right
    return 1 + getNumNodesBetween(p -> left, min, max) + getNumNodesBetween(p -> right, min, max);
  else
    //retruns the value not in the range
    return getNumNodesBetween(p -> left, min, max) + getNumNodesBetween(p -> right, min, max);
}

void BST::printNodesBetween(el_t min, el_t max)
{
  cout << "------------- The Numbers Between " << min << " and " << max << " found in the tree are ------------------------" << endl;
  printNodesBetween(root, min, max);
  cout << endl;
}

void BST::printNodesBetween(node* p, el_t min, el_t max)
{
  if(p == NULL)
    return;
  //the nodes traverses the tree from the left
  printNodesBetween(p -> left, min, max);
  //when it is inside the range
  if(p -> elem > min && p -> elem < max)
    cout << p -> elem << "--->";
  printNodesBetween(p -> right, min, max);
}

int main()
{
  /*************************************** first BST Lab *********************
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

  *****************************************************************************/
  /********************* second BST lab ******************************
  BST b;
  
  b.insertNode(5);
  b.insertNode(8);
  b.insertNode(3);
  b.insertNode(9);
  b.insertNode(6);
  b.insertNode(1);
  b.insertNode(0);
  b.insertNode(4);
  b.insertNode(7);
  b.insertNode(20);

  cout << "\n--------------------- getMaxLength --------------------------" << endl; 
  cout << b.getMaxLength();

  cout << endl;

  cout << "\n---------------------- search Rec ----------------------------" << endl;
  cout << b.searchRec(20);

  cout << endl;

  cout << "---- Print all elements using the in-order traversal -----" << endl;
  b.inOrderPrint();

  cout << endl;

  cout << "---- Print all elements using the pre-order traversal -----" << endl;
  b.preOrderPrint();
  
  cout << endl;

  cout << "---- Print all elements using the post-order traversal -----" << endl;
  b.postOrderPrint();
  
  cout << endl;

  cout << "\n--- destructor gets called when b goes out of scope here ---" << endl;
  *******************************************/

  //------------------------------- Homework BST ------------------------------
  BST b; //this is going to be the class object
  ifstream fin; //this is used to check the value inside the date file bst.dat
  fin.open("bst.dat");
  int min, max, value; //our ints of max, min and value

  //enter the min
  cout << "Enter min: ";
  cin >> min;

  //enter the max
  cout << "Enter max: ";
  cin >> max;
  
  //this is going to be able to recoginze the file or not
  if(!fin)
    cout << "File is not recognized" << endl;
  else
    {
      //this is going to be the input of the value of the file
      fin >> value;
      //this will be inside the file
      while(fin)
	{
	  //insert the node that is from the ifstream
	  b.insertNode(value);
	  fin >> value;
	}
      //display the amount of nodes that there is
      cout << "----------- The Number of nodes between " << min << " and " << max << " is " << b.getNumNodesBetween(min, max) << " /n"<< endl;
      b.printNodesBetween(min, max);
      cout << endl;
    }
  return 0;
}
