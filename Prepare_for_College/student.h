#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "price.h" //for college since we are using Price
using namespace std;

const int MAX = 6;

class Student
{
 private:
  string fN;
  string lN;
  char gender;
  int numClasses;
  int classes[MAX];
  int stuID; //this is part of the college lab
  Price balance; //this as well is for the college lab
 public:
  Student();
  Student(string fn, string ln, char gn, int studentID);
  int addCourse(int crn);
  void viewAllCourses()const;
  bool dropCourse(int crn);
  
  //all these functions below are for the college lab
  string getFirstName()const;
  string getLastName()const;
  char getGender()const;
  int getNumClasses()const;
  int getStuID()const;
  int getClassOf(int i)const;
  Price getBalance()const;
  void addFee(int d, int c);
  void reduceFee(int d, int c);
};

#endif
