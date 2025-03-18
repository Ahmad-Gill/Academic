//
//  main.cpp
//  PF_Question_1
//
//  Created by Ahmad Gill on 11/05/2022.
//

#include <iostream>
using namespace std;
int main_menue(int ID[10]);
void Operations_Menue()
{
    char choice1;
    double deposit;
    int balance;
    cout<<"d -> Deposit Money"<<endl;
    cout<<"w -> Withdraw Money"<<endl;
    cout<<"r -> Request Balance"<<endl;
    cout<<"m -> Go back to Main Screen"<<endl<<">";
    cin >> choice1;
    string deposit1;
    if(choice1 == 'd')
    {
        cout<<"Enter Amount of deposit: "<<endl;
        cout<<">";
        cin>>deposit1;
        //balance = balance + deposit;
        if(deposit1 >= "a" || deposit1 <= "z" || deposit1 <= "Z" || deposit1 >= "A")
        {
        cout<<"Invalid Input"<<endl;
        cout<<"Enter Amount of deposit again: ";
        cin>>deposit1;
        }
        cout<<"Amount Credited Successfully"<<endl;
        Operations_Menue();
    }

    if(choice1 == 'w')
    {
        float withdrawl = 0;
        int hundred = 0 , five_thousand = 0 , thousand = 0 , fifty = 0 , twenty = 0 , ten = 0 , five_hundred = 0;
        cout<<"Amount of withdrawl: "<<endl;
        cout<<">";
        cin>>withdrawl;
        float withdrwal1 = withdrawl;
        while(withdrawl >= 5000)
        {
            five_thousand = five_thousand + 1;
            withdrawl = withdrawl - 5000;
        }
        while(withdrawl >= 1000)
        {
            thousand = thousand + 1;
            withdrawl = withdrawl - 1000;
        }
        while(withdrawl >= 500)
        {
            five_hundred = five_hundred + 1;
            withdrawl = withdrawl - 500;
        }
        while(withdrawl >= 100)
        {
            hundred = hundred + 1;
            withdrawl = withdrawl - 100;
        }
        while(withdrawl >= 50)
        {
            fifty = fifty + 1;
            withdrawl = withdrawl - 50;
        }
        while(withdrawl >= 20)
        {
            twenty = twenty + 1;
            withdrawl = withdrawl - 20;
        }
        while(withdrawl >= 10)
        {
            ten = ten + 1;
            withdrawl = withdrawl - 10;
        }
        int remaining = 0;
        remaining = withdrawl;
        while(remaining != 0)
        {
            cout<<"Invalid Input"<<endl;
            cout<<"Amount of withdrwal: "<<endl<<">";
            cin>>withdrawl;
            withdrwal1 = withdrawl;
             while(withdrawl >= 5000)
        {
            five_thousand = five_thousand + 1;
            withdrawl = withdrawl - 5000;
        }
        while(withdrawl >= 1000)
        {
            thousand = thousand + 1;
            withdrawl = withdrawl - 1000;
        }
        while(withdrawl >= 500)
        {
            five_hundred = five_hundred + 1;
            withdrawl = withdrawl - 500;
        }
        while(withdrawl >= 100)
        {
            hundred = hundred + 1;
            withdrawl = withdrawl - 100;
        }
        while(withdrawl >= 50)
        {
            fifty = fifty + 1;
            withdrawl = withdrawl - 50;
        }
        while(withdrawl >= 20)
        {
            twenty = twenty + 1;
            withdrawl = withdrawl - 20;
        }
        while(withdrawl >= 10)
        {
            ten = ten + 1;
            withdrawl = withdrawl - 10;
        }
        remaining = withdrawl;

        }
        if(remaining == 0)
        {
            cout<<"Cash Withdrawl for RS."<<withdrwal1<<" requested"<<endl;
            balance = deposit - withdrwal1;
        }
        if(five_thousand != 0)
        {
            cout<<"Denomination 5000s - "<<five_thousand<<endl;;
        }
        if(thousand != 0)
        {
            cout<<"Denomination 1000s - "<<thousand<<endl;
        }
        if(five_hundred != 0)
        {
            cout<<"Denomination 500s - "<<five_hundred<<endl;
        }
        if(hundred != 0)
        {
            cout<<"Denomination 100s - "<<hundred<<endl;
        }
        if(fifty != 0)
        {
            cout<<"Denomination 50s - "<<fifty<<endl;
        }
        if(twenty != 0)
        {
            cout<<"Denomination 20s - "<<twenty<<endl;
        }
        if(ten != 0)
        {
            cout<<"Denomination 10s - "<<ten<<endl;
        }
        Operations_Menue();
        }

    if(choice1 == 'r')
    {
        cout<<"Your balance is RS."<<deposit<<endl;
        Operations_Menue();
    }

   /* if(choice1 == 'm')
    {
        int main_menue(int ID);
    }*/
}

int main_menue(int ID[10])
{
  //  int ID[10];
    char choice;
    int user_id;
    cout<<"Please Select An Option From The Menu Below"<<endl;
    cout<<"l -> Login "<<endl;
    cout<<"c -> Create New Account "<<endl;
    cout<<"q -> Quit "<<endl<<">";
    cin>>choice;
    if(choice == 'l')
    {
        int i = 0;
        cout<<"Please enter your user id:";
        cin>>user_id;
        int a;
        for(int i = 0 ; i < 10 ; i++)
        {
        if(ID[i] == user_id)
        {
            a = 1;
        }
        }
        if(a==1)
        {
            cout<<"Access Granted!"<<endl;
            Operations_Menue();
        }
        else
        {
            cout<<"******** Account Does not Exist !!! ********"<<endl<<endl;
            main_menue(ID);
        }
    }
    if(choice == 'c')
    {
        cout<<"Please enter your user id:"<<endl;
        cin>>user_id;
     //   ID[0] = user_id;
        main_menue(ID);
    }
    if(choice == 'q')
    {
        int count;
        count++;
        cout<<"Thanks for stopping by User"<<count<<"! BYE"<<endl<<endl;
        main_menue(ID);
    }
}

int main()
{
    int ID[10] = {1,2,3,4,5,6,7,8,9,10};
    int id = 0;
    int j ;
    int initial_balance = 0 ;
    cout<<"Hi! Welcome to Mr.Hafiz Mahad Sheikh's ATM Machine!";
    cout<<endl;
    cout<<"Please enter your choice: ";
    main_menue(ID);
    return 0;
}
