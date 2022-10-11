/****************************************************
Template written by Kazumi Slott
CS211
selection sort lab

This program has 4 different selection sort functions.
*****************************************************/
#include <iostream>
#include <cstdlib>
#include "array.h"
using namespace std;
//??????? include your array.h

void selectionSort1(int array[], int N);
void selectionSort2(int array[], int N);
void selectionSort3(int array[], int N);
void selectionSort4(int array[], int N);
void fill(int ar[], int number);
void test(int code);

int main()
{
  cout << "------ testing selectionSort1: Ascending moving largest to end  ------" << endl;
  test(1);

  cout << "\n------ testing selectionSort2: Descending moving smallest to end  ------" << endl;
  test(2);

  cout << "\n------ testing selectionSort3: Ascending moving smallest to beginning  ------" << endl;
  test(3);

  cout << "\n------ testing selectionSort4: Descending moving largest to beginning  ------" << endl;
  test(4);

  return 0;
}

//This function fills the array with random numbers between 1 and 100
void fill(int ar[], int number)
{
  for(int i = 0; i < number; i++)
    {
      ar[i] = rand() % 100 + 1;
    }
}



//code = 1 for selectionSort1
//       2 for selectionSort2
//       3 for selectionSort3
//       4 for selectionSort4

void test(int code)
{
  srand(time(0)); // this is to use for our random
  //make a constant SIZE set to 10
  const int SIZE = 10;
  //declare an integer array using SIZE  
  int array[SIZE];
  //fill the array by calling fill()
  fill(array, SIZE);
  //print the array by calling print() in array.h
  print(array,SIZE);
  //create a switch statement here to call a different sort function depending on the code.
  //?????
  switch(code)
    {
    case 1:
      selectionSort1(array, SIZE);
      break;
    case 2:
      selectionSort2(array, SIZE);
      break;
    case 3:
      selectionSort3(array, SIZE);
      break;
    case 4:
      selectionSort4(array, SIZE);
      break;
    }
  //print the array - hopefully the numbers are sorted correctly
  cout << endl;
  print(array, SIZE);
  cout << endl;

}



//this function sorts the numbers in ascending order by moving the largest to the end: smallest to largest
void selectionSort1(int array[], int N) 
{
  int lrgIndx; //the index of the largest value
  int temp; //temporary variable that holds the largest value

  //last is the last index in unsorted part
  for(int last = N-1; last >= 1; last--) 
    {
      lrgIndx = 0; //assume the first item is the largest
      //find the largest in unsorted part ([0..last])
      for(int i = 1; i <= last; i++) 
	{
	  if(array[i] > array[lrgIndx]) //The current item is larger 
	    lrgIndx = i;
	}

      //swap the largest with the last item in the unsorted part
      temp = array[lrgIndx]; 
      array[lrgIndx] = array[last]; 
      array[last] = temp;
    } 
}



//Change this function so it sorts the numbers in descending order by moving the smallest to the end: largest to smallest                                                                    
//You can change the variable names to suit their purposes. 
//The structure of this code shouldn't change.
void selectionSort2(int array[], int N)
{
  int lrgIndx; //this is so it can be able to find the largets index                                                                                                                                               
  int temp; //this is a temporary variable
                                                                                                                                  
  //this loop is so it can sort the function                                                                                                                                                
  for(int last = N-1; last >= 1; last--)
    {
      lrgIndx = 0; //it is set to 0 before it counts the largest number
                                                                                                                                      
      //this loop is going to be used to replace                                                                                                                                      
      for(int i = 1; i <= last; i++)
        {
          if(array[i] < array[lrgIndx]) //the line then gets smaller                                                                                                                          
            lrgIndx = i;
        }

      //to then make sure it goes from largest to smallest                                                                                                                           
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}




//Change this function so it sorts the numbers in ascending order by moving the smallest to the beginning: smallest to largest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort3(int array[], int N)
{
  int smallIndx; //the smallest number in the function                                                                                                                                                                        
  int temp; //the variable temp is temporary                                                                                                                                                                            
  //?????????                                                                                                                                                                                 
  for(int first = 0; first <= N-1; first++)
    {
      smallIndx = N-1; //going tom start at 0 for our small index                                                                                                                                                                   
      //this loop is so we can get our small number                                                                                                                                                                             
      for(int i = N-1; i >= first; i--)
        {
          if(array[i] < array[smallIndx]) //to compare the small number                                                                                                                                            
            smallIndx = i;
        }

      //this is then going to make the numbers from smallest to largest                                                                                                                                                                               
      temp = array[smallIndx];
      array[smallIndx] = array[first];
      array[first] = temp;
    }
}



//Change this function so it sorts the numbers in descending order by moving the largest to the beginning: largest to smallest                                                                
//You can change the variable names to suit their purposes.                                                                                                                                   
//The structure of this code shouldn't change.
void selectionSort4(int array[], int N)
{
  int lrgIndx; //thids is going to be the large index                                                                                                                                                                        
  int temp; //this is our temp variable                                                                                                                                                                            
  //?????????                                                                                                                                                                                 
  for(int last = 0; last <= N-1; last++)
    {
      lrgIndx = N-1; //the large index is going to start at 0                                                                                                                                                                   
      //this is then so it can find the large number in this loop                                                                                                                                                                             
      for(int i = N-1; i >= last; i--)
        {
          if(array[i] > array[lrgIndx]) //if the number is large                                                                                                                                            
            lrgIndx = i;
        }

      //this is so it can have the large number in the front of the order                                                                                                                                                                       
      temp = array[lrgIndx];
      array[lrgIndx] = array[last];
      array[last] = temp;
    }
}












