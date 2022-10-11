/**********************************************
Michael Alonso Ambrocio\
Cs 211
10/5/22
This program is going to evaluate expressions and form using the stack data
***********************************************/

#include <iostream>
#include "stack.h" //this is going to use our stack.h

using namespace std;

//all of the functions that we will be using for our program
bool isOperand(char ch);
int charToInt(char ch);
bool isOperator(char ch);
int doMath(const int operand1, char sign, const int operand2);
bool addStack(const Stack& s);
bool popStack(const Stack& s);

int main()
{
  
  Stack s; //the s is going to be our stack
  bool valid = true; //this is going to set true to run the loop
  string exp; //this is our user input
  int counter = 0; //counter to keep track
  int operand1; //this is our first operand
  int operand2; //this is our second operand
  int result; //the result of both operands and the operators
  
  cout << "Enter Expressions: "; //this is display our message
  cin >> exp; //this is to get our input

  //the loop is then going to check to see if if the input is the operator and operand and going to then convert it into a int and being push into a stack and when it is a operator then we will pop it and be into doMath if it is true

  do
    {
      if(isOperand(exp[counter]) ==  true) //is going to check if it is a number
	{
	  if(addStack(s) == true) //check if the number can be pushed to a stack
	    {
	      s.push(charToInt(exp[counter])); //convert character into integer and push to stack
	    }
	  else //if there is no space then it is going to break the loop
	    {
	      valid = false;
	    }
	}
      else if (isOperator(exp[counter]) == true) //check if the character is +,-,*,/
	{
	  valid = popStack(s);
	  if(valid == true) //if not empty then it will pop the top element 
	    {
	      operand2 = s.pop();
	      valid = popStack(s); //call to check if any other numbers exist
	      if(valid == true) //check to see if the expression is still valid
		{
		  operand1 = s.pop();
		  result = doMath(operand1, exp[counter], operand2);
		  s.push(result); //pushing the result back to stack
		}
	    }
	}
      else //if user does not have a opernad or operatar then false
	{
	  cout << "Error: Invalid item was found (" << exp[counter] << ")" << endl;
	  valid = false; //set to false to break the loop
	}
      counter++; //increment
    }
  while(valid == true && counter < exp.length()); //stack and char are valid
  if(valid = true) //check to see the string and exp are valid
    {
      result = s.pop(); //pop the element 
      if(s.isEmpty() == false) //if the stack is not empty then we have a lot of operands=
	{
	  //error message will display
	  cout << "Error: Too many operands" << endl;
	}
      else //if stack is empty then display
	{
	  cout << " = " << result << endl;
	}
    }
  return 0;
}


/*****************************************
this function will check if the character is an operand or integer
Then when it does if it is an integer then it will return true
char cs is a expr{index} in main
******************************************/
bool isOperand(char ch)
{
  if(ch >= '0' && ch <= '9')
    {
      return true; //this will check if the character is from 0 - 9 return true
    }
  return false;
}

/**************************************
This function is pretty much going to make the character into
an integer
 *************************************/
int charToInt(char ch)
{
  int result = ch - '0';
  return result;
}

/*************************************
This function is going to check if the character is an operator +, -, *, /
and then once it checks it, it will then return true if it is

 ************************************/
bool isOperator(char ch)
{
  //this will be used fore getting our operators
  switch(ch)
    {
    case('+'):
    case('-'):
    case('*'):
    case('/'):
      return true; //will be true if it is any of this 
    break;
    default:
      return false; //if not then it is false
      break;
    }
}

/***********************************
This function will then combine with operands and operators
and then operand2 is going to be the first pop
and then operand1 is the second pop
opt is our operators
 **********************************/
int doMath(const int operand1, char sign, const int operand2)
{
  int result; //this is going to create integer variable that is going to hold two operators
  switch(sign)
    {
    case('+'): //going to add
      result = operand1 + operand2;
      break;
    case('-'):  //going to subtract
      result = operand1 - operand2;
      break;
    case('*'): //going to multiple
      result = operand1 * operand2;
      break;
    case('/'): //going to divide
      result = operand1 / operand2;
      break;
    }
  return result;
}

/***********************************
This function is going to check when there is a space in the stack
and it is pushed and return true if there is and false if there isnt any space

 **********************************/
bool addStack(const Stack& s)
{
  if(s.isFull() == true) //this is going to check if the stack is full
    {
      //This is going to return this message if the stack is full
      cout << "Error: Expression is too long" << endl;
      return false; //return false if they cant add to stack
    }
  return true; //if it can add
}


/**********************************
This function is going to check if the element can be popped
and display error message 
**********************************/
bool popStack(const Stack& s)
{
  if(s.isEmpty() == true)
    {
      //this is going to display the message if it is true
      cout << "Error: Not enough operands" << endl;
      return false;
    }
  return true;
}
