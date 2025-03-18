#include <iostream>
using namespace std;

char main_menu() {
    char choice;
    cout << "Welcome to Main Menu!\nPlease select an option from the menu below: " << endl;
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout<<"enter your choice ";
    cin >> choice;

    while (choice != 'l' && choice != 'c' && choice != 'q')
    {
        cout << "Invalid option." << endl;
        cin >> choice;
    }
    return choice;
}


int login(int account_IDs[], int& ID_index)
{
    int user_id = 0;
    int choice = 0;
    cout << " Enter the Login ID (1-10) : ";
    cin >> user_id;
    int remaining = 0;
    for (int i = 0;i < 10;i++)
    {

        if (account_IDs[i] == user_id)
        {
            remaining = 1; //account found
            ID_index = i;
        }
    }
    if(remaining == 0)
    {
        cout << "Invalid login id.\t\tFirstly create new account." << endl;
        cout << "Returnning to main menu..." << endl;
        choice = main_menu();
        remaining =1;
    }


    if (remaining == 1||choice=='c')
    {
        for (int i = 0;i < 10;i++)
        {

            if (account_IDs[i] == user_id)
            {
                cout << "\nAccount Found!";
                cout << "\nPlease select an option from the menu below: " << endl;
                cout << "1 -> Withdraw" << endl;
                cout << "2 -> Deposit" << endl;
                cout << "3 -> Request" << endl;
                cout << "4 -> Go back to Main Menu" << endl;
                cout<<"enter your choice ";
                cin >> choice;


            }

        }
    }
        return choice;
}

int main()
{
    int cash = 0;
    char choice = main_menu();
    int choice2 = 0;
    int account_IDs[10] = { 0 };
    int balance[10] = { 0 };
    int count = 0;
    int ID_index = 0;
    while(choice=='l' || choice=='c' || choice=='q')
    {
    if (choice == 'l')
    {
        choice2 = login(account_IDs, ID_index);
    }
     if (choice == 'c')
    {
        count++;
      
        cout << "\nCreating Your Account\nEnter account ID to create account: \n";
  
            cin >> account_IDs[count];
        choice2 = login(account_IDs, ID_index);
   
        
    }
     if (choice == 'q')
    {
        cout << "Quitting program!"<<endl;
        cout << "User ID " << account_IDs[ID_index] << " has " << balance[ID_index] << " Balance left";
        choice = 'r';
    }
        while(choice2==1||choice2==2||choice2==3)
        {
            if (choice2 == 1)
            {
                int R5000 = 0, R1000 = 0, R500 = 0, R100 = 0, R50 = 0, R20 = 0, R10 = 0;
                cout << "\nYou selected  * Withdraw Cash *  ";
                int cash;
                cout << "\n Enter amount to withdraw: ";
                cin >> cash;
                int y=cash;
                if (cash <= balance[ID_index])
                {
                    cout << "\nYou have enough cash to withdraw";
                    if (cash % 5000 == 0 || cash % 1000 == 0 || cash % 500 == 0 || cash % 100 == 0 || cash % 50 == 0 || cash % 20 == 0 || cash % 20 == 0)
                    {
                        cout << "\nCash withdrawal for " << cash << " requested: ";

                        R5000 = cash / 5000;
                        cash = cash % 5000;
                        R1000 = cash / 1000;
                        cash = cash % 1000;
                        R500 = cash / 500;
                        cash = cash % 500;
                        R100 = cash / 100;
                        cash = cash % 100;
                        R50 = cash / 50;
                        cash = cash % 50;
                        R20 = cash / 20;
                        cash = cash % 20;
                        R10 = cash / 10;
                        cash = cash % 10;
                        cout << "\n withdrawal detals: \n";
                        cout << "5000 rupee notes: " << R5000 << endl;
                        cout << "1000 rupee notes: " << R1000 << endl;
                        cout << "500 rupee notes: " << R500 << endl;
                        cout << "100 rupee notes: " << R100 << endl;
                        cout << "50 rupee notes: " << R50 << endl;
                        cout << "20 rupee notes: " << R20 << endl;
                        cout << "10 rupee notes: " << R10 << endl;
                        balance[ID_index] -= y;
                        cout<<     balance[ID_index] ;
                        
                    }
                }
                    else
                        {
                        cout << "\nEnter a valid amount.\n ATM cannot give change(coins)";
                        choice2 = login(account_IDs, ID_index);
                    }
                choice2 = login(account_IDs, ID_index);
            }

 
    if (choice2 == 2)
    {
        cout << "\nYou selected  * Deposit Cash *  ";
        cout << "\nEnter amount to Deposit: ";
       cin >> cash;

          balance[ID_index]= cash;
        cout << "\nCash amount " << cash << "  added successfully! \n returning to login department \n";
       choice2 = login(account_IDs, ID_index);

        
    }
  
    if (choice2 == 3)
    {
        cout << "\nYou selected  * Request Cash *  ";
        
        cout << "You (Account ID " << account_IDs[ID_index] << ") have " << balance[ID_index] << " cash amount in your account"<<endl;
        choice2 = login(account_IDs, ID_index);
    }
if (choice2 == 4)
{
    choice = main_menu();
}
        }
    }
    return 0;
}





