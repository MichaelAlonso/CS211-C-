#include <iostream>


using namespace std;


enum direct{NORTH, EAST, SOUTH, WEST};

class Car
{
private:
  string model;
  int milage;
  int year;
  int x;
  int y;
  direct direction;
public: //this is where we store our prototypes to help get the private
  Car(string md, int yr);
  string getModel()const;
  void goForward(int block);
  int getX()const;
  int getY()const;
  void turnRight();
  string getDirection()const;
  void turnLeft();
  int getYear()const;
  int getmilage()const;
};

//This is when we start a new car and need to name it a model and year and starts at 0,0 and NORTH
Car::Car(string md, int yr)
{

  model = md;
  year = yr;
  milage = 0;
  x = 0;
  y = 0;
  direction = NORTH;

}
//This will then get the name of the model of the car that we typed in
string Car::getModel()const
{
  return model;
}

int Car::getYear()const
{
  return year;
}

int Car::getmilage()const
{
  return milage;
}

//This prototype is going to be able to move the car forward
void Car::goForward(int block)
{
  if(direction == NORTH)
    y += block;
  else if(direction == EAST)
    x += block;
  else if(direction == SOUTH)
    y -= block;
  else if(direction == WEST)
    x -= block;
  milage += block;
}

int Car::getX()const
{
  return x;
}

int Car::getY()const
{
  return y;
}

string Car::getDirection()const
{
  switch(direction)
    {
    case NORTH: return "NORTH";
    case EAST: return "EAST";
    case SOUTH: return "SOUTH";
    case WEST: return "WEST";
    }
  //return direction;
}

void Car::turnRight()
{
  if(direction == WEST) //if it already at WESt
    direction = NORTH; //goes back to north
  else
    direction = (direct)(direction + 1);
}

void Car::turnLeft()
{
  if(direction == NORTH)
    direction = WEST;
  else
    direction = (direct)(direction - 1);
}

void showInfo(Car c);

int main()
{
  Car c1("Camry", 2022);
  Car c2("Neon", 2020);

  /*  cout << c1.getModel() << endl;
  c1.turnRight();
  c1.goForward(5);
  c1.turnRight();
  c1.goForward(2);
  c1.turnRight();
  c1.turnRight();
  c1.goForward(3);
  cout << c1.getX() << " , " << c1.getY() << endl;
  */
  
  c1.goForward(3);
  c1.turnRight();
  c1.goForward(5);
  c1.turnRight();
  c1.goForward(7);
  c1.turnRight();
  c1.goForward(6);
  c1.turnLeft();
  c1.goForward(1);
  showInfo(c1);

  c2.goForward(5);
  c2.turnLeft();
  c2.goForward(1);
  c2.turnLeft();
  c2.goForward(2);
  c2.turnLeft();
  c2.goForward(4);
  c2.turnLeft();
  c2.goForward(10);
  showInfo(c2);

  return 0;
}

void showInfo(Car c)
{
  cout << c.getModel() << "(" << c.getYear() << ") is located at (" << c.getX() << "," << c.getY() << ") facing " << c.getDirection() <<". It has " << c.getmilage() << " miles on it." << endl;
}
