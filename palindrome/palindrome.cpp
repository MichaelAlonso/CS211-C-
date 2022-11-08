#include <iostream>
#include <string>
#include <fstream>
#include "LL.h" //we are using the file LL.h for this program

using namespace std;

void createLL(LL& a, string sentence);
bool isLetter(char character);
char myToLower(char character);
bool palindrome(LL& palin);

int main()
{
  ifstream fin; //this is the input of the file
  fin.open("palindrome.dat"); //this is for the data file will hold the inputs for this
  
  //if it does not exist
  if(!fin)
    {
      cout << "You must have the right file" << endl;
    }
  //if it does exist
  else
    {
      LL m; //so it can access the header
      string s; //the length is the string
      
      //this is if the file reaches the end
      while(!fin.eof())
	{
	  getline(fin, s); //going to grab everything
	  createLL(m, s); //new sentence
	  m.displayAll(); //display
	  if(palindrome(m) == true) //to get the return type
	    cout << s << " is a palindrome. "  << endl;
	  else
	    cout << s << " is not a palindrome. " << endl;
	}
    }
  fin.close(); //to close it
  return 0;
}

/*************************

This is going to construct a linked list from the string minus the punctuations and spaces with each  node having one letter

 ************************/

void createLL(LL& a, string sentence)
{
  while(!a.isEmpty()) //without this it would say not palindrome after the pop
    {
      a.deleteFront();
    }
  for(int i = 0; i < sentence.length(); i++) //read the string that we give it
    {
      //character is passed and verify it is a character as a string
      if(isLetter(sentence[i]))
	{
	  //this will set the variable so it can be a lower case letter
	  char c = myToLower(sentence[i]);
	  a.addFront(c);
	}
    }
}

/*********************************

isLetter will return zeros if ch is a nonletter otherwise then it returns non-zeros

 *********************************/

bool isLetter(char character)
{
  //this is going to determine if it is a letter
  if((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
    return true; //if it is a character
  else// if not then false
    return false;
}

/********************************

This is going to return it into a lower case

 ********************************/

char myToLower(char character)
{
  //if the character is an uppercase
  if(character >= 'A' && character <= 'Z')
    //this part will then add the uppercase and subtract the value of an lower case 
    character = character + ('a' - 'A');
  return character;
}

bool palindrome(LL& palin)
{
  char front;
  char rear;
  while(!palin.isEmpty()) //if it is empty
    {
      front = palin.deleteFront();
      rear = front;
      if(!palin.isEmpty()) //making sure it is not empty again
	rear = palin.deleteRear();
      //this is going to be if the front is not equal to rear
      if(front != rear)
	return false; //if it is false
    }
  return true; //if it is true 
}
