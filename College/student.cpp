using namespace std;
#include "student.h"
#include "array.h"
#include "price.h"

Student::Student()
{
  fN = "unknown";
  lN = "unknown";
  gender = 'X';
  stuID = -1; //this is part of the college lab
  numClasses = 0;
}

Student::Student(string fn, string ln, char gn, int id)
{
  fN = fn;
  lN = ln;
  gender = gn;
  numClasses = 0;
  stuID = id; //part of the college lab
}

int Student::addCourse(int crn)
{
  int stuff = find(classes, MAX, crn);
  if(numClasses >= MAX)
    return -1;
  if(stuff != -1)
    return 0;
  else
    {
      classes[numClasses++] = crn;
      return 1;
    }

}

void Student::viewAllCourses()const
{
  print(classes, numClasses);
}

bool Student::dropCourse(int crn)
{
  if(remove(classes, numClasses, crn))
    {
      numClasses--;
      return true;
    }
  else
    return false;
}

//These next 5 functions below are for college lab
string Student::getFirstName()const
{
  return fN;
}

string Student::getLastName()const
{
  return lN;
}

char Student::getGender()const
{
  return gender;
}

int Student::getNumClasses()const
{
  return numClasses;
}

int Student::getStuID()const
{
  return stuID;
}

int Student::getClassOf(int i)const
{
  find(classes, MAX, i);
  return classes[i];
}

Price Student::getBalance()const
{
  return balance;
}

void Student::addFee(int d, int c)
{
  Price p(d,c);
  balance = balance + p;
}

void Student::reduceFee(int d, int c)
{
  Price p(d,c);
  balance = balance - p;
}
