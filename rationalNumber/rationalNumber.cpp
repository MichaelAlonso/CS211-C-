#include "rationalNumber.h"

//default constructor: set top to 0 and bottom to 1
rNum::rNum()
{
  top = 0;
  bot = 1;
}

//non-default constructor: we won't be using it in the client, but we might as well make it.
rNum::rNum(int top, int bot)
{
  this -> top = top;
  this -> bot = bot;
}
//Create all operator overloaded functions here. You need to figure out what you need by reading the client.
//this overloads the + and adds the two rational numbers and both are const
/*rNum rNum::operator+(const rNum& r1,const rNum& r2)
{
  //this object is going to be returned
  rNum result; 
  if(r1.bot == r2.bot) //if the denominatos are the same
    {
      result.top = r1.top + r2.top; //this is going to add the numeratos
      result.bot = r2.bot; //we could use r1.bot as well for this since it is the same denominators
    }
  else //if they are not the same denominators
    {
      result.top = (r1.top * r2.bot) + (r2.top * r1.bot); //cross multiplying
      result.bot = (r1.bot * r2.bot); //multipling the two denominatos
    }
  simplify(result); //simplying the result
  return result; //return our answer
}

//This function is going to allow main to print out the rNum for the top and bot numbers
ostream& operator<<(ostream& out, const rNum& r)
{
  cout << r.top << "/" << r.bot; //output the numbers with the slash
  return out;
}

//This function is going to be able to take the user input 
istream& operator>>(istream& is, rNum& r)
{
  cout << "Enter the Top Number: " << endl; //this is going to be for the numerator
  is >> r.top;
  cout << "Enter the Bottom Number: " << endl;
  is >> r.bot;
  return is; //return the input stream
}

//This operator will make changes to r1 by using the pass by referene
void rNum::operator+=(rNum& r1, const rNum& r2)
{
  if(r1.bot == r2.bot)
    {
      r1.top += r2.top; //if the denominators are the same
    }
  else
    {
      r1.top = (r1.top * r2.bot) + (r2.top * r1.top);
      r1.bot = (r1.bot * r2.bot);
    }
  simplify(r1);
}

//This operator checks if r1 is less than r2 and will return true if not then will return false
bool rNum::operator>(const rNum& r1, const rNum& r2)
{
  if(r1.bot == r2.bot) //if the denominators are the same we compare the r1 and r2 top
    {
      if(r1.top > r2.top)
	return true;
      return false; //if r2 is greater than or equal then it is false

    }
  else
    {
      //these are temporary numerators
      int temptop1;
      int temptop2;
      temptop1 = r1.top * r2.bot;
      temptop2 = r2.top * r1.bot; 
      if(temptop1 > temptop 2) //compares if the rational number is greater if yes then it is true
	return true;
      return false;
    }

}

//this will check if the functions are equal to each other
bool rNum::operator==(const rNum& r1, const rNum& r2)
{
  //both numbers share numerator and denominators
  if(r1.top == r2.top && r1.bot == r2.bot)
    return true;
  return false;
}

//This is not an operator overloaded function.. This function will simplify a rational number to the simplest form.
void rNum::simplify(rNum& r)
{
  int greatestCommonFactor = 0; //setting our GCF to 0
  int numerator;
  int denominator;
  
  numerator = r.top; //setting the numerator to top of the fraction
  denominator = r.bot; //setting denominator to bot of the fraction

  while(numerator % denominator != 0)
    {
      //we are able to get GCF by getting what the remainder is of the numbers
      greatestCommonFactor = numerator % denominator;
      //now then we swap the these two
      numerator = denominator;
      //this will then set denominator to GCF
      denominator = greatestCommonFactor;
    }
  //now repeating until numerator and denominator == 0
  if(greatestCommonFactor == 0) //check if GCF is equal to zero
    {
      //divide the rational number numerator to the denominator
      r.top /= r.bot;
      r.bot = 1; //TESTING WITH THIS MAY HAVE TO DELETE
    }
  else //if the GCF isn't zero divide both top and bot by the GCF
    {
      r.top /= greatestCommonFactor;
      r.bot /= greatestCommonFactor;
    }
}
*/
