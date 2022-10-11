#ifndef STUDENT_H
#define STUDENT_H

#include <string>
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
 public:
  Student();
  Student(string fn, string ln, char gn);
  int addCourse(int crn);
  void viewAllCourses()const;
  bool dropCourse(int crn);
};

#endif
