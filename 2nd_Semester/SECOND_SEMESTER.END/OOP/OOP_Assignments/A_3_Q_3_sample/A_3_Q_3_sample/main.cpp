#include<iostream>
#include<cstring>
using namespace std;
class Roman_Number
{
  private:
      char Roman[100];
      char tens;
      char hundreds;
      char units;
      char thousands;
      char fifty;
      char five_hundred;
      char five;
      int Decimal_Number;
  public:
      Roman_Number()
      {
          Roman[100] = '\0';
          units = 'I';
          tens = 'X';
          hundreds = 'C';
          fifty = 'L';
          five_hundred = 'D';
          thousands = 'M';
          five = 'V';
          Decimal_Number = 0;
      }
      void SetRomanNumber(char R[100])
      {
          strcpy(Roman , R);
      }
      char *GetRomanNumber()
      {
          return Roman;
      }

      // Converting Roman Number in Simple Number

      int Conversion_Roman_To_Decimal()
      {
          Decimal_Number = 0;
          for(int i = 0 ; i < sizeof(Roman) ; i++)
          {
              if(Roman[i]== units && Roman[i+1] == five)
              {
                  Decimal_Number = Decimal_Number + 4;
                  break;
              }
              if(Roman[i] == units && Roman[i+1] == tens)
              {
                  Decimal_Number = Decimal_Number + 9;
                  break;
              }
              if(Roman[i] == tens && Roman[i+1] == fifty)
              {
                  Decimal_Number = Decimal_Number + 40;
                  break;
              }
              if(Roman[i] == tens && Roman[i+1] == hundreds)
              {
                  Decimal_Number = Decimal_Number + 90;
                  break;
              }
              if(Roman[i] == hundreds && Roman[i+1] == five_hundred)
              {
                  Decimal_Number = Decimal_Number + 400;
                  break;
              }
              if(Roman[i] == hundreds && Roman[i] == thousands)
              {
                  Decimal_Number = Decimal_Number + 900;
                  break;
              }
              if(Roman[i] == units)
              {
                  Decimal_Number = Decimal_Number + 1;
              }
              if(Roman[i] == five)
              {
                  Decimal_Number = Decimal_Number + 5;
              }
              if(Roman[i] == tens)
              {
                  Decimal_Number = Decimal_Number + 10;
              }
              if(Roman[i] == fifty)
              {
                  Decimal_Number = Decimal_Number + 50;
              }
              if(Roman[i] == hundreds)
              {
                  Decimal_Number = Decimal_Number + 100;
              }
              if(Roman[i] == five_hundred)
              {
                  Decimal_Number = Decimal_Number + 500;
              }
              if(Roman[i] == thousands)
              {
                  Decimal_Number = Decimal_Number + 1000;
              }
          }
          return Decimal_Number;
      }

