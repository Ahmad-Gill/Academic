//
//  main.cpp
//  lab_11_Q_2
//
//  Created by Ahmad Gill on 27/05/2022.
//

#include <iostream>
using namespace std;
class Account
{
protected:
    int Account_Number;
    double Account_Ballance;
public:
    void set_A_N(int n)
    {
      
        this->Account_Number=n;
    }
    void set_A_B(double b)
    {
      
        this->Account_Ballance=b;
    }
    
    int get_A_N()
    {
        return this->Account_Number;
    }
    double get_A_B()
    {
        return this->Account_Ballance;
    }
    virtual void credit(double b)
    {
       // cout<<b<<endl;
        this->Account_Ballance=this->Account_Ballance+b;
    }
    virtual void debit(double b)
    {
        this->Account_Ballance= this->Account_Ballance-b;
    }
virtual void print()
    {
        cout<<"the account number is "<<this->Account_Number;
        cout<<"\n the account ballance is "<<this->Account_Ballance;
    }
};
class current_Account : public Account
{
protected:
    Account A;
    double Service_chage;
    double Minimum_ballance;
public:
   void Set(double m)
    {
       this->Minimum_ballance=m;
       this->Service_chage=0;
       if(Account_Ballance<Minimum_ballance)
           this->Service_chage=100;
           
   }
    void Set_balance(double b)
    {
        this->Minimum_ballance=b;
    }
 virtual void credit(double b)
    {
        double x= Account_Ballance+b;
      set_A_B(x);
      
    }
   virtual void debit(double b)
    {
        
        double x= Account_Ballance-b;
      set_A_B(x);
      
    }
    void print_1()
    {
        cout<<"the account number is "<<Account_Number;
        cout<<"\n the account ballance is "<<Account_Ballance;
        cout<<"minimum ballance is "<<this->Minimum_ballance;
        cout<<"servise charges is "<<this->Service_chage;
        
    }
};
class Saving_Account  : public Account
{
protected:
    Account A;
    int interest_rate;
public:
    void set_I_R(int r)
    {
        this->interest_rate=r;
    }
    int Get_I_R()
    {
        return this->interest_rate;
    }
    void print_1()
    {
        cout<<"the account number is "<<Account_Number;
        cout<<"\n the account ballance is "<<Account_Ballance;
        cout<<"the intersst rate is "<<this->interest_rate;
    }
    void credit(double b)
      {
        double x= this->A.get_A_B()-b;
        set_A_B(x);
      }
      void debit(double b)
      {
          if(Account_Ballance<b)
         cout<<"the account balance is in the range ";
          
      }
    
};
int main() {
   Account *ptr[3];
   // ptr[0]=new Account;
    ptr[1] =  new current_Account;
    ptr[2]= new Saving_Account;
    cout<<"enter the account number ";
    int N;
    cin>>N;
    cout<<"Enter the account balance ";
    int B;
    cin>>B;
    cout<<"enter the cradit amount ";
    int C;
    cin>>C;
    cout<<"enter the debit amount ";
    int D;
    cin>>D;
  
    ptr[0]->set_A_B(B);
    ptr[0]->set_A_N(N);
    ptr[0]->credit(C);
    ptr[0]->debit(D);
    cout<<"================= Out PUT OF FIRST =============================\n";
    ptr[0]->print();
    cout<<"\n================= Out PUT OF Second =============================\n";
    ptr[1]->credit(C);
    ptr[1]->debit(D);
    ptr[1]->print();
    cout<<"\n================= Out PUT OF third =============================\n";
  //  ptr[2]->set_I_R(10);
    ptr[2]->credit(C);
    ptr[2]->debit(D);
    ptr[2]->print();
    return 0;
}

