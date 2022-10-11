#include <iostream>
#include "price.h" //being able to include the price.h

using namespace std;

int main()
{
  Price p1(2,50);
  Price p2(3,75);
  Price p3(1,99);
  Price p4(1,58);

  Price total1;
  Price total2;
  Price total3;
  Price diff1;
  Price diff2;

  total1 = p1 + p2;
  total2 = p1 + p1;
  total3 = p1 + p4;
  diff1 = p2 - p1;
  diff2 = p1 - p3;

  cout << "$" << p1 << "+$" << p2 << "=$" << total1 << endl; //$2.50 + $3.75 = $6.25
  cout << "$" << p1 << "+$" << p1 << "=$" << total2 << endl; //$2.50 + $3.75 = $6.25
  cout << "$" << p1 << "+$" << p4 << "=$" << total3 << endl; //$2.50 + $3.75 = $6.25
  cout << "$" << p2 << "+$" << p1 << "=$" << diff1 << endl; //$2.50 + $3.75 = $6.25
  cout << "$" << p1 << "+$" << p3 << "=$" << diff2 << endl; //$2.50 + $3.75 = $6.25

  return 0;
}
