#include <iostream>

using namespace std;

void myStrcpy(char dest[], const char source[]);

int main()
{
  char str1[20] = "Hello CS111";
  cout << str1 << endl; //Hello CS111
  myStrcpy(str1, "Oh PHYS302");
  cout << str1 << endl; //Oh PHYS302
  myStrcpy(str1, "What a great world");
  cout << str1 << endl; //What a great world
  return 0;
}

void myStrcpy(char dest[], const char source[])
{
  int i = 0; //this is going to be set to 0
  while(source[i])
    {
      dest[i] = source[i]; //dest us going to equal to source
      i++; //this is going to count
    }
  dest[i] = '\0';
}
