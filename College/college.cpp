#include <iostream>
#include <fstream>
#include <cstdlib> //for atoi() <-- you might not use this
using namespace std;
#include "/cs/slott/cs211/checkInput.h"
#include "price.h"
#include "student.h"
#include "array.h"

const int SIZE = 100; //size of the array
const int START = 100000;//student id starts at 100000
const int PASSWORD = 123; //password for admission's office 
const int PRIME1 = 31; //used to calculate a student's password
const int PRIME2 = 5;

int showMenu();
int showAdmMenu();
int showStuMenu();
void addStu(Student ar[], int& n, int& stuID);
void showStuInfo(const Student& s);
void allStuInfo(const Student ar[], const int n);
bool operator==(const Student& s, int id);
void removeStu(Student ar[], int& n);
void addStuFromFile(Student ar[], int& n, int& id);
void addCourse(Student& s);
void dropCourse(Student& s);
void makePayment(Student& s);
void viewStuInfo(Student ar[], int& counter);
int verifyStu(Student ar[], int& counter, int studentID);

int main()
{
  Student ar[SIZE];
  int count = 0; //the number of students in the array
  int id = START; //curID is the student id used for the next student you are creating
  int index = 0; //the index for the student to find
  int choice; //the choice the user will make
  int password; //the password is 123
  int findstudentID; //find the student ID
  
  /*********************** phase 1 ************************************8
  cout << "-------- adding the first student --------" << endl;
  addStu(stu,id,count); //this will be for adding the first student to the program

  cout << "-------- showing the first student --------" << endl;                             
  showStuInfo(stu[0]);  //pass the first student

  cout << "-------- adding student 2, 3, and 4 --------" << endl;
  addStu(stu,id,count); //this will add the next 4 students that we need
  addStu(stu,id,count);
  addStu(stu,id,count);

  //this is going to show all the students
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(stu, count);

  //this part will be to remove the studeny
  cout << "-------- removing stu 2 --------" << endl;
  removeStu(stu, count); //remove the second stu

  //this will again show the student
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(stu, count);

  //this is so it can remove the last student
  cout << "-------- removing the last student --------" << endl;
  removeStu(stu, count); //remove the last stu

  //this is again to show all the students
  cout << "-------- showing all the students --------" << endl;
  allStuInfo(stu, count);

  //this is to add the file
  cout << "-------- adding from file --------" << endl;
  addStuFromFile(stu, count, id);

  cout << "-------- showing all the students --------" << endl;                              
  allStuInfo(stu, count);
  ****************************/
  /******************************** Phase 2 ******************************
  cout << "-------- adding the first student --------" << endl;
  addStu(ar, id, count);
  cout << "-------- showing the first student --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- addiing 111 to a student --------" << endl;
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- addiing 222 to a student --------" << endl;
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);                                                                              
  cout << "-------- addiing 222 again to a student ==> error --------" << endl;                                            
  addCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- removing 222 --------" << endl;
  dropCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "-------- removing 333 ==> error --------" << endl;
  dropCourse(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "########################################################################################" << endl;
  cout << "If you didn't work on bonus feature, enter 20 0. If you did, enter 20" << endl;
  cout << "########################################################################################" << endl;
  cout << "-------- making a payment --------" << endl;
  makePayment(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "########################################################################################" << endl;
  cout << "If you didn't work on bonus feature, enter 10 14. If you did, enter 10.14" << endl;
  cout << "########################################################################################" << endl;
  cout << "-------- making a payment --------" << endl;
  makePayment(ar[0]);
  cout << "-------- showing the info --------" << endl;
  showStuInfo(ar[0]);
  cout << "########################################################################################" << endl;
  cout << "Did you work on the bonus feature where you reject an over payment? Enter Y or N:";
  char ans;
  cin >> ans;
  if(ans == 'Y' || ans == 'y')
    {
      cout << "-------- For bonus, making an overpayment ==> show error and won't be processed --------" << endl;
      makePayment(ar[0]);
      cout << "-------- showing the info --------" << endl;
      showStuInfo(ar[0]);
    }
  else
    cout << "You didn't work on the bonus feather for overpayment" << endl;
    ****************** End of Phase 2 *********************/  

  //******************* Phase 3 ******************************************

  do
    {
      choice = showMenu(); //this is going to show the menu
      if(choice == 1) //if it is 1
	{
	  cout << "Enter Your Password: "; //Enter the password that we set to
	  cin >> password; //password is 123
	  if(password == 123) //enter this or will not work
	    {
	      int adminChoice; //this is admins choice
	      while(adminChoice != 6) //will keep showing till they exit putting 6
		{
		  adminChoice = showAdmMenu(); //will show admin menu
		  switch(adminChoice) //now will use switch for all the functions in showAdmMenu()
		    {
		    case 1:
		      addStu(ar, count, id); //to add a student to a class
		      break;
		    case 2:
		      addStuFromFile(ar, count, id); //adding student from college.dat
		      break;
		    case 3:
		      removeStu(ar, count); //removing the student
		      break;
		    case 4:
		      cout << "Enter the Student ID: "; //enter student ID
		      cin >> index; 
		      findstudentID = find(ar, count, index); //this is to find the id
		      if(findstudentID == -1) //if it does not exist
			cout << "The Student ID Doesn't Exist" << endl << endl;
		      else //if found
			showStuInfo(ar[findstudentID]); //this will show the student info
		      break;
		    case 5:
		      allStuInfo(ar, count); //display all the students that are in the array
		      break;
		    default:
		      cout << endl;
		    }
		}
	    }
	  else
	    {
	      cout << "Wrong Password - Try Again" << endl << endl; //display if the password is wrong
	    }
	}
      else if(choice == 2) //if the user picks 2
	{
	  int studentChoice; //students options
	  int studentID; //this will hold the students ID
	  int password2; //this is password for students
	  int found; //if the id is found
	  int studentID2;
	  cout << "Enter Student ID: ";
	  cin >> studentID; //enter studentID
	  found = find(ar, count, studentID); //to return the index
	  if(found == -1) //this is if the student doesnt exist
	    cout << "The Student ID Doesn't Exist." << endl << endl;
	  else
	    {
	      cout << "Enter the Password: ";
	      cin >> password2; //this is going to ask for the password for the student
	      studentID2 = ar[found].getStuID(); //studentID2 is going to hold the student ID
	      studentID2 = studentID2 % (PRIME1 * PRIME2); //will get the password and store
	      if(password2 == studentID2) //if not equal then we show the error message
		{
		  cout << "The Password is Wrong." << endl << endl; //display the message
		}
	      else //if it does match
		{
		  int crn;
		  int crnD;
		  cout << "Welcome " << ar[found].getFirstName() << endl; //welcome the student
		  while(studentChoice != 5) //cannot exit the loop till they pick 5
		    {
		      studentChoice = showStuMenu(); //this will be the student menu
		      switch(studentChoice)
			{
			case 1:
			  addCourse(ar[found]); //this will add the course to student
			  break;
			case 2:
			  dropCourse(ar[found]); //drop the course
			  break;
			case 3:
			  makePayment(ar[found]); //make payment
			  break;
			case 4:
			  showStuInfo(ar[found]); //show student info
			  break;
			}
		    }
		}
	    }
	}
    }

  while(choice != 3); //close if it is 3
  return 0;
}



