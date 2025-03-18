//
//  main.cpp
//  21L-5617(ASSIGNMENT_3_COMPLETE)
//
//  Created by Ahmad Gill on 24/05/2022.
//



//  main.cpp

//  Q_1

//

//  Created by Ahmad Gill on 18/04/2022.

//
#include <iostream>
#include <cmath>

using namespace std;

class VectorType

{

    double *x;

    double *y;

    double *z;

public:

   VectorType(double a=0.0,double b= 0.0,double c=0.0)

    {

        x=new double;

        y= new double;

        z= new double;
       *x = a;
       *y = b;
       *z = c;
    }
    friend istream & operator >>(istream &, VectorType & );
    friend ostream & operator <<(ostream &, VectorType & );
    friend void operator == (const VectorType & , const VectorType &);
    friend void operator !=(const VectorType &,const VectorType &);
    
    VectorType(VectorType&obj)

    {
        obj.x =this->x;

        obj.y = this->y;

        obj.z= this->z;
    }
    double operator*(VectorType & obj)

    {
        double W;
        W = ((*this->x)*(*(obj.x)))+((*this->y)*(*(obj.y)))+((*this->z)*(*(obj.z)));
        return W;
    }
    double Length()
    {
        double P;
        P=   sqrt((((*this->x)*(*this->x))+((*this->y)*(*this->y))+((*this->z)*(*this->z))));
        return P;
    }
    double Angle(double dot_product,double L_U,double L_V)
    {
        double x= L_V*L_U;
        double angle;
        angle =acos((dot_product/x));
        angle =  angle*(180/3.14);
        return angle;
    }
    VectorType operator+(VectorType & obj)
    {
        VectorType A;
        *A.x= (*this->x)+(*obj.x);
        *A.y= (*this->y)+(*obj.y);
        *A.z= (*this->z)+(*obj.z);
        
        return A;
    }
    VectorType operator-(VectorType & obj)
    {
        VectorType A;
        *A.x= (*this->x)-(*obj.x);
        *A.y= (*this->y)-(*obj.y);
        *A.z= (*this->z)-(*obj.z);
        
        return A;
    }
    void operator ++()
    {
      
        cout<<"("<<(*this->x)++<<" , "<<(*this->y)++<<" , "<<(*this->z)++<<" ) \n";
      
    }
    void operator ++(int)
    {
    
        cout<<"("<<++(*this->x)<<" , "<<++(*this->y)<<" , "<<++(*this->z)<<" ) \n";
       
    }
    void operator --()
    {
     
        cout<<"("<<(*this->x)--<<" , "<<(*this->y)--<<" , "<<(*this->z)--<<" ) \n";
       
    }
    void operator --(int)
    {
      
        cout<<"("<<--(*this->x)<<" , "<<--(*this->y)<<" , "<<--(*this->z)<<" ) \n";
    }
    double get_x()
    {
        return *this->x;
    }
    double get_y()
    {
        return *this->y;
    }
    double get_z()
    {
        return *this->z;

    }
    ~VectorType()
    {
    x=NULL;
    y=NULL;
    z=NULL;
    }
};
istream & operator >>(istream  & input,VectorType & obj )
{
    cout<<"enter the value of first integer : ";
    input>>*obj.x;
    cout<<"enter the value of second integer : ";
    input>>*obj.y;
    cout<<"enter the value of third integer : ";
    input>>*obj.z;
  
    return input;
}
ostream & operator <<(ostream  & output,VectorType & obj )
{
    output<<"("<<*obj.x<<" , "<<*obj.y<<" , "<<*obj.z<<" ) \n";
  
    return output;
}

void  operator ==(VectorType &obj,VectorType &obj1)

{
    
   
   if(((obj.get_x())==(obj1.get_x()))&&((obj.get_y())==(obj1.get_y()))&&((obj.get_z())==(obj1.get_z())))
       cout<<"the vectors are same :";
    else
        cout<<" the given vectors are not same ";
}

