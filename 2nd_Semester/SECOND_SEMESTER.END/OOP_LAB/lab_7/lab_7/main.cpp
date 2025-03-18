//
//  main.cpp
//  lab_7
//
//  Created by Ahmad Gill on 07/04/2022.
//

#include <iostream>
using namespace std;
class Quadratic
{
private:
     int a;
     int b;
     int c;
public:
    Quadratic()//default constructor
    {
        a = 0;
        b = 0;
        c = 0;
    }
    friend void Input(Quadratic);
   Quadratic(const Quadratic &q1)///cpy constructor
   {
       a = q1.a;
       b = q1.b;
       c = q1.c;
   }
   ~Quadratic()
    {
       
   }//Destructor
      Quadratic operator+(const Quadratic &obj)
      {
          cout<<"the quadratic requation is given as"<<this->a+obj.a<<" x*2 "<<this->b+obj.b<<" x "<<this->c+obj.c<<endl;
          return 0;
      }
    friend Quadratic operator+(Quadratic);
    Quadratic operator-(const Quadratic &obj)
      {
          cout<<"the quadratic requation is given as"<<this->a-obj.a<<" x*2 "<<this->b-obj.b<<" x "<<this->c-obj.c<<endl;
          return 0;
      }
    friend Quadratic operator-(Quadratic);
      Quadratic operator*(const Quadratic &obj)
      {
          cout<<"the quadratic requation is given as"<<this->a*obj.a<<" x*2 "<<this->b*obj.b<<" x "<<this->c*obj.c<<endl;
          return 0;
      }
    void Input()
    {
        cout<<"enter the value X*2 for first equation";
        cin>> this->a;
        cout<<"enter the value X for first equation";
        cin>>  this->b;
        cout<<"enter the value constant for first equation";
       cin>> this->c;
    }
      
};
int main()
{
    
  
   
    
    Quadratic q1;
    q1.Input();
  Quadratic  q2=q1;
    return 0;
}
