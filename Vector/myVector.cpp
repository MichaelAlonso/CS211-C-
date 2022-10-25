#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
using namespace std;

template <class T>
class myVector
{

private:
  T* ar;
  int num; 
public:
  myVector();
  ~myVector();
  void push_back(const T& e);
  int size() const;
  T& operator[](int index);
  void erase(int index);
  void insert(int index, const T& e);
};

//This is going to be necessary when using the template class T
template <class T>
//always use T even if it is not being used
myVector<T>::myVector()
{
  ar = NULL;
  num = 0;
}

//This is going to make sure to delete the array and so there is also no memory leaks as well
template <class T>
myVector<T>::~myVector()
{
  if(ar!= NULL)
    delete[] ar;
}


template <class T>
//we need the const and the pass by value so e isnt going to be a larger value
void myVector<T>::push_back(const T& e)
{
  T* array = new T[num + 1];
  //num is going to be the size of the array
  for(int i = 0; i < num; i++)
    {
      //the left hand side is a new array while the right side is the original array
      *(array + 1) = *(ar + 1);
    }
  //now e is going to be the value to have all of them copied inside the array
  *(array + num) = e;
  if( ar != NULL)
    {
      //this is going to make sure that it is deleted so none of the memory leaks happens
      delete []ar; 
    }
  ar = array;
  num++;

}

//this function will make sure to record the elements that are in the array and used in many functions
template <class T>
int myVector<T>::size()
{

  return num;

}

//this is operator overload function that is used with [] and be used in in order for it to get the function to make sure it works 
template <class T>
T& myVector<T>::operator[](int index)
{
  //if it is less than the value of numbers that are in the array
  if(index < num)
    //the pointer array is going to be added 
    return *(ar + index);
  else
    throw "invalid index";
  //it will be return back to ar[index]
}

//This is going to erase and be used to take out the functions that are inside the array

template <class T>
void myVector<T>::erase(int index)
{
  if(index > (num - 1))
    cout << "Index is invalid" << endl;
  else
    {
      T* ar2 = new T[num];
      for(int i = 0; i < index; i++)
	{
	  *(ar2 + i) = *(ar + i);
	}
      for(int i = index; i < (num + 1); i++)
	{
	  *(ar2 + i) = *(ar + (i + 1));
	}
      if(ar != NULL)
	{
	  delete []ar;
	  ar = ar2;
	  num--;
	}
    }
}

template <class T>
void myVector<T>::insert(int index, const T& e)
{
  if(index > num)
    {
      cout << "Index is invalid." << endl;
    }
  else
    {
      t* ar2 = new T[num + 1];
      for(int i = 0; i < num; i++)
	{
	  *(ar2 + i) = *(ar + i);
	}
      num++; 
      T temp1 = *(ar2 + index);
      for(int i = index; i < num; i++)
	{
	  T temp2 = *(ar2 + (i + 1));
	  *(ar2 + (i + 1)) = temp1;
	  temp1 = temp2;
	}
      *(ar + index) = e;
      if(ar != NULL)
	{
	  delete []ar;
	  ar = ar2;
	}
    }
}

template <class T>
void print(myVector<T>& v)//this outputs the following
{
  for(int i = 0; i < v.size(); i++)
    {
      cout << "[" << v.ar[i] << "]";
    }
  cout << endl;
}

int main() 
{
  myVector<int> v;//use any data type
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.print(v);
  v.erase(1);
  v.erase(2);
  //test myVector functions
  //Call push_back() multiple times
  //Call print() to show all the elements in the vector
  return 0;
}
template <class T>
void print(myVector<T>& v)//this outputs the following
{
  for(int i = 0; i < v.size(); i++)
    cout << "[" << v.ar[i] << "]";
  cout << endl;
}
#endif
