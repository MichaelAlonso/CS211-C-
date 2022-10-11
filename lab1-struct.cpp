/*******************************************
Michael Alonso Ambrocio
CS211 Slott 
lab1
1-21-2020

Display the names in the file, and call some of the functions.
*******************************************/

#include <iostream>
#include <iomanip>
#include <fstream>

//???????? need more header files?
using namespace std;

//???????? Where do the prototypes go?
//???????? Declare the struct called student
int getStuData(studentInfo student[]);
void displayAllStu(const studentInfo student[], int n);
void displayStu(student s);
void findYoungOld(conststudentInfo student[], int n);
int findID(const studentInfo student[],int n);
//????? Decare a constant called MAX and set it to 20. //The maximum number of students the array can hold

int main()
{
  //?????????? create a student called stu and set 1000, Lucy, Smith, 20 to it
  studentInfo stu;
  stu.id = 1000;
  stu.name = "lucy";
  stu.last = "Smith";
  stu.age = 20;
  displayStu(stu); //?????????? display stu by calling displayStu                                                                                                 
       
  studentInfo student[MAX]; //?????????? Create an array of students using MAX

  int number; //it holds the number of students or -1 if the input file didn't exist

  number = getStuData(student);
  //?????????? call the getStuData function to fill the array with students' information
  //getStuData returns the number of students or -1 if the file doesn't exist
  
  
  //?????????  
    cout << "The file didn't exist." << endl;
  //?????????
    cout << "There are no students in the input file." << endl; //The file existed but it was empty
  //?????? //The input file had at least one student 
    {
      //??????  show all the students' info by calling displayAllStu 
      findID(look, id);
      int look; //The id the user is looking for
      cout << "\nEnter the id you are looking for: ";
      cin >> look;
      
      //Find a student with the id you are looking for and display the information about that student. If no student has the id, show an appropriate message.
      //?????????????  Call findID  
      //if( ???????  ) //The id the user was looking for was found
           //display the info on the student with that id by calling displayStu
      //else
      
	cout << "No student with id " << look << " was found" << endl;

      //find the youngest and oldest students by calling findYoungOld
      int yngInd; //index of the yougest student
      int oldInd; //index of the oldest student
      //??????????? call findYoundOld
      findYoungOld(age, yngInd);
      cout<< "\nThe youngest Student -----" << endl;
      //??????????? call displayStu to show the youngest student's info
      findYoungOld(age, oldInd);
      cout<< "\nThe oldest Student -----" << endl;
      //?????????? call displayStu to show the oldest student's info
    }     

  cout << endl;
    
  return 0;
}

//This function loads students' data into the array and returns the number of students.
int getStuData(studentInfo student[]){

   string filename;
   int number = 0;

  cout << "Enter the input file name that has the students' info: ";
  cin >> filename; 
  ifstream file;
  inFile.open("student.dat");
 
  if(!inFile){
    cout <<"Cannot open the input file" << endl;
  }
  else
    {
      outFile.open("result.dat");
      int num;
      for(int i = 0; i < 10; i++){
	inFile >> num;
	outFile << setw(4) << num << endl;
      }
      infile.close();
      outFile.close();
    }
  return 0;

}

/* This function searches through the array to find the student with the id the user is looking for.
      The user is asked to enter the id she is looking for in the main.
      Return the index where the student with the id was found or -1 if not found. */


/*??? findID( ???????? )
{

}*/

int findID(const studentInfo student[], int n){
  for(int i = 0; i < MAX; i++)
    if (student[].id == MAX)
      displayStu(student[]);
  return -1;
}

/*Pass the student array and call displayStu to show each student */
void displayAllStu(const studentInfo student[], int n){
  cout << left << setw(40) << "ID " << setw(10) << "FIRST NAME" << setw(10) << "LAST NAME" << setw(10) << "AGE" << endl;
  cout << "----------=----------------------------------------";
  for(int i = 0; i < n; i++){
    cout << left;
    cout << setw(40) << student[i].id;
    cout << setw(10) << student[i].name;
    cout << setw(10) << student[i].last;
    cout << setw(10) << student[i].age;
    cout << endl;
  }
}
/*???? displayAllStu( ????????? )
{
 
   //call displayStu to show each student

}*/

/*One student struct is passed to this function and display all the information (id, fName, lName and age) about that student.*/
/*??? displayStu( ???? )
{

}*/
void displayStu(student s){
  cout << left;
  cout << setw(40) << student[i].id;
  cout << setw(10) << student[i].name;
  cout << setw(10) << student[i].last;
  cout << setw(10) << student[i].age;
  cout << endl;
}

/*This function will pass back the *indices* of the youngest and oldest students */
/*????  findYoungOld( ???? )
{

  
}*/
void findYoungOld(const studentInfo student[], int n){
  int oldest = 0;
  int youngest = 0;
  for (int i = 0; i < n; i++){
    if (youngest < student[i].oldest){
      youngest = arr[i].oldest;
    }
  }
  return oldest;
  return youngest;
}
