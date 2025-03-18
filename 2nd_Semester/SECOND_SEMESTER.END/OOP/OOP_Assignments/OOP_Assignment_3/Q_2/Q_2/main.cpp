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
