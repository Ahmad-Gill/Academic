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
