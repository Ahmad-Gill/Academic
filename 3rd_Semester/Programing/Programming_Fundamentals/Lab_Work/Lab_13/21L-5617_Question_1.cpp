/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
void Sum_Of_N(int arry[], int I,int N){
    int sum =0;
 
    for(int  i = I ;i != (I+N);i++){
        sum = sum+arry[i];
    }
    cout<<"the required sum is = "<<sum;
}
int main()
{
    int a[100],sum=0;
    int Index;int Number;
    for(int i = 0 ;i<9;i++){
        cout<<"enter the elements of an array "<<i<<" = ";
        cin>>a[i];
    }
      
    
    cout<<"enter value of index = ";
    cin>>Index;
    cout<<"enter value of sum of numbers = ";
    cin>>Number;
   
Sum_Of_N(a,Index,Number);
    return 0;
}
