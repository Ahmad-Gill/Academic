//
//  main.cpp
//  Lab_9
//
//  Created by Ahmad Gill on 28/04/2022.
//

#include <iostream>
using namespace std;
/*
class Tyre
{
private:
int* width;
int* aspect_ratio;
int* diameter;
public:
    Tyre(int a,int b,int c)
    {
        width = new int;
        *width = a;
        aspect_ratio = new int ;
        *aspect_ratio = b;
        diameter = new int ;
        *diameter = c;
    }
    int Get_width()
    {
        return *this->width;
    }
   int  Get_aspect_ratio()
    {
        return *this->aspect_ratio;
    }
    int  Get_diameter()
     {
         return *this->diameter;
     }
    ~Tyre()
    {
        width = NULL;
        aspect_ratio = NULL;
        diameter = NULL;
    }
//Constructors, Getters and Destructor
void PrintTyre()
    {
    cout<<"the width of the tyre is = "<<Get_width()<<endl;;
    cout<<"the diameter of the tyre is = "<<Get_diameter()<<endl;
    cout<<"the aspect retion of the tyre = "<<Get_aspect_ratio()<<endl;
    
    }
};
class Car
{
private:
int* model;
string* company;
Tyre* t1;
public:
    Car(int m,string  com,Tyre&obj )
    {
        t1 = &obj;
        model = new int ;
        *model = m;
        company = new string;
        *company = com;
        
    }
    ~Car()
    {
        model = NULL;
        company= NULL;
    }
   int get_model()
    {
       return *this->model;
   }
    string get_company()
     {
        return *this->company;
    }
//Constructors, Destructor
void PrintCar()
    {
    cout<<"the model of the car  = "<<get_model()<<endl;
    cout<<"the company of the car  is = "<<get_company()<<endl;
    cout<<"the width of the tyre is = "<<t1->Get_width()<<endl;
    cout<<"the diameter of the tyre is = "<<t1->Get_diameter()<<endl;
    cout<<"the aspect retion of the tyre = "<<t1->Get_aspect_ratio()<<endl;
    
    
}
};
int main() {
    Tyre tNew(12, 10, 13);
    Car cNew(2016,"Honda",tNew);
    cNew.PrintCar();
    return 0;
}
*/
/*
class Local_Phone
{
  
    int number;
public:
    Local_Phone(int n)
    {
        number=n;
    }
   void set_Local_Phone(int n)
    { number =n;
        
    }
   int  get_local_number()
    {
       return this->number;
    }
};
    class Nat_pjone : public Local_Phone
    {
        int code;
    public:
        Nat_pjone(int a,int  b):Local_Phone(a)
        {
            code=b;
        }
      void  set_nat_phone(int c)
        {
          code = c;
        }
        int get_Nat_cod()
        {
            return this->code;
        }
   
};
class Int_phone : public Nat_pjone
{
    int INt_code;
public:
    Int_phone(int a=0,int b=0,int c=0):  Nat_pjone(a,b)
    {
        INt_code = c;
    }
  void  get()
    {
      cout<<"National phone Number =  +"<<get_Nat_cod()<<"-"<<get_local_number()<<endl;
      cout<<"Internationsl phone Number =  +"<<this->INt_code<<"-"<<get_local_number()<<endl;
    }
};
int main() {
    int number;
    cout<<"enter the local number = ";
    cin>>number;
    int Int_code;
    int Nat_code;
    cout<<"enter the national code = ";
    cin>>Nat_code;
    cout<<"enter the International code = ";
    cin>>Int_code;
    Int_phone N1(number,Nat_code,Int_code);
    N1.get();
    return 0 ;
}

*/
class Employe
{
    string name;
    unsigned long number;
public:
    void put(string n,unsigned long num)
    {
        name = n;
        number = num;
    }
    int get_Number()
    {
        return this->number;
        
    }
    string get_name()
    {
        return this->name;
    }
    
};
class Employe_2:public Employe
{
  
    double compensasion;
    string time_to_indicate;
public:
    void IN_put(double d ,string s)
    {
        compensasion = d;
        time_to_indicate = s;
    }
    int desplay_compensasion()
    {
        return this->compensasion;
        
    }
    string get_time_to_indicate()
    {
        return this->time_to_indicate;
    }
};
int main() {
    
    return 0;
}

