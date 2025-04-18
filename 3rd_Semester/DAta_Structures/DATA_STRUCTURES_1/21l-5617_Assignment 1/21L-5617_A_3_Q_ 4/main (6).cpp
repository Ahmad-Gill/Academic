/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream>
using namespace std;
int main()
{
int Amount,cent,$,y;
double x;
    cout<<"Enter the amont in RS ";
    cin>>Amount;
  if(Amount>=165){
     $ = Amount/165;
    cout<<"Total Number of Dolars"<<"= "<<$<<endl;}
     y =Amount-($*165);
     if (Amount<165 ||y<165){
     x=y/165.0;
        cent =x*100;
    
       cout<<"Total Number of Cents"<<"= "<<cent;
   }
      
return 0;
}