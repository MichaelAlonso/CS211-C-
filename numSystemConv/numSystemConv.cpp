/***************************************************************************
CS211
Template prepared by Kazumi Slott 
Your name: Michael Alonso Ambrocio

Program description: This program is going
to take a number from 1 to 999,999 and be able to convert this from binary, octet, and hexadecimal
***************************************************************************/
#include <iostream>
using namespace std;
#include "/cs/slott/cs211/checkInput.h"
#include "stack.h" //this is going to get from my stack.h file

//this is the functions that we made below
int getBase();
char convertToChar(int n);
void convertRec(int n, int b);
void convertStack(int n, int b);

int main()
{
  int dec;
  int base;

  cout << "Enter a number in base 10: ";

  //get a decimal number by calling getData in checkInput.h. Accept a numer 
  //between 1 and 999999.
  dec = getData(1, 999999, "Enter a number between 1 and 999999. Enter again: ");

  //get a base (2, 8 or 16) by calling getBase
  base = getBase();

  cout << "----------- Using recursion ---------------" << endl;
  //call convertRec to show the number in the base number system of the user’s choice
  convertRec(dec, base);

  cout << endl;

  cout << "----------- Using a stack ---------------" << endl;
  //Call convertStack to show the number in the base number system of the user’s choice
  convertStack(dec, base);

  cout << endl;
  return 0;
}

/****************************************************************************
This function asks for a number system to which a decimal number is converted, either 2, 8 or 16.
It rejects bad inputs other than 2, 8 or 16.
It returns either 2, 8 or 16
****************************************************************************/
int getBase()
{
  int input; //this is to be able to get the number the person will use
  cout << "Enter a base to convert the base 10 to number to: ";
  cin >> input; //this is going to be the user input
  
  while(input != 2 && input != 8 && input != 16)
    {
      cin.clear();
      cin.ignore(); //this is going to be used so we can avoid infinite loop
      cout << "Invalid Base. Enter 2,8,16 base: ";
      cin >> input; //the user input
    }
  return input; //this is going to return back the input
}

/****************************************************************************
This function receives an integer between 0 and 15 and returns the character.
If n = 0 .. 9, it returns '0' .. '9'
If n = 10 .. 15, returns 'A' .. 'F'

n is an integer between 0 and 15
****************************************************************************/
char convertToChar(int n)
{
  char character; //this is for character
  if(n < 10) //if it is less than 10 then we return the same number 
    {
      //48 is the ascii value of 0 and add the decimal to the character ascii code to the number
      return character = 48 + n;
    }
  //run if the decimal is greater than 9
  return character = 55 + n;
}

/***************************************************************************
This is a <<recursive>> function to convert a decimal number to a different number system and print it.

n is a decimal number
b is a number system to which n is converted, either 2, 8 or 16
***************************************************************************/
void convertRec(int n, int b)
{
  if(n == 0) //going to return before we hit the switch statement
    {
      return;
    }
  switch(b) //n is going to change depending on the base type and using a switch statement
    {
    case(2):
      convertRec(n/2, b); //calling function dividing decimal by half
      cout << n % 2; //print number, this will return 0 or 1 for binary
      break;
    case(8):
      convertRec(n/8, b); //divide 8 to convert to octet
      cout << n % 8; //print octate value since its finding the remainder
      break;
    case(16):
      convertRec(n/16, b); //dividing by 16 since its hexadecimal
      cout << convertToChar(n % 16); //calling this since its a hexadecimal print out
      break;
    }
}

/**************************************************************************
This function uses a stack to convert a decimal number to a different number system and prints it.
This is not a recursive function.

n is a decimal number
b is a number system to which n is converted, either 2, 8 or 16
**************************************************************************/
void convertStack(int n, int b)
{
  Stack s; //using our stack
  while(n > 0) //the decimal is greater then zero and we go to a switch statement pushing back value
    {
      switch(b)
	{
	case(2): //if it is 2 then push the modulo into the stack
	  s.push(n % 2);
	  n /= 2; //dividing the decimal and go till decimal hits zero
	  break;
	case(8): //push the remainder of n % 8 and divide it by 8
	  s.push(n % 8);
	  n /= 8;
	  break;
	case(16): //the same thing as the last two case functions
	  s.push(n % 16);
	  n /= 16;
	  break;
	}
    }
  if(b == 16) //if base is 16 then convert the decimal to character
    {
      while(!s.isEmpty()) //stack is not empty then we will pop the top
	{
	  cout << convertToChar(s.pop()); //convert decimal to character and display top element
	}
    }
  else //if it is not 16 then we dont convert
    {
      while(!s.isEmpty()) //is not empty then we pop the top element and display
	{
	  cout << s.pop();
	}
    }
}