      //Adding Two Roman Numbers
      void operator+(Roman_Number &r1)
      {
          int Add = 0;
          Add = Decimal_Number + r1.Conversion_Roman_To_Decimal();
          cout<<"The Roman Numbers After Addition In Decimal Form: ";
          cout<<Add;
          cout<<endl;
          cout<<"The Roman Numbers After Addition In Roman Format: ";
          for(int i = 0 ; i < sizeof(Roman) ; i++)
          {
              while(Add >= 1000)
              {
                  cout<<"M";
                  Add = Add - 1000;
              }
              while(Add == 900)
              {
                  cout<<"CM";
                  Add = Add - 900;
              }
              while(Add >= 500)
              {
                  cout<<"D";
                Add = Add - 500;
              }
              while(Add == 400)
              {
                  cout<<"CD";
                  Add = Add - 400;
              }
              while(Add >= 100)
              {
                  cout<<"C";
                  Add = Add - 100;
              }
              while(Add == 90)
              {
                  cout<<"XC";
                  Add = Add - 90;
              }
              while(Add >= 50)
              {
                  cout<<"L";
                  Add = Add - 50;
             }
             while(Add == 40)
             {
                 cout<<"XL";
                 Add = Add -40;

             }
              while(Add == 9)
              {
                  cout<<"IX";
                  Add = Add - 9;
              }
              while(Add >= 10)
              {
                  Add = Add - 10;
                  cout<<"X";
              }
              while(Add == 4)
              {
                  cout<<"IV";
                  Add=Add-5;
              }
              while(Add >= 5)
              {
                  cout<<"V";
                  Add = Add - 5;
              }

              while(Add >= 1)
               {
                  cout<<"I";
                  Add = Add - 1;
              }
          }
      }
    // Subtracting Two Roman Numbers
     void operator - (Roman_Number &r1)
     {
          int Sub = 0;
          Sub = Decimal_Number - r1.Conversion_Roman_To_Decimal();
          cout<<"The Roman Numbers After Subtraction In Decimal Form: ";
          if(Sub < 0)
          {
              Sub = Sub * (-1);
          }
          cout<<Sub;
          cout<<endl;
          cout<<"The Roman Numbers After Subtraction In Roman Format: ";
          for(int i = 0 ; i < sizeof(Roman) ; i++)
          {
              if(Sub == 0)
              {
                  cout<<" ";
              }
              while(Sub >= 1000)
              {
                  cout<<"M";
                  Sub = Sub - 1000;
              }
              while(Sub == 900)
              {
                  cout<<"CM";
                  Sub = Sub - 900;
              }
              while(Sub >= 500)
              {
                cout<<"D";
                Sub = Sub - 500;
              }
              while(Sub == 400)
              {
                  cout<<"CD";
                  Sub = Sub - 400;
              }
              while(Sub >= 100)
              {
                  cout<<"C";
                  Sub = Sub - 100;

              }
              while(Sub == 90)
              {
                  cout<<"XC";
                  Sub = Sub - 90;
              }
              while(Sub >= 50)
              {
                  cout<<"L";
                  Sub = Sub - 50;
              }
              while(Sub == 40)
              {
                  cout<<"XL";
                  Sub = Sub - 40;
              }
              while(Sub >= 10)
              {
                  Sub = Sub - 10;
                  cout<<"X";
              }
                while(Sub == 9)
              {
                  Sub = Sub -9;
                  cout<<"IX";
              }
              while(Sub >= 5)
              {
                  cout<<"V";
                  Sub = Sub - 5;
              }
              while(Sub == 4)
              {
                  cout<<"IV";
                  Sub = Sub -4;
              }
              while(Sub >= 1)
               {
                  cout<<"I";
                  Sub = Sub - 1;
              }
          }
     }
     // Multiplying two Roman Numbers
     void operator*(Roman_Number &r1)
     {
         int Mul = 0;
          Mul = Decimal_Number * r1.Conversion_Roman_To_Decimal();
          cout<<"The Roman Numbers After Multiplication In Decimal Form: ";
          cout<<Mul;
          cout<<endl;
          cout<<"The Roman Numbers After Multiplication In Roman Format: ";
          for(int i = 0 ; i < sizeof(Roman) ; i++)
          {
              while(Mul >= 1000)
              {
                  cout<<"M";
                  Mul = Mul - 1000;
              }
              while(Mul == 900)
              {
                  cout<<"CM";
                  Mul = Mul - 900;
              }
              while(Mul >= 500)
              {
                  cout<<"D";
                Mul = Mul - 500;
              }
              while(Mul == 400)
              {
                  cout<<"CD";
                  Mul = Mul - 400;
              }
              while(Mul >= 100)
              {
                  cout<<"C";
                  Mul = Mul - 100;
              }
              while(Mul == 90)
              {
                  cout<<"XC";
                  Mul = Mul - 90;
              }
              while(Mul >= 50)
              {
                  cout<<"L";
                  Mul = Mul - 50;
              }
              while(Mul == 40)
              {
                  cout<<"XL";
                  Mul = Mul - 40;
              }
              while(Mul >= 10)
              {
                  Mul = Mul - 10;
                  cout<<"X";
              }
              while(Mul == 9)
              {
                  cout<<"IX";
                  Mul = Mul - 9;
              }
              while(Mul >= 5)
              {
                  cout<<"V";
                  Mul = Mul - 5;
              }
              while(Mul == 4)
              {
                  cout<<"IV";
                  Mul = Mul - 4;
              }
              while(Mul >= 1)
               {
                  cout<<"I";
                  Mul = Mul - 1;
              }
          }
     }

