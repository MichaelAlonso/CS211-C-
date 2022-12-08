#include <iostream>
#include "myCstring.h" //will be using this from the other program

using namespace std;

void showResult(const char* longwrd, const char* shortwrd, const char* all);

int main()
{
  const char* badAr[4] = {"funky", "idiot", "stinky", "stupid"}; //the bad words sorted
  int l; //this is l for long
  int s = 10; //short will be equal to 10
  char wd[10]; //each word is read into a c-string. A word can have up tp 9 characters because '\0' takes up 1 slot
  char all[111] = ""; //this will have all the words minus bad words separated by "," it is initialized to ""(empty string to start with
  int len; //the length of the word
  char longestWd[10] = "xxxxxxxxx"; //this is going to hold the longest word
  char shortestWd[10] = "xxxxxxxxx"; //this is going to hold the shortest word
  for(int i = 0; i < 10; i++) //this will be now so i can put the words into the program
    {
      cout << "Enter a word: "; //enter word
      cin >> wd; //what we input

      //this will be when we find the bad word
      if(binarySearch(badAr, 0, 3, wd) < 0)
	{
	  //functions from our .h file we are using
	  myStrcat(all, wd);
	  myStrcat(all, " , ");

	  len = myStrlen(wd); //if the word is longer
	  if(len > l)
	    {
	      l = len;
	      myStrcpy(longestWd, wd);
	    }
	  else if(len < s) //if the word is short
	    {
	      s = len;
	      myStrcpy(shortestWd, wd);
	    }
	}
    }
  //this will then show the result of all we inputted
  showResult(longestWd, shortestWd, all);
  return 0;
}

/***************

This function is going to be showing the result for longest, shortest,
and removing all bad words

 *************/

void showResult(const char* longwrd, const char* shortwrd, const char* all)
{
  cout << "The longest word: " << longwrd << endl;
  cout << "The shortest word: " << shortwrd << endl;
  cout << "All words minus bad words: " << all << endl;
}
