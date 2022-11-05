#include <iostream>
#include <string>
#include "lqueue.h"                      
//#include "LL_T.h"
using namespace std;

//These are our functions that we are adding in this
void createReverseLL(LQueue& l, const string& s); //<int>                         
void addLLs(LQueue& l1, LQueue& l2, LQueue& total);


int main()
{
  string n1, n2; //this is the integer

  //this is going to be where we ask for the numbers
  cout << "Enter a posisitve number: ";
  cin >> n1;
  cout << "Enter another positive number: ";
  cin >> n2;
  //this is going to be our l1

  LQueue l1;
  createReverseLL(l1, n1);
  //this is going to be our l2
  LQueue l2;
  createReverseLL(l2, n2);

  //this is our display all that is going to display it
  l1.displayAll();

  cout << " + " ;
  //this is our display all that is going to display it
  l2.displayAll();

  cout << " = " ;
  //the total is going to be used with LQueue
  LQueue total;
  //using our function and applying those three things we used
  addLLs(l1, l2, total);
  //now will display everything so far
  total.displayAll();
  cout << endl;

  //this will be our second one to show as well the result
  cout << n1 << " + " << n2 << " = ";

  total.printAllReverse();
  cout << endl;

  return 0;
}

//this is for our createReverseLL function
void createReverseLL(LQueue& l, const string& s)
{
  for(int i=s.size() - 1; i >= 0; i--)
    {
      int temp = (int)s[i] - 48;
      l.addRear(temp);
    }
}

//this is the addLL function for our program
void addLLs(LQueue& l1, LQueue& l2, LQueue& total)
{
  int sum, n1, n2; //the numbers
  int carry = 0; //starts at 0
  while(!l1.isEmpty() || !l2.isEmpty())
    {
      if(l1.isEmpty())
        //the n1 is going to equal 0                
        n1 = 0;
      else
	{
        n1 = l1.deleteFront();
	}
      if(l2.isEmpty())
        //n2 is set to 0
        n2 = 0;
      else
        //n2 is going to equal to this
        n2 = l2.deleteFront();
      //the sum is going to equal n1 and n2 and carry
      sum = n1 + n2 + carry;
      //if the sum is greater than or less than 10                   
      if (sum >= 10)
	{
        //the sum is going to be this and the % is the remainder
	  sum = sum % 10;
	  carry = 1; //carry is set to 1                 
	}
      else
        carry = 0; //the carry is set to 0
      total.addRear(sum);
    }
  //this is so if the it is more than 1                       
  if (carry >= 1)
    total.addRear(carry);
}
