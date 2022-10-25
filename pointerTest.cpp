#include <iostream>
using namespace std;

int main()
{
  int* P1; //p1 will point to the integer cell
  int* P2; //p2 will point to the integer cell

  P1 = new int; //a new cell is created and p1 points to it
  P2 = new int; //a new cell is created and p2 points to it

  *P1 = 1; //1 will go into the cell pointed in P1
  *P2 = 2; //2 will go into the cell pointed in P2

  cout << *P1 << endl;
  cout << *P2 << endl;

  delete P2; //this is going to free the cell pointed in P2 and it is now a dangling pointer now
  P2 = P1;

  cout << *P2 << endl;

  delete P1;
  P1 = NULL;
  P2 = new int;

  *P2 = 3;

  cout << *P2 << endl;

  return 0;
}

/*
int main()
{
  int n = 1;
  int* pi;
  double* pf1;
  double* pf2;
  string* ps;

  pi = &n;
  pf1 = new double;
  pf2 = new double;
  ps = new string;

  *pi = 2;
  *pf1 = 10.55;
  *pf2 = 11.55;
  *ps = "Hello";

  cout << "0 " << pi << endl;
  cout << "1 " << pf1 << " " << pf2 << " " << ps << endl;
  cout << "2 " << *pf1 << " " << *pf2 << " " << *ps << endl;

  delete ps;
  ps = new string;
  *ps = "World";

  cout << "3 " << ps << endl;
  cout << "4 " << *ps << endl;

  pf2 = pf1;

  cout << "5 " << pf1 << " " << pf2 << endl;
  cout << "6 " << *pf1 << " " << *pf2 << endl;

  delete pf1;
  pf1 = NULL;

  cout << "7 " << pf1 << " " << pf2 << endl;
  cout << "8 " << *pf2 << endl;
  cout << "9 " << *pf1 << endl;

  return 0;
}
*/
