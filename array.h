/*****************************************************
Template prepared by Kazumi Slott
CS211
lab on template functions
This header file provides useful operations on an array
of any data type.

Your name:
*****************************************************/

#include <iostream>
using namespace std;

/********************************************
This function fills the array with data entered from the keyboard.

ar is an array of any data type
n is the number of items entered into ar
********************************************/
template <class T>
void fill(T ar[], int n)
{

  for(int i = 0; i < n; i++)
    {
      cout << "Enter an Item: ";
      cin >> ar[i];
    }
  cout << endl;
}



/********************************************
This function prints the array.

ar is an array of any data type
n is the number of items in ar
********************************************/
template <class T>
void print(T ar[], int n)
{
  for(int i = 0; i < n; i++)
    {
      cout << ar[i] << " ";
    }
  cout << endl;
}




/*******************************************
This function returns the index of the highest value.

ar is an array of any data type.
n is the number of items in ar
*******************************************/
template <class T>
int getHighest(const T ar[], int number)
{
  int highestNumber = 0;
  for(int i = 0; i < number; i++)
    {
      if(ar[highestNumber] < ar[i])
	{
	  highestNumber = i;
	}
    }
  return highestNumber;
}
/*******************************************
This function returns the index of the lowest value.

ar is an array of any data type.
n is the number of items in array
*******************************************/
template <class T>
int getLowest(const T ar[], int number)
{
  int lowestNumber = 0;
  for(int i = 0; i < number; i++)
    {
      if(ar[lowestNumber] > ar[i])
	{
	  lowestNumber = i;
	}
    }
  return lowestNumber;
}

/********************************************
This function returns the average.

ar is an array of any data type.
n is the number of items in ar
********************************************/
template <class T>
double getAvg(const T ar[], int number)
{
  double average;
  double total;
  for(int i = 0; i < number; i++)
    {
      total += ar[i];
    }
  average = total/number;
  return average;
}

/*******************************************
This function stores unique items into an array
and returns the number of the unique items.
  e.g.  If ar contains  9 3 5 3 9 1 9
        uniqAr gets 9 3 5 1
        The function returns 4  
       
ar is the original array of any data type
uniqAr is the array that will have only unique items
n is the number of items in ar
*******************************************/
template <class T>
int unique(const T ar[], T uniqAr[] , int n)
{
  bool unique;
  int counter = 1;
  uniqAr[0] = ar[0];
  for(int i = 0; i < n; i++)
    {
      unique = false;
      for(int m = 0; m < counter; m++)
	{
	  if(ar[i] == ar[m])
	    {
	      unique = true;
	    }
	}
      if(unique == false)
	{
	  uniqAr[counter] = ar[i];
	  counter++;
	}
      unique = false;
    }
  return counter;
//uniqAr in the caller will be filled with only unique numbers

}




/***********************************************
This function sorts the items in ascending order: smallest to largest

array is an array of any data type
N is the number of items in the array
**********************************************/                                                

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//The following function sorts an integer array in ascending order 
//using the selection sort algorithm.
//You need to change this code so it works with an array of any data type.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
template <class T>
void sort(T array[], int N)
{
  int lrgIndx; //the index of the largest value                                                                                               
  T temp; //temporary variable that holds the largest value                                                                                  

  //last is the last index in unsorted portion                                                                                                 
  for(int last = N-1; last >= 1; last--)
    {
      lrgIndx = 0; //assume the first item is the largest                                                                                      
      //find the largest in unsorted portion ([0..last])                                                                                       
      for(int i = 1; i <= last; i++)
        {
          if(array[i] > array[lrgIndx]) //The current item is larger                                                                           
            lrgIndx = i;
        }

      //swap the largest with the last item in the unsorted portion                                                                            
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}


template <class T>
T bubbleSort(T array[], int SIZE)
{
  bool finished = false;
  T temp;
  while(!finished)
    {
      finished = true;
      for(int i = 0; i < SIZE-1; i++)
	{
	  if(array[i] > array[i + 1])
	    {
	      temp = array[i];
	      array[i] = array[i + 1];
	      array[i+1] = temp;
	      finished = false;
	    }
	}
    }
}

template <class T, class T1>
int find(const T array[], int SIZE, const T1& m)
{
  int return1 = -1;
  for(int i = 0; i < SIZE; i++)
    {
      if(array[i] == m)
	{
	  return1 = i;
	}
    }
  return return1;

}

//this is our remove prototype that we are going to be using
template <class T, class T1>
  bool remove(T array[], int num, T1 removed)
{
  int remove = find(array, num, removed);
  if(remove != -1)
    {
      for(int i = remove; i < num - 1; i++)
	{
	  array[i] = array[i + 1];
	}
      return true;
    }
  else
    {
    return false;
    }
}