void   operator !=(VectorType &obj,VectorType obj1)
{
   
    if(((obj.get_x())!=(obj1.get_x()))&&((obj.get_y())!=(obj1.get_y()))&&((obj.get_z())!=(obj1.get_z())))
        cout<<" the given vectors are not same";
    else
        cout<<"  ";
    
}
int main() {
   
    VectorType U;
    VectorType V;
    cout<<"input of first vector : \n";
    cin>>U;
    cout<<"\ninput of second vector : \n";
    cin>>V;
    cout<<"output of first vector : ";
    cout<<U;
    cout<<"output of second vector : ";
    cout<<V;
 
    cout<<"equality test : = ";
    U==V;
    cout<<endl;
      VectorType W1;
    cout<<"the Dot product of two vectors : = ";
    double product;
    product = U*V;
    cout<<product;
    cout<<endl;
    double P = U.Length();
    double P1 = V.Length();
    cout<<"length of first vectore : = "<<P<<endl;
    cout<<"length of second vectore : = "<<P1<<endl;
    double Anglel;
    Anglel =    U.Angle(product, P, P1);
    cout<<"angle between these two vectors is : = ";
    cout<<Anglel<<endl;
    VectorType Plus;
    cout<<"the sum of two vectors : ";
    Plus =   U+V;
    cout<<"("<<  Plus.get_x()<<" , "<<Plus.get_y()<<" , "<<Plus.get_z()<<" ) \n";
    VectorType Minus;
    cout<<"the subtraction of two vectors : ";
    Minus = U-V;
    cout<<"("<<Minus.get_x()<<" , "<<Minus.get_y()<<" , "<<Minus.get_z()<<" ) \n";
    cout<<"=======for first vector======\n";
    cout<<"pre increment in first vector ";
    ++U;
    cout<<"post increment in first vector ";
    U++;
    cout<<"pre decrement  in first vector ";
    --U;
    cout<<"post decrement in first vector ";
    U--;
    cout<<"=======for second vectoe=======\n";
    cout<<"pre increment in first vector ";
    ++V;
    cout<<"post increment in first vector ";
    V++;
    cout<<"pre decrement  in first vector ";
    --V;
    cout<<"post decrement in first vector ";
    V--;
  
  
    return 0;
    

}


