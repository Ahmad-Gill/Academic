//
//  main.cpp
//  Home_work_2
//
//  Created by Ahmad Gill on 11/05/2022.
//

//
//  main.cpp
//  Home_work_2
//
//  Created by Ahmad Gill on 28/04/2022.
//

#include <iostream>
using namespace std;
static int fraction_count;
class Fraction
{
   
    int numerator;
    int denomirator;
public:
    Fraction(int n=1,int d=1)
    {
        this->numerator =n;
        this->denomirator =d;
    }
    void SET_Numerator(int n)
    {
        this->numerator = n;
    }
    void Set_denomirator(int d)
    {
        this->denomirator =d;
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

            cout<<"Addition: = "<<obj.numerator<<"/"<<obj.denomirator;
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
        obj.numerator =this-> numerator * f.numerator;
        obj.denomirator =this-> denomirator * f.denomirator;
       for(int i = 2 ; i <= obj.numerator ; i++)
        {
            if(obj.denomirator % i == 0 && obj.numerator % i == 0)
            {
               obj.numerator = obj.numerator / i;
                obj.denomirator = obj.denomirator / i;
            }
        }
        cout<<"Multiplication:=  "<<obj.numerator<<"/"<<obj.denomirator;
        return obj;
    }

    bool isProper()const
    {
        if(this->numerator > this->denomirator)
            return true;
        else
            return false;
    }

     int getCount()
    {
         return  2;
    }

    bool operator > (const Fraction &f)
    {
        if(this->denomirator == f.denomirator)
        {
            if(this->numerator > f.numerator)
            {
                return true;
            }
        }

            if(this->numerator == f.numerator)
            {
                 return true;
            
        if(this->denomirator < f.denomirator)
        {
            return true;
        }
            }
        else
        {
            return false;
        }
    }

    void show()
    {
        cout<<this->numerator<<"/"<<this->denomirator;
    }
};

int main()
{
    int newmerator , denomirator , newmoirtor_1 , denomirator_1;
    cout<<"===================First Fraction============================\n";
    cout<<"Enter the value for numerator: = ";
    cin >> newmerator;
    cout<<"Enter the value for denominator:=  ";
    cin >> denomirator;
    Fraction f1(newmerator,denomirator);
    cout<<"==================SECOND Fraction============================\n";
    cout<<"Enter the value for numerator: ";
    cin >> newmoirtor_1;
    cout<<"Enter the value for denominator: ";
    cin >> denomirator_1;
    Fraction f2(newmoirtor_1,denomirator_1);
    cout<<"\n===============NUMBER  of Fraction============================\n";
    cout<<"Number of fractions: = "<<f1.getCount();
   // cout<<"2"<<endl;
    cout<<"\n===============  ADDITION  of Fraction============================\n";
   f1+f2;
    cout<<"\n===============Multiplication   of Fraction============================\n";
    f1*f2;
    cout<<"\n=========PROPER/IMPROPER FRO FIRST FRACTION ===================\n";
    if(f1.isProper())
    {
        cout<<"The given first fraction if Proper";
    }
    else
    {
        cout<<"the given first fraction is improper";
    }
    
    cout<<"\n=========PROPER/IMPROPER FRO second FRACTION ===================\n";
    if(f2.isProper())
    {
        cout<<"The given second fraction is proper";
    }
    else
    {
        cout<<"The given second fraction is improper";
    }
    cout<<endl;
    cout<<"\n=========less than/ grater than  ===================\n";
    if(f1.operator >(f2))
    {
        cout<<"The second fraction is greater than   to the other";
    }
    else
    {
        cout<<"The first fraction is less than  to the other";
    }
    cout<<endl;
    return 0;
}

