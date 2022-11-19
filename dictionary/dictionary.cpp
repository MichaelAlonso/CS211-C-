#include <iostream>
#include <string>
#include <fstream>
#include "LL.h"
#include "utility.h"

using namespace std;

//these are the functions that we will be using
void buildLL(LL& dictionary);
string stripStr(string wd);
void removeBadWords(LL& badWord);
void outputToFile(LL& a);

int main()
{
  LL m;

  buildLL(m);
  removeBadWords(m);

  m.displayAll();
  outputToFile(m);
  


  return 0;
}

/***********************

This is the first function that we are making and will be used to help with LL

 ***********************/

void buildLL(LL& dictionary)
{
  string word; //this is for word
  string temp; //this is for our temporary
  ifstream fin; //to make a file
  //string file; //the filename
  
  //file = "essay.txt"; //this is for the filename that is anme essay.txt that we made
  fin.open("essay.txt"); //to be able to open the file
  //fin >> word; //this is so it can use word

  while(fin) //when the file is being used
    {
      fin >> word;
      temp = stripStr(word); 
      if(!dictionary.search(temp))
	dictionary.addInOrderAscend(temp); //this will be calling the function from LL
    }
  fin.close(); //to be able to close the file
}

/*************************

This function is going to be able to strip the letters 

*************************/

string stripStr(string wd)
{
  string word = ""; //this is going to be what word equals to
  for(int i = 0; i < wd.length(); i++) //the length of the word
    {
      if(isLetter(wd[i]))
	{
	  word += myToLower(wd[i]); 
	}
    }
  return word; //this is going to be able to return back to word
}

/***********************************

This function is going to make sure to remove the bad word

 ***********************************/

void removeBadWords(LL& badWord)
{
  string bad; //this is going to make the string for badword
  string file = "bad.txt"; //this is going to be the string file that will be for the bad words
  ifstream fin;
  fin.open("bad.txt"); //being able to open the file

  while(fin)
    {
      fin >> bad;
      while(badWord.search(bad))
	badWord.deleteNode(bad);
    }
  fin.close(); //this is now going to close the file
}

/********************************

This function is going to be able to output the file

 *******************************/

void outputToFile(LL& a)
{
  string word = a.deleteFront(); //this is going to set the string
  ofstream fout; //ofstream is going to be fout
  
  string nameOfFile = "./dictionary/?.txt"; //this is for the file named dictionary
  nameOfFile[13] = toMyUpper(word[0]); //change to an uppercase
  fout.open(nameOfFile.c_str()); //be opening the file
  while(!a.isEmpty())
    {
      if(toMyUpper(word[0]) == nameOfFile[13])
	{
	  //this is going to output it into the file
	  fout << word << endl;
	}
      else
	{
	  fout.close(); //going to close last file
	  nameOfFile[13] = toMyUpper(word[0]);
	  fout.open(nameOfFile.c_str());
	  fout << word << endl;
	}
      word = a.deleteFront();
    }
  fout.close(); //this is going to close the file
}