//  main.cpp
//  Q_2
//
//  Created by Ahmad Gill on 20/04/2022.
//
#include <iostream>
using namespace std;
class Strings
{
    char  *str;
    int length;
    string  *new_str;
    string *New_str;
public:
    Strings(int x)
    {
        this->length = x;
        str = new char[this->length];New_str = new string[this->length+1];
        for(int j=0;j<this->length;j++)
            this->str[j]=' ';
    }
    friend istream & operator >>(istream &, Strings & );
    friend ostream & operator <<(ostream &, Strings & );
   void operator ==(Strings &S1)
    { int counter=0;
       for(int i=0;i<this->length;i++)
       {
           if(S1.str[i]==this->str[i])
               counter ++;
       }
           if (counter==S1.length)
               cout<<"the both strings are same \n";
   }
    void operator >(Strings &S1)
     { int counter=0;
        for(int i=0;i<this->length;i++)
        {
            if(S1.str[i]>this->str[i])
                counter ++;
        }
            if (counter>=1)
                cout<<"the string is greater then th eother \n";
    }
    void operator < (Strings &S1)
     { int counter=0;
        for(int i=0;i<this->length;i++)
        {
            if(S1.str[i]<this->str[i])
                counter ++;
        }
            if (counter>=1)
                cout<<"the string is smaller than the other ";
    }
    void operator !=(Strings &S2)
     {
       int counter=0;
        for(int i=0;i<this->length;i++)
        {
            if(S2.str[i]!=this->str[i])
                counter ++;
        }
            if(counter >=1)
                cout<<"the both strings are  not same ";
    }
    void operator [] (int index)
    {
        while(index<0||index>this->length)
        {
            cout<<"envalid Input  :: enter the in dex again : = ";
            cin>>index;
        }
        cout<< this->str[index];
    }
    void Sub_String(char a ,char b)
    {
        char *s =new char [this->length] ;
        int counter =0;
        for(int i=0;i<=this->length;i++)
        {
            cout<<s[i];
        }
        while(this->str[counter]!=a)
            counter++;
        for(int i=0;i<=length;i++)
        {
            if(this->str[i]==a)
            {
                s[i]=this->str[i];
                for(int j=i+1;str[j]!=b;j++)
                    s[j]=str[i+j];
            }
        }
       for(int i=0;i<=this->length;i++)
            cout<<s[i];
        cout<<"\nthe requird index is "<<counter;
    }
    void Lower_case()
    {
        for(int i=0;i<=this->length;i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
                        str[i] = str[i] + 32;
            else
                this->str[i]=this->str[i];
       }
        for(int i=0;i<=this->length;i++)
            cout<<this->str[i];
    }
    void Upper_case()
    {
        for(int i=0;i<=this->length;i++)
        {

         if(this->str[i] >= 'a' && this->str[i] <= 'z') {
             this->str[i]=this->str[i]-32;
           }
         else
             this->str[i]=this->str[i];
       }
        for(int i=0;i<=this->length+1;i++)
            cout<<this->str[i];
    }
    void operator + ()
    {
        new_str = new string[this->length+1];
        for(int i=0;i<=this->length;i++)
        {
            this->new_str[i] = this->str[i];
        }
        cout<<"\n=============the addition of integer : ===================\n";
        cout<<"\nenter the integer : ";
        for(int i=this->length;i<this->length+1;i++)
            cin>> new_str[this->length+1];
        for(int i=0;i<=this->length+1;i++)
            cout<<new_str[i];
        cout<<"\n===============the addition string : ======================\n";
            cout<<"\nenter the string ";
        for(int i=this->length;i<this->length+1;i++)
            cin>> new_str[this->length+1];
        for(int i=0;i<=this->length+1;i++)
            cout<<new_str[i];
        cout<<"\n==================the addition of char ==================\n";
            cout<<"enter the char ";
        for(int i=this->length;i<this->length+1;i++)
            cin>> new_str[this->length+1];
        for(int i=0;i<=this->length+1;i++)
            cout<<new_str[i];
        cout<<"\n=============the addition of float value=====================\n";
            cout<<"enter the float value ";
        for(int i=this->length;i<this->length+1;i++)
            cin>> new_str[this->length+1];
        for(int i=0;i<=this->length+1;i++)
            cout<<new_str[i];
    }
    void operator+(int  x)
    {   New_str = new string[this->length+1];
        New_str = new string[this->length+1];
        for(int i=0;i<=this->length+1;i++)
        {
            this->New_str[i+1] = this->str[i];
        }
        cout<<"\n=============the addition of integer : ===================\n";
        cout<<"\nenter the integer : ";
        for(int i=this->length;i<this->length+1;i++)
            cin>> New_str[0];
        for(int i=0;i<=this->length+1;i++)
            cout<<New_str[i];
        cout<<"\n===============the addition string : ======================\n";
            cout<<"\nenter the string ";
        for(int i=this->length;i<this->length+1;i++)
            cin>> New_str[0];
        for(int i=0;i<=this->length+1;i++)
            cout<<New_str[i];

        cout<<"\n==================the addition of char ==================\n";
            cout<<"enter the char ";
        for(int i=this->length;i<this->length+1;i++)
            cin>> New_str[0];
        for(int i=0;i<=this->length+1;i++)
            cout<<New_str[i];
        cout<<"\n=============the addition of float value=====================\n";
            cout<<"enter the float value ";
        for(int i=this->length;i<this->length+1;i++)
            cin>> New_str[0];
        for(int i=0;i<=this->length+1;i++)
            cout<<New_str[i];
    }
};
istream & operator >>(istream & input,Strings& str1)
{   cout<<"enter the string ";
    for(int i=0;i<str1.length;i++)
        input>>str1.str[i];
    return input;
}
ostream & operator <<(ostream & output,Strings& str1)
{   cout<<"the orignal string is : = ";
    for(int i=0;i<str1.length;i++)
    output<<str1.str[i];
    return output;
}