// ************************  PHASE 1  ****************************

void addStu(Student ar[], int& n, int& stuID)
{
  string firstName;
  string lastName;
  char gender;
  //case 1 of admission
  //cin >>> fn, ln, gen
  if(n == SIZE)
    cout << "Max number of students reached" << endl;
  else
    {
      cout << "Enter First Name: ";
      cin >> firstName;

      cout << "Enter Last Name: ";
      cin >> lastName;

      cout << "Enter Gender: ";
      cin >> gender;

  //create a student object. The first student created is given a stu id, 100000 (coming from const START).
  //The second student gets 100001, the third student gets 100002, etc (notice curID in main).
      Student s(firstName, lastName, gender, stuID++);
  //copy the info from the stu obj into the array at the appropriate slot
      ar[n] = s;
      n++;
      stuID++;
    }
}

void showStuInfo(const Student& s)
{                                                                                                                                             
//*********************************************************************
//DO NOT send the entire array to this function. BIG deduction if you do.
//SEND only ONE student object as a parameter. If you don't know how, check
//lab1-struct.cpp.
//********************************************************************** 


  cout << "--------------------" << endl;                                                         
                                                                                                                                             
  cout << "first name: " <<  s.getFirstName()  << endl;                                                                                                 
 
  cout << "last name: " << s.getLastName()  << endl;                                                                           

  cout << "gender: " << s.getGender() << endl; 
 
  cout << "stu id: " << s.getStuID() << endl;

  cout << "num classes: " << s.getNumClasses()  << endl;
                       
  cout << "Courses: ";                                                                                                                        
 
  for(int i = 0; i < s.getNumClasses(); i++)  //Don't use showAllCourses() but show each course at a time. Which memeber function shows one course?      
    cout << s.getClassOf(i)  << ", ";                                                                                                                 
 
                                                                                                                                              
  cout << "\nAmount owed $" << s.getBalance()  << endl;  //You have an operator overloading function to show a price object at once                   
 
  cout << endl;                                                                                                                               
 
}


