#ifndef UTILITY_H
#define UTILITY_H

using namespace std;

/**********

This is going to be able to tell if it is a letter or not

*********/

bool isLetter(char character)
{
  //this is going to go through all the letters
  if((character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z'))
    return true; //if it is true
  else
    return false; //if it is not true
}

/**********

This is going to deal with the uppercase

**********/

char toMyUpper(char character)
{
  if(character >= 'a' && character <= 'z')
    //then once it does find the upper
    character = character - ('a' - 'A');
  return character;
}

/************

This function is going to be able to find any of the uppercases

***********/
char myToLower(char character)
{
  //this is going to tell if anyone of it is uppercase
  if(character >= 'A' && character <= 'Z')
    //once it does find the uppercase
    character = character + ('a' - 'A');
  return character;
}

//our endif
#endif
