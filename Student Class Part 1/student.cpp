#include "student.h"
#include "array.h"

Student::Student()
{
  fN = "unknown";
  lN = "unknown";
  gender = 'X';
  numClasses = 0;
}

Student::Student(string fn, string ln, char gn)
{
  fN = fn;
  lN = ln;
  gender = gn;
  numClasses = 0;
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
