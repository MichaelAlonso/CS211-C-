#ifndef MYCSTRING_H
#define MYCSTRING_H

#include <iostream>

using namespace std;

/********************

This function is from the 9-1 lecture notes this will be so we can get the
length

 ********************/

int myStrlen(const char* cstr)
{
  int i; //i is going to be used for the loop
  for(i = 0; cstr[i] != '\0'; i++);
  return i;
}

void myStrcpy(char* dest, const char* source)
{
  int i = 0; //same thing as the myStrlen
  for(i = 0; source[i] != '\0'; i++)
    {
      dest[i] = source[i]; //dest is going to equal to source
    }
  dest[i] = '\0'; //will then be '\0'
}

void myStrcat(char* dest, const char* source)
{
  //all of these are going to be set to 0
  int d = 0;
  int i = 0;
  int j = 0;

  //move d to the end of the dest
  for(d = 0; dest[d] != '\0'; d++) 
    {
    }
  //now for i and d
  for(i = 0; source[i] != '\0'; i++, d++)
    {
      dest[d] = source[i]; //what dest is going to equal
    }
  //copy each character from the source to dest

  dest[d] = '\0'; //placing '\0'
}

int myStrcmp(const char* cstr1, const char* cstr2)
{
  for(int i = 0; cstr1[i] != '\0' || cstr2[i] != '\0'; i++)
    {
      if(cstr1[i] != cstr2[i])
	return cstr1[i] - cstr2[i];
    }
  return 0;
}

/**************

this is going to be the binarySearch function for the program

 **************/
int binarySearch(const char ** badAr, int a, int b, char* c)
{
  int n; //n is set to an integer
  while(a <= b) //b is set greater or equal to
    {
      n = a + (b - a) + 1/2;
      if(myStrcmp(badAr[n], c) == 0)
	return n;
      if(myStrcmp(badAr[n], c) < 0)
	{
	  a = n + 1; //this will then add 1
	}
      else
	{
	  b = n - 1; //this will then subtract
	}
    }
  return -1;
}

#endif