int main() {
    cout<<"enter the size of string : = ";
    int a;
    cin>>a;
    cout<<"===================FIRST STRING=================\n";
    Strings S1(a);
    cin>>S1;
    cout<<S1;
    cout<<endl;
    cout<<"===================SECOND STRING=================\n";
    Strings S2(a);
    cin>>S2;
    cout<<S2;
    cout<<endl;
    cout<<"===================USING OPERATORS=================\n";
    S1==S2;
    cout<<endl;
    S1>S2;
    cout<<endl;
    S1<S2;
    cout<<endl;
    S1!=S2;
    cout<<endl;
    int x;
    cout<<"================Search the word at  index : ========\n ";
    cout<<"enter the index : ";
    cin>>x;
    cout<<"the word at this index is : ";
    S1[x];
    cout<<"\n================substring======================= \n ";
    char q,v;
    cout<<"enter the first charactor : ";
    cin>>q;
    cout<<"enter the second charactor : ";
    cin>>v;
    S1.Sub_String(q, v);
    cout<<endl<<"===================lower case ===================\n ";
    S1.Lower_case();
    cout<<"\n==========================upper case==================\n ";
    S1.Upper_case();
    cout<<endl;
    cout<<endl<<"==========POST CATINATION==========================\n";
    S1.operator+();
    cout<<endl;
    cout<<"=================PRE CATIBATION==========================\n";
    S1.operator+(1);
    cout<<endl;
    return 0;
}


#include<iostream>
#include<cstring>
using namespace std;
class Roman_Number
{
  private:
      char Roman_Numbers[100];
      char ten;
      char hundred;
      char unit;
      char thousand;
      char fifty;
      char five_hundred;
      char five;
      int Decimal_Number;
public:
      Roman_Number()
      {
          Roman_Numbers[100] = '\0';
          unit = 'I';
          ten = 'X';
          hundred = 'C';
          fifty = 'L';
          five_hundred = 'D';
          thousand = 'M';
          five = 'V';
          Decimal_Number = 0;
      }
      void SetRomanNumber(char R[100])
      {
          strcpy(Roman_Numbers , R);
      }
      char *GetRomanNumber()
      {
          return Roman_Numbers;
      }
      int Conversion_Roman_To_Decimal()
      {
          Decimal_Number = 0;
          for(int i = 0 ; i < sizeof(Roman_Numbers) ; i++)
          {
              if(Roman_Numbers[i]== unit && Roman_Numbers[i+1] == five)
              {
                  Decimal_Number = Decimal_Number + 4;
                  break;
              }
              if(Roman_Numbers[i] == unit && Roman_Numbers[i+1] == ten)
              {
                  Decimal_Number = Decimal_Number + 9;
                  break;
              }
              if(Roman_Numbers[i] == ten && Roman_Numbers[i+1] == fifty)
              {
                  Decimal_Number = Decimal_Number + 40;
                  break;
              }
              if(Roman_Numbers[i] == ten && Roman_Numbers[i+1] == hundred)
              {
                  Decimal_Number = Decimal_Number + 90;
                  break;
              }
              if(Roman_Numbers[i] == hundred && Roman_Numbers[i+1] == five_hundred)
              {
                  Decimal_Number = Decimal_Number + 400;
                  break;
              }
              if(Roman_Numbers[i] == hundred && Roman_Numbers[i] == thousand)
              {
                  Decimal_Number = Decimal_Number + 900;
                  break;
              }
              
                  if(Roman_Numbers[i] == unit)
                  {
                      Decimal_Number = Decimal_Number + 1;
                  }
                  if(Roman_Numbers[i] == five)
                  {
                      Decimal_Number = Decimal_Number + 5;
                  }
                  if(Roman_Numbers[i] == ten)
                  {
                      Decimal_Number = Decimal_Number + 10;
                  }
                  if(Roman_Numbers[i] == fifty)
                  {
                      Decimal_Number = Decimal_Number + 50;
                  }
                  if(Roman_Numbers[i] == hundred)
                  {
                      Decimal_Number = Decimal_Number + 100;
                  }
                  if(Roman_Numbers[i] == five_hundred)
                  {
                      Decimal_Number = Decimal_Number + 500;
                  }
                  if(Roman_Numbers[i] == thousand)
                  {
                      Decimal_Number = Decimal_Number + 1000;
                  }
             
          }
          return Decimal_Number;
      }
    int  operator +(Roman_Number &r1)
    {
        int plus= this->Decimal_Number+r1.Decimal_Number;
        return plus;
    }
    int  operator -(Roman_Number &r1)
    {
        int Minus= this->Decimal_Number-r1.Decimal_Number;
        return Minus;
    }
    int  operator *(Roman_Number &r1)
    {
        int Multiply= this->Decimal_Number*r1.Decimal_Number;
        return Multiply;
    }
    int  operator /(Roman_Number &r1)
    {
        int dev= this->Decimal_Number/r1.Decimal_Number;
        return dev;
    }
    void decimal_to_Roman(int value)
    {
        if(value<0)
        {
            value =value*-1;
        }
        for(int i = 0 ; i < sizeof(Roman_Numbers) ; i++)
        {
            if(value == 0)
            {
                cout<<" ";
            }
            while(value >= 1000)
            {
                cout<<"M";
                value = value - 1000;
            }
            while(value == 900)
            {
                cout<<"CM";
                value = value - 900;
            }
            while(value >= 500)
            {
              cout<<"D";
              value = value - 500;
            }
            while(value == 400)
            {
                cout<<"CD";
                value = value - 400;
            }
            while(value >= 100)
            {
                cout<<"C";
                value = value - 100;

            }
            while(value == 90)
            {
                cout<<"XC";
                value = value - 90;
            }
            while(value >= 50)
            {
                cout<<"L";
                value = value - 50;
            }
            while(value == 40)
            {
                cout<<"XL";
                value = value - 40;
            }
            while(value >= 10)
            {
                value = value - 10;
                cout<<"X";
            }
              while(value == 9)
            {
                value = value -9;
                cout<<"IX";
            }
            while(value >= 5)
            {
                cout<<"V";
                value = value - 5;
            }
            while(value == 4)
            {
                cout<<"IV";
                value = value -4;
            }
            while(value >= 1)
             {
                cout<<"I";
                value = value - 1;
            }
        }
    }