void allStuInfo(const Student ar[], const int n)
{
//Case 5 of Admission and case 4 of student
//Call showStuInfo()
//******************************************
//YOU MUST call showStuInfo() to show each student.
//*******************************************
  if(n == 0) //if we did not input any students
    cout << "There are no students enrolled" << endl;
  else //if we did
    {
      for(int i = 0; i < n; i++)
        showStuInfo(ar[i]);
    }
}

bool operator==(const Student& s, int id) 
{
  if(s.getStuID() == id) //make sure to change the id
    return true; //this is to make sure to add the id by 1
  else
    return false; //if it is not the same from the original one  
}


void removeStu(Student ar[], int& n)
{
  //Case 3 of Admission
  int id;
  int index;
  //2 different messages
  cout << "Enter the Student ID: " << endl; //ask for student id
  cin >> id;
  index = find(ar, n, id); //find the student id;
  //this is going to show with negative number that it does not exist
  if(index == -1)
    cout << "student with id " << id << " doesn't exist" << endl;
  else
    {
      cout << ar[index].getFirstName() << " " << ar[index].getLastName() << " has been removed." << endl;
      remove(ar, n, id); // f << " " << l << " has been removed." << endl
      n--;
    }
}

void addStuFromFile(Student ar[], int& n, int& id)
{
  //Case 2 of admission
  ifstream fin;
  char gender;
  string fN;
  string lN;
  string fileName;
  //this is going to be able to enter a filename
  cout << "Enter a File Name: " << endl;
  cin >> fileName;
  fin.open(fileName.c_str()); //this is going to open the file college.dat
  if(!fin)
    {
      //if the file name isnt fouund
      cout << "File cannot be found" << endl;
    }
  else //if it is found
    {
      fin >> fN; //this is for First Name
      fin >> lN; //this is for last name
      fin >> gender; //this is for the gender
      {
        while(fin)
          {
            if(n == SIZE) //if the array is full it will display a message
              {
                cout << "Array is full" << endl;
              }
            else //if it is not full
              {
                Student s(fN, lN, gender, id);
                ar[n] = s;
                n++;
                id++; //going to increase the id
                fin >> fN; //name
                fin >> lN; //last name
                fin >> gender; //gender
              }
          }
        fin.close(); //this will close the file
      }
    }
}




//*******************  PHASE 2 ****************************


