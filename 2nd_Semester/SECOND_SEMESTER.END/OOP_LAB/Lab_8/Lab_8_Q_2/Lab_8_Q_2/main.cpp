//
//  main.cpp
//  Lab_8_Q_2
//
//  Created by Ahmad Gill on 15/04/2022.
//

#include <iostream>
using namespace std;
class Point
{
int* x;
int* y;
public:
//Constructors, Getters and Destructor
   void set(int &a ,int &b)
    {
        x = &a;
        y= &b;
    }
    void get()
    {
        cout<<"the value of x is ;"<<*x<<endl;
        cout<<"the value of y is : "<<*y<<endl;
    }
    ~Point()
    {
    
    }
};

class Circle
{
private:
float* radius;
Point* coordinate;
public:
//Constructors, Getters, Destructor
    Circle(float &a,int &b,int &c)
    {
        radius = &a;
        coordinate->set(b,c);
        
    }
    void Get()
    {
        cout<<"raduus of given circle is : "<<*radius;
        coordinate->get();
    }
//bool CheckOnCircle(Point&amp; p1) //Returns true if point lies in circle,

// false otherwise
};
class Cylinder
{
private:
int height;
Circle* top; //Circle on top of Cylinder circle* bottom;
//Circle on bottom of Cylinder
public:
//Constructors, Destructors
//bool CheckOnCylinder(Point&amp; p1) //Returns true if point lies
//in cylinder, false otherwise
};

int main()
{// should contains following lines, You can add more code, but these lines should be
    int x=2;
    int y=4;
 //   Point p1(x,y);
    
   Circle c1(5.3,x,y);
    c1.Get();
    //Take radius, x, y c1.CheckOnCircle(p1) ;
//cylinder cl1(7,5.3,2,9,5.3,2,3); //takes height, parameters for top and bottom circles
//cl1.CheckOnCylinder(p1);
    return 0;
}