     // Dividing Two Roman Numbers
     void operator/ (Roman_Number &r1)
     {
          float Div ;
          Div = Decimal_Number / r1.Decimal_Number;
          cout<<"The Roman Numbers After Division In Decimal Form: ";
          cout<<Div;
          cout<<endl;
          cout<<"The Roman Numbers After Division In Roman Format: ";
          for(int i = 0 ; i < sizeof(Roman) ; i++)
          {
              while(Div >= 1000)
              {
                  cout<<"M";
                  Div = Div - 1000;
              }
              while(Div == 900)
              {
                  cout<<"CM";
                  Div = Div - 900;
              }
              while(Div >= 500)
              {
                  cout<<"D";
                Div = Div - 500;
              }
              while(Div == 400)
              {
                  cout<<"CD";
                  Div = Div - 400;
              }
              while(Div >= 100)
              {
                  cout<<"C";
                  Div = Div - 100;
              }
              while(Div == 90)
              {
                  cout<<"XC";
                  Div = Div - 90;
              }
              while(Div >= 50)
              {
                  cout<<"L";
                  Div = Div - 50;
              }
              while(Div == 40)
              {
                  cout<<"XL";
                  Div = Div - 40;
              }
              while(Div >= 10)
              {
                  Div = Div - 10;
                  cout<<"X";
              }
              while(Div == 9)
              {
                  cout<<"IX";
                  Div = Div  - 9;
              }
              while(Div >= 5)
              {
                  cout<<"V";
                  Div = Div - 5;
              }
              while(Div == 4)
              {
                  cout<<"IV";
                  Div = Div - 4;
              }
              while(Div >= 1)
               {
                  cout<<"I";
                  Div = Div - 1;
              }
          }
     }


     // Postfix Implementation(Increment)
     void operator++(int)
     {
         int D = Conversion_Roman_To_Decimal();
         cout<<D++;
     }
     // Postfix Implementation(Decrement)
      void operator--(int)
     {
         int D = Conversion_Roman_To_Decimal();
         cout<<D--;
     }

     // Prefix Implementation(Increment)
      void operator++()
      {
          int D = Conversion_Roman_To_Decimal();
          cout<<(++D);
      }

       // Prefix Implementation(Decrement)
        void operator--()
      {
          int D = Conversion_Roman_To_Decimal();
          cout<<(--D);
      }
      // Checking The Equality of Two Roman Numbers
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

      // Checking the InEquality of Two Roman Numbers
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

      // Checking for the Largest Roman Numbers
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

      // Checking for the Smallest Roman Number
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
    char roman[100] , roman1[100];
    int size =0 , size1=0;
    cout << "Enter the size for array for first roman number: ";
    cin >> size;
    cout<<"Enter 1st Roman Number: ";
    for(int i = 0 ; i < size ; i++)
    {
        cin>>roman[i];
    }
    cout << "Enter the size for second roman number: ";
    cin >> size1;
    cout<<"Enter 2nd Roman Number: ";
    for(int i = 0 ; i < size1 ; i++)
    {
        cin>>roman1[i];
    }
    r1.SetRomanNumber(roman);
    r2.SetRomanNumber(roman1);
    cout<<endl;
    cout<<"Decimal Equivalent of the First Roman Number is: "<<r1.Conversion_Roman_To_Decimal();
    cout<<endl;
    cout<<"Decimal Equivalent of the Second Roman Number is: "<<r2.Conversion_Roman_To_Decimal();
    cout<<endl;
    cout<<endl;
    r1 + r2;
    cout<<endl;
    cout<<endl;
    r1-r2;
    cout<<endl;
    cout<<endl;
    r1*r2;
    cout<<endl;
    cout<<endl;
    r1/r2;
    cout<<endl;
    cout<<endl;
    cout<<"____________________________________________________"<<endl;
    cout<<"COMPARING THE NUMERALS"<<endl;
   if(r1.operator==(r2) == 1)
    {
        cout<<"Both the numerals are equal";
        cout<<endl;
    }
    else
    {
        cout<<"Both the numerals are not equal to each other";
        cout<<endl;
    }
    if(r1.operator>(r2) == 1)
    {
        cout<<"First Numeral is Greater than the other"<<endl;
    }
    if(r1.operator<(r2) == 1)
    {
        cout<<"First Numeral is Smaller than the other";
        cout<<endl;
    }
    cout<<"__________________________________________________"<<endl;
    cout<<"Prefix Increment Implementation"<<endl;
    cout<<"First Numeral: ";
    ++r1;
    cout<<endl;
    cout<<"Second Numeral: ";
    ++r2;
    cout<<endl;
    cout<<"Prefix Decrement Implementation"<<endl;
    cout<<"First Numeral: ";
    --r1;
    cout<<endl;
    cout<<"Second Numeral: ";
    --r2;
    cout<<endl<<endl;
    cout<<"___________________________________________________"<<endl;
    cout<<endl;
    cout<<"Postfix Increment Implementation";
    cout<<endl;
    cout<<"First Numeral: ";
    r1++;
    cout<<endl;
    cout<<"Second Numeral: ";
    r2++;
    cout<<endl;
    cout<<endl;
    cout<<"Postfix Decrement Implementation";
    cout<<endl;
    cout<<"First Numeral: ";
    r1--;
    cout<<endl;
    cout<<"Second Numeral: ";
    r2--;
    cout<<endl;
    return 0;
}