void addCourse(Student& s)
{
//case 1 of student
//FYI, I am passing one student to this function not the array. 
  int crn;
  cout << "enter crn: ";
  cin >> crn;

//3 different messages to show
  if(s.addCourse(crn) == 1)
    {
      
  // " has been added successfully" << endl;
      cout << crn << " has been added successfully" << endl;
      crn = crn + 111; //this will be when a class is added
      s.addFee(50,14);
    }
  else if(s.addCourse(crn) == 0) //this is if the class is already existing
    // " was not added because you have " << crn << " already." <<  endl;
    cout << crn << " was not added because you have " << crn << " already." << endl;
  else //if full
    // " was not added because your schedule is full." <<  endl;
    cout << crn << " was not added because your schedule is full." << endl;
}


void dropCourse(Student& s)
{
  int crn;
  cout << "Enter crn: ";
  cin >> crn;
//case 2 of admission
//FYI, I am passing one student to this function not the array. 

//2 different messages
    // " wasn't dropped from " << s.getFirstName() << " because " << cr << " doesn't exist" << endl;
    // " has been dropped successfully." << endl;
  if(s.dropCourse(crn) == false)
    cout << crn << " wasn't dropped from " << s.getFirstName() << " because " << crn << " doesn't exist" << endl;
  else
    {
      cout << crn << " has been dropped successfully." << endl;
      s.reduceFee(50,14);
    }
}


void makePayment(Student& s)
{
  int d;
  int c;
//case 3 of student
  cout << " You currently owe " << s.getBalance() << endl;
  cin >> d >> c;
//FYI, I am passing one student to this function not the array.
  s.reduceFee(d,c);
}






//******************** PHASE 3 ****************************

bool checkPassword(int option, int password, int studentID )
{
//I am using this function to check a password for both the admission's office and student
//FYI, I am passing the correct password as a parameter and returning true/false.
//The correct password for a student is  student_id % (PRIME1 * PRIME2)
}


int findStu(Student ar[], int& n, int studentID)
{
//Small function. You may choose not to use this function. That is OK.
  return find(ar, n, studentID);
//Ask for the student id
//call find() to find the student id
//return what find() returned which is index where it was found or -1
}


void viewStuInfo(Student ar[], int& counter)
{
//Case 4 of admission
  int studentID;
  int verify;
//Ask for the student id
  cout << "Enter your ID: ";
  cin >> studentID;
//If the student doesn't exist, show an error message.
  verify = find(ar, counter, studentID);
  if(verify == -1)
    cout << "The Student Doesn't Exist" << endl;
  else
//If it exists, call showStuInfo to show the student
    showStuInfo(ar[verify]);
}


int verifyStu(Student ar[], int& counter, int studentID)
{
//You may decide not to use this function. If so, that is OK.
  int verify = find(ar, counter, studentID);
//When the user is a student, select 2 in the top menu. He/she enters hi/her student id.
//Make sure the stuent id exists in the array. If not, I am showing an error message.
//FYI, I am returning the index where the student was found or -1 if not found.
  if(verify == -1)
    cout << "Student Does Not Exist" << endl;
  else
    return verify;
}



int showMenu()
{
  int choice;
  cout << "========================================================" << endl;
  cout << "1: Admission's Office" << endl;
  cout << "2: Student" << endl;
  cout << "3: End program" << endl;
  cout << "========================================================" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 3, "\tInvalid choice. Enter only 1, 2 or 3: ");

  return choice;
}


int showStuMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a course" << endl;
  cout << "2: drop a course" << endl;
  cout << "3: Make a payment" << endl;
  cout << "4: View my information" << endl;
  cout << "5: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 5, "\tInvalid choice. Enter only 1 through 5: ");

  return choice;
}

int showAdmMenu()
{
  int choice;

  cout << endl;
  cout << "***************************" << endl;
  cout << "1: Add a new student" << endl;
  cout << "2: Add new students from a file" << endl;
  cout << "3: drop a student" << endl;
  cout << "4: View one student info" << endl;
  cout << "5: View all students' info" << endl;
  cout << "6: Quit" << endl;
  cout << "***************************" << endl;
  cout << "Enter your choice: ";
  choice = getData(1, 6, "\tInvalid choice. Enter only 1 through 6: ");

  return choice;
}
