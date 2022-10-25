/******************************
Kazumi Slott
CS211

Test client to prep for college.
******************************/

#include <iostream>
using namespace std;
#include "student.h"
#include "array.h"

void addCourseToStudent(Student& s, int crn);
void print(const Student& s);
bool operator==(const Student& s, int id ) ;

int main()
{
  Student s1("Kathy", "Ross", 'f', 1000);
 
  //Create another student with Mike, Smith, m                                                                               
  Student s2("Mike", "Smith", 'm', 1001);

  //creating one more student using the default constructor    
  Student s3;

  //add 111 to Kathy                                                                                                         
  addCourseToStudent(s1, 111);
  cout << endl;

  //add 111 to Mike                                                                                                          
  addCourseToStudent(s2, 111);
  //add 222 to Mike                                                                                                          
  addCourseToStudent(s2, 222);
  //try to add 222 to Mike                                                                                                   
  addCourseToStudent(s2, 222);
  //add 333 to Mike                                                                                                          
  addCourseToStudent(s2, 333);
  //add 444 to Mike                                                                                                          
  addCourseToStudent(s2, 444);
  //add 555 to Mike                                                                                                          
  addCourseToStudent(s2, 555);
  //add 666 to Mike                                                                                                          
  addCourseToStudent(s2, 666);

  //Show each student's info                                                                                                 
  cout << "\n----- s1 ----" << endl;
  print(s1);
  cout << "\n----- s2 ---" << endl;
  print(s2);
  cout << "\n----- s3 ---" << endl;
  print(s3);


  cout << "\n1 " << s1.getBalance() << endl;
  s1.addFee(1, 99);
  cout << "2 " << s1.getBalance() << endl;
  s1.reduceFee(0, 50);
  cout << "3 " << s1.getBalance() << endl;

  Student ar[3];
  ar[0] = s1; 
  Student s10("Mike", "Smith", 'm', 2000);
  ar[1] = s10;
  Student s20("Matthew", "Ross", 'm', 3000);
  ar[2] = s20;

  cout << "Mike found at " << find(ar, 3, 2000);

  remove(ar, 3, 2000); //removing the student with id 2000

  cout << endl;
  for(int i = 0; i < 2; i++) //the array has 2 students. Kathy and Matthew students.
    {
      cout << "At index " << i << "----" << endl;
      print(ar[i]);
    }


  return 0;
}

  
//returns true if the student has id, false otherwise.
bool operator==(const Student& s, int id ) 
{
  if(s.getStuID() == id)
    return true;
  else
  return false;
}

void addCourseToStudent(Student& s, int crn)
{
  s.addCourse(crn);
}

void print(const Student& s)
{
  cout << "first name: " << s.getFirstName() << endl;
  cout << "last name: " << s.getLastName() << endl;
  cout << "gender: " << s.getGender() << endl;
  cout << "stu id: " << s.getStuID() << endl;
  cout << "num classes: " << s.getNumClasses() << endl;

  cout << "Courses: ";
  for(int i = 0; i < s.getNumClasses(); i++)
    cout << s.getClassOf(i) << " ";

  cout << endl;
}
