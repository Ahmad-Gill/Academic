//
//  main.cpp
//  Home_work_2
//
//  Created by Ahmad Gill on 28/04/2022.
//

#include <iostream>
using namespace std;
class Fraction
{
    static int fraction_count;
    int numerator;
    int denomirator;
public:
    Fraction(int n=1,int d=1)
    {
        numerator =n;
        denomirator =d;
    }
    void SET_Numerator(int n)
    {
        numerator = n;
    }
    void Set_denomirator(int d)
    {
        denomirator =d;
    }
    int Get_Numerator()const
    {
        return this->numerator;
    }
    int Get_denomirator()const
    {
        return this->denomirator;
    }
Fraction operator+(const Fraction&obj_1)
    {
        Fraction obj;
    if(this->denomirator == obj_1.denomirator)
        {
            obj.numerator = numerator + obj_1.numerator;
            obj.denomirator = denomirator;
        for(int i = 2 ; i <= obj.numerator ; i++)
        {
            if(obj.denomirator % i == 0 && obj.numerator % i == 0)
            {
               obj.numerator = obj.numerator / i;
                obj.denomirator = obj.denomirator / i;
            }
        }

            cout<<"Addition: "<<obj.numerator<<"/"<<obj.denomirator;
    }
    else
    {
        cout<<"Addition is not possible as denominators are different"<<endl;
    }
    return obj;
    }
    Fraction operator *(const Fraction &f)
    {
        Fraction obj;
        obj.numerator = numerator * f.numerator;
        obj.denomirator = denomirator * f.denomirator;
       for(int i = 2 ; i <= obj.numerator ; i++)
        {
            if(obj.denomirator % i == 0 && obj.numerator % i == 0)
            {
               obj.numerator = obj.numerator / i;
                obj.denomirator = obj.denomirator / i;
            }
        }
        cout<<"Multiplication: "<<obj.numerator<<"/"<<obj.denomirator;
        return obj;
    }

    bool isProper()const
    {
        if(this->numerator > this->denomirator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

     int getCount()
    {
         return fraction_count;
    }

    bool operator > (const Fraction &f)
    {
        if(denomirator == f.denomirator)
        {
            if(numerator > f.numerator)
            {
                return true;
            }
        }

        if(numerator == f.numerator)
        {
            if(numerator > f.numerator)
            {
                 return true;
            }
        }
        if(denomirator > f.denomirator)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void show()
    {
        cout<<"Number of fractions: "<<this->getCount();
        cout<<"2"<<endl;
        cout<<"Addition: ";
        cout<<endl;
        cout<<"Multiplication: ";
        cout<<endl;
        cout<<endl;
        cout<<"Comparison: ";
    }
};

int main()
{
    int n , d , n1 , d1;
    cout<<"For First Fraction"<<endl;
    cout<<"__________________________________________"<<endl;
    cout<<endl;
    cout<<"Enter the value for numerator: ";
    cin >> n;
    cout<<"Enter the value for denominator: ";
    cin >> d;
  //  static int count1= 0;
    Fraction f1(n,d);
 
  //  Fraction (n , d);
  //  f1.setNum(n);
   // f1.setDen(d);
    cout<<endl;
    cout<<"For Second Fraction"<<endl;
    cout<<"__________________________________________"<<endl<<endl;
    cout<<"Enter the value for numerator: ";
    cin >> n1;
    cout<<"Enter the value for denominator: ";
    cin >> d1;
    Fraction f2(n1,d1);
    cout<<endl;
  //  f2.setNum(n1);
   // f2.setDen(d1);
    cout<<endl;
    cout<<"Number of fractions: "<<f1.getCount();
    cout<<"2"<<endl;
    cout<<endl;
    f1+f2;
    cout<<endl;
    f1*f2;
    cout<<endl;
    if(f1.isProper())
    {
        cout<<"The given first fraction if Proper";
    }
    else
    {
        cout<<"the given first fraction is improper";
    }
    cout<<endl;
    if(f2.isProper())
    {
        cout<<"The given second fraction is proper";
    }
    else
    {
        cout<<"The given second fraction is improper";
    }
    cout<<endl;
    if(f1.operator >(f2))
    {
        cout<<"The second fraction is greater than or equal to the other";
    }
    else
    {
        cout<<"The first fraction is greater than or equal to the other";
    }
    cout<<endl;
    return 0;
}

