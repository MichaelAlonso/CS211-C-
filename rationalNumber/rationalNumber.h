#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

class rNum
{
  //  friend ostream& operator<<(ostream& out, const rNum& r);
  // friend istream& operator>>(istream& is, rNum& r);
 private: //both our top and bot are going to be here so we can access it through our public
  int top;
  int bot;

 public:
  //default constructor
  rNum();
  //non default constructor
  rNum(int top, int bot);
  //this is our 6 operators are at and that we made in rationalNumber.cpp
  // rNum operator+(const rNum& r1, const rNum& r2);
  // void operator+=(rNum& r1, const rNum& r2);
  //bool operator>(const rNum& r1, const rNum& r2);
  //bool operator==(const rNum& r1, const rNum& r2);
  //our simplify is different because it is not an overload function compared to the other 6 we are making
  //void simplify(rNum& r);

};



#endif
