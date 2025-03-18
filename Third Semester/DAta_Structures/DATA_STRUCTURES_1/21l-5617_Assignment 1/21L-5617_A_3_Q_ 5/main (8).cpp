
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
int main()
{
 int Amount,rev = 0,digit,n;
 cout<<"Plese enter a positive nymber";
cin>>Amount;
n = Amount;
do{
    digit =  Amount%10;
    rev = (rev*10)+digit;
    Amount = Amount/10;
}
 while(Amount !=0);
 cout<<"the reverse of the number is "<<"="<< rev<<endl;
 
         if (n == rev){
             cout<<"its a  palindromic Number";}
         else{
             cout<<"its  a not palindromic Number";
}
    return 0;
}
