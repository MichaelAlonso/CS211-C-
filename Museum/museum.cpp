#include <iostream>
#include "array.h" //this is from the program that we wrote earlier
#include "/cs/slott/cs211/checkInput.h" //This is the program that we are going to use for getData and getYN
#include <iomanip> //this is to use setprecision
#include <fstream> //this is for fout


using namespace std;

int people = 0; //there is 0 people starting 
const int MAX = 2; //the max amount of people is 100
string arrayString[MAX]; //this is the array for string
double arrayDouble[MAX]; //this is the array for double
int arrayInt[MAX]; //this is the array for integers
char q; //setting char variable

int showMenu(); //the function to get the menu that we wrote below
void getVisitorInfo(string arrayString[], int arrayInt[], double arrayDouble[], int& i); //the function to get the info
bool checkPassword(int pW); //this is for the password
template <class T>
void showStatistic(T& out, string ts[], int ti[], double td[], int& visit); //this is to show the stats of the people that visit

int main()
{
  ofstream fout; //output
  string date; //variable for data
  string file; //file being written to the file

  do
    {
      showMenu(); //loops show menu as long the user doesnt input n or N
    }
  while (q != 'Y');
  if(q == 'Y') //if user is going to input the y or Y
    {
      cout << "Enter today's date: "; //this is going to get the date and also put it in the file
      cin >> date; //getting the date that is going to be input
      file = date + ".txt"; //this is going to make the filename 
      fout.open(file.c_str()); //makes the file that is going to be written to
      showStatistic(fout, arrayString, arrayInt, arrayDouble, people); //shows stats for the visitors
      fout.close(); //closes the file

    }

  return 0;
}

int showMenu() //this function is going to be to display our menu for users to interact with
{
  int password; //Setting our password to an int so we use only whole numbers
  
  cout << "======================================" << endl;
  cout << "1. Visitor" << endl;
  cout << "2. Museum Staff" << endl;
  cout << "Enter your choice: ";
  int choice = getData(1, 2, "Invalid Choice. Enter 1 or 2: "); //user only given two options which are 1 or 2
  if(choice == 1) //if user picks 1
    {
      getVisitorInfo(arrayString,arrayInt,arrayDouble, people); //this is to get the information from the people who visit
    }
  else if(choice == 2) //if the person picks 2 
    {
      cout << "Enter the Password: "; //asking for a password
      cin >> password; //enter the password
      if(checkPassword(password) != true)
	{
	  cout << "Password is incorrect" << endl; //this is to display that the password was wrong
	}
      else //if it is correct then we move on
	{
	  showStatistic(cout, arrayString, arrayInt, arrayDouble, people);
	  cout << "Do you want to close the museum? Y or N: ";
	  q = getYN("Invalid Answer. Enter Y or N: "); //is going to get the q which is the answer
	}
    }

  return q; //this will return the answer we put
}

//this is going to get the visitors information country, age, and hours
void getVisitorInfo(string arrayString[], int arrayInt[], double arrayDouble[], int& i)
{
  if(i < MAX) //this is for the 100 people a day
    {
      cout << endl;
      cout << "Enter your country: ";
      cin >> arrayString[i]; //will get the country array
      
      cout << endl;
      cout << "Enter your age: ";
      arrayInt[i] = getData(0, 200, "The age has to be between 0 and 200. Enter again: "); //set the min from 0 to high 200 so cant go above 200

      cout << endl;
      cout << "Enter the number of hours you explored: ";
      arrayDouble[i] = getData(0.0, 10.0, "The number of hours has to be between 0 and 10.0 Enter again: "); //the min is 0 and the limit is 10.0 if it goes further then the message will display

      i++; //this will add the visitor
    }
  else
    {
      cout << "We cannot take anymore visitor info: " << endl; //this is we go over 100
    }
}

//this function is to check the password that is going to be inputted
bool checkPassword(int pW)
{
  if(pW == 5678) //password is 5678
    {
      return true;
    }
  //if the password is wrong 
  else
    return false; 
}

//this is for the template in case we need to use it for int, array, string, or char
template <class T>
void showStatistic(T& out, string ts[], int ti[], double td[], int& visit)
{
  if(visit == 0) //when there is no visitors
    {
      //the message that will be displayed
      cout << "The total number of visitors is: " << visit << endl;
    }
  else //when there is at least one or more visitors
    {
      out << "The total number of visitors is: " << visit << endl; //outputting the amount of visitors

      string uniqString[visit]; //going to be setting a new unique for visits
      int uniString = unique(ts, uniqString, visit); //setting unique function to a int variable

      out << "------ The names of the countries of visitors ------" << endl; //this is for the countries
      sort(uniqString, uniString);
      print(uniqString, uniString); //printing out the unique function

      int young = getLowest(ti, visit); //this is going to get the youngest 
      cout << endl;
      out << "The age of the youngest visitor: " << ti[young] << endl; //output the youngest to file

      int old = getHighest(ti, visit); //this is going to get the oldest
      out << "The age of the oldest visitor: " << ti[old] << endl; //this is going to output the oldest to file

      double avg = getAvg(ti, visit); //this is going to get the average
      out << setprecision(3) << "The average age of the visitors: " << avg << endl; //outputs to file

      int lowest = getLowest(td, visit); //is going to get the lowest
      cout << endl;
      out << "The shortest visit hours: " << td[lowest] << endl; // outputs the lowest to file

      int longest = getHighest(td, visit); //is going to get the highest
      out << "The longest visit hours: " << td[longest] << endl; //outputs the longest to file

      double avgHours = getAvg(td, visit); //is going to get the average hours
      out << setprecision(3) << "The average visit hours: " << avgHours << endl; //outputs the average hours

    }
}