    int operator++()
    {
        return ++this->Decimal_Number;
    }

     int operator++(int)
     {
         return this->Decimal_Number++;
     }
  
    
    int operator--()
  {
        return --this->Decimal_Number;
  }
      int operator--(int)
     {
          return this->Decimal_Number--;
     }
      bool operator==(Roman_Number &r1)
      {
          if(this->Decimal_Number == r1.Decimal_Number)
          {
              return true;
          }
          else
          {
              return false;
          }
      }
    

      bool operator != (Roman_Number &r1)
      {
          if(this->Decimal_Number != r1.Decimal_Number)
          {
              return true;
          }
          else
          {
              return false;
          }
      }
      bool operator > (Roman_Number &r1)
      {
        if(this->Decimal_Number > r1.Decimal_Number)
        {
            return true;
        }
          else
          {
              return false;
          }
    }

      bool operator < (Roman_Number &r1)
      {
          if(this->Decimal_Number < r1.Decimal_Number)
          {
              return true;
          }
          else
          {
              return false;
          }
      }
};

int main()
{
    
    Roman_Number r1 , r2;
    char roman_Number1[100] , roman_Number2[100];
    int size =0 , size1=0;
    cout << "Enter the size for array for first roman number: ";
    cin >> size;
    cout<<"Enter 1st Roman Number: ";
    for(int i = 0 ; i < size ; i++)
    {
        cin>>roman_Number1[i];
    }
    cout << "Enter the size for second roman number: ";
    cin >> size1;
    cout<<"Enter 2nd Roman Number: ";
    for(int i = 0 ; i < size1 ; i++)
    {
        cin>>roman_Number2[i];
    }
    int Decimal_1=0;
    r1.SetRomanNumber(roman_Number1);
    r2.SetRomanNumber(roman_Number2);
    cout<<endl;
   
    cout<<"Decimal Equivalent of the First Roman Number is: ";
    Decimal_1=r1.Conversion_Roman_To_Decimal();
    cout<<Decimal_1;
    cout<<endl;
    int Decimal_2=0;
    cout<<"Decimal Equivalent of the Second Roman Number is: ";
   Decimal_2 = r2.Conversion_Roman_To_Decimal();
    cout<<Decimal_2;
    cout<<endl;
    cout<<"==============ADDITION OF NUMBERS=====================\n";
    cout<<"Addition of two decimal numbers : ";
  int Plus =   r1 + r2;
    cout<<Plus;
    cout<<endl<<"Addition of two ROMAN numbers : ";
    r2.decimal_to_Roman(Plus);
    cout<<endl;
    cout<<"===============SUBTRACTION OF TWO NUMBERS==================\n";
   int Minus=  r1-r2;
    cout<<endl<<"Subtraction of two decimal numbers : ";
    cout<<Minus;
    cout<<endl;
    cout<<"SUBTRACTION of two roman numbers : ";
    r1.decimal_to_Roman(Minus);
    cout<<"\n========MULTIPLICATION OF TWO NUMBERS==================\n";
    cout<<"MULTIPLICATION  of two decimal numbers : ";
   int Multiply =  r1*r2;
    cout<<Multiply;
    cout<<endl<<"MULTIPLICATION of two roman numbers : ";
    r1.decimal_to_Roman(Multiply);
    cout<<endl<<"===========DEVISION OF TWO NUMBERS=======================\n";
    cout<<endl<<"DIVISION of two decimal numbers : ";
    int dev=  r1/r2;
    cout<<dev;
    cout<<endl<<"DIVISION of two Roman numbers : ";
    r1.decimal_to_Roman(dev);
    cout<<endl;
    cout<<"==========COMPARISON OF NUMBERS==========================="<<endl;
   if(r1==r2)
    {
        cout<<"Both the numerals are equal";
        cout<<endl;
    }
    else
    {
        cout<<"Both the numerals are not equal to each other";
        cout<<endl;
    }
    if(r1>r2 )
    {
        cout<<"First Numeral is Greater than the other"<<endl;
    }
    if(r1<r2)
    {
        cout<<"First Numeral is Smaller than the other";
        cout<<endl;
    }
    cout<<"=================ALGEBRIC OPERATIONS =========================\n";
    cout<<"==================FIRST NUMBER=========================\n";
    cout<<"Postfix Increment Implementation \n ";
  cout<<"IN Decimal Number : =  ";
   int Post_incr_1=  r1++;
    
    cout<< Post_incr_1<<endl;
    cout<<"IN roman Number : ";
    r1.decimal_to_Roman(Post_incr_1);
    cout<<"\nPrefix Increment Implementation : \n ";
    cout<<"IN DECIMAL ";
    int Pre_incr_1 = ++r1;
    cout<<Pre_incr_1;
    cout<<endl;
    
    cout<<"IN roman Number : ";
    r1.decimal_to_Roman(Pre_incr_1);
    cout<<"\nPOSTFIX decrement : \n";
    cout<<"IN decimal value : = ";
   int Post_dec_1=  r1--;
    cout<<Post_dec_1<<endl;
    cout<<"IN roman Number : ";
    r1.decimal_to_Roman(Post_dec_1);
    
    cout<<"\nPrefix Decrement Implementation : \n";
    cout<<"IN Decimal Numeral: ";
   int Pre_dec_1=  --r1;
    cout<<Pre_dec_1<<endl;
    cout<<"IN roman Number : ";
    r1.decimal_to_Roman(Pre_dec_1);
    cout<<endl;
   
    cout<<"==================SECOND NUMBER===================="<<endl;
    cout<<"Postfix Increment Implementation : \n ";
  cout<<"IN Decimal Number : ";
   int Post_incr_2=  r2++;
    
    cout<< Post_incr_2<<endl;
    cout<<"IN roman Number : ";
    r1.decimal_to_Roman(Post_incr_2);
    cout<<"\nPrefix Increment Implementation : \n ";
    cout<<"IN DECIMAL ";
    int Pre_incr_2 = ++r2;
    cout<<Pre_incr_2;
    cout<<endl;
    
    cout<<"IN roman Number : ";
    r1.decimal_to_Roman(Pre_incr_2);
    cout<<"\nPOSTFIX decrement   \n";
    cout<<" IN decimal value : = ";
   int Post_dec_2=  r2--;
    cout<<Post_dec_2<<endl;
    cout<<"IN roman Number : ";
    r1.decimal_to_Roman(Post_dec_2);
    
    cout<<"\nPrefix Decrement Implementation :\n ";
    cout<<"IN Decimal Numeral: ";
   int Pre_dec_2=  --r2;
    cout<<Pre_dec_2<<endl;
    cout<<"IN roman Number : ";
    r1.decimal_to_Roman(Pre_dec_2);
    cout<<endl;
   
    return 0;
}
