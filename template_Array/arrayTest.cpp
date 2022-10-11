/***************************************************************
CS211
Template prepared by Kazumi Slott
1-28-2020

This program tests array.h
**************************************************************/

#include "array.h"


int main()
{
  //declare const called SZ_I set to 7
  const int SZ_I = 7;
  //declare const called SZ_D set to 3
  const int SZ_D = 3;
  //declare const called SZ_C set to 5
  const int SZ_C = 5;

  //create an integer array that has SZ_I slots
  int arrayInteger[SZ_I];

  //create a double array that has SZ_D slots
  double arrayDouble[SZ_D];
  //create a character array that has SZ_C slots
  char arrayCharacter[SZ_C];

  cout << "------Filling the Integer Array------" << endl;
 
  //call fill with the integer array
  fill(arrayInteger, SZ_I);
  //call fill with the double array
  cout << "------Filling the Double Array------" << endl;  
  fill(arrayDouble, SZ_D);

  //call fill with the character array
  cout << "------Filling the Character Array------" << endl;
  fill(arrayCharacter, SZ_C);


  //call print (with 2 parameters) with the integer array
  print(arrayInteger, SZ_I);

  //call print with the double array
  print(arrayDouble, SZ_D);

  //call print with the character array
  print(arrayCharacter, SZ_C);
  
  //call getHighest with the character array and show the highest value along with its location
  int highest = getHighest(arrayCharacter, SZ_C);
  cout << "The highest is " << arrayCharacter[highest] << " at " << highest << endl;
  //call getLowest with the duoble and show the lowest value along with its location
  int lowest = getLowest(arrayDouble, SZ_D);
  cout << "The lowest is " << arrayDouble[lowest] << " at " << lowest << endl;

  //call getAvg with the integer array and show the returend value
  double average = getAvg(arrayInteger, SZ_I);
  cout << "The average is " << average << endl;

  //call unique with integer array and show unique array and the number of unique numbers
  int uniqueNumber[SZ_I];
  int u = unique(arrayInteger, uniqueNumber, SZ_I);
  print(uniqueNumber, u);
  cout << "\n The total number of unique integers is " << u << endl;
  //call unique with character array and show unique array and the number of unique numbers
  char uniqueChar[SZ_C];
  int uc = unique(arrayCharacter, uniqueChar, SZ_C);
  print(uniqueChar, uc);
  cout << "\n The total number of unique characters is " << uc << endl;
  

  //sort the double array and print it
 sort(arrayDouble, SZ_D);
  print(arrayDouble, SZ_D);
  cout << endl;

  //sort the character array and print it
  sort(arrayCharacter, SZ_C);
  print(arrayCharacter, SZ_C);
  cout << endl;

  return 0;
}
