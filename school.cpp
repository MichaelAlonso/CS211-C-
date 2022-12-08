#include <iostream>

using namespace std;

//------------------ Person Class ----------------------
class Person
{
protected: //this is going to used to access from the inherited class
  static int current_id;
  static int num; //the amount of people that are going to be created
  const int ID; //this is going to be included for everyone
  string firstName; //this is for first name
  string lastName; //this is for the last name
  string SSN; //this is for social security
  string email; //this is for email

public:
  Person(string f = "unknown", string l = "unknown", string s = "000-00-0000", string e = "unknown");
  void printInfo();
  static int getCurrentId();
  static int getNum();
};

int Person::current_id = 1000;
int Person::num = 0;

Person::Person(string f, string l, string S, string e): ID(current_id)
{
  firstName = f;
  lastName = l;
  SSN = S;
  email = e;
  current_id++; //this is going to increment after every person
  num++; //this is going to increment the people that are added or deleted
}

void Person::printInfo()
{
  cout << "Person::printInfo()" << endl;
  cout << "Your ID is " << ID << "\nYour First Name is " << firstName << "\nYour Last Name is " << lastName << "\nYour Social Security Number is " << SSN << "\nYour Email is " << email << endl;

}

int Person::getCurrentId()
{
  return current_id;
}

int Person::getNum()
{
  return num;
}

class Faculty : public Person
{
private:
  int dprtID;
  int year;

public:
  Faculty(string f = "unknown", string l = "unknown", string S = "000-00-0000", string e = "unknown", int d = -1, int y = -1) : Person(f,l,S,e)
  {
    dprtID = d;
    year = y;
  }
  void printInfo()
  {
    cout << "Faculty::printInfo()" << endl;
    Person::printInfo();
    cout << "Your department ID is " << dprtID << "\nThe number of years you attended the school is " << year << endl << endl;
  }
};

class Student : public Person
{
private:
  string major;
  double gpa;
  char grade;
public:
  Student(string f = "unknown", string l = "unknown", string S = "000-00-0000", string e = "unknown", string m = "unknown", double gp = -1.00, char gr = '?') : Person(f,l,S,e)
  {
    major = m;
    gpa = gp;
    grade = gr;
  }
  void printInfo()
  {
    cout << "Student::printInfo()" << endl;
    Person::printInfo();
    cout << "Your major is " << major << "\nYour gpa is " << gpa << "\nYour grade is " << grade << endl << endl;
  }
};

int main()
{
  Faculty f("Kathy", "Ross", "222-33-4444", "kathy@csusm.edu", 100, 2);
  Student s("Tom", "Lopez", "333-44-5555", "tom@csusm.edu", "CS", 3.33, 'J');
  Faculty f2("Mike", "Smith", "111-22-3333", "mike@csusm.edu", 100, 5);
  Student s2("Mike", "Smith", "111-22-3333", "mike@csusm.edu", "CS", 3.25, 'S');

  cout << "------------------------\n1: Faculty" << endl;
  f.printInfo();
  cout << "------------------------" << endl;

  cout << "2: Student" << endl;
  s.printInfo();
  cout << "------------------------" << endl;

  cout << "3: Faculty" << endl;
  f2.printInfo();
  cout << "------------------------" << endl;

  cout << "4: Student" << endl;
  s2.printInfo();
  cout << "------------------------" << endl;

  cout << "There are " << Person::getNum() << " people that are registered and the current id is " << Person::getCurrentId() << endl;

  return 0;
}

