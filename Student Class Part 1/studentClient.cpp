#include <iostream>
using namespace std;
#include "student.h"


int main()
{
  Student s1("Michael", "Alonso", 'M');
  //with addCourse we will be able to see the classes that got added
  s1.addCourse(100);
  s1.addCourse(200);
  s1.addCourse(300);
  s1.addCourse(400);
  s1.dropCourse(200); //this is to show that the class got dropped and wont be displayed in the final result


  cout << "This is showing that the function has worked when adding a class" << endl;
  s1.viewAllCourses();
  return 0;
}
