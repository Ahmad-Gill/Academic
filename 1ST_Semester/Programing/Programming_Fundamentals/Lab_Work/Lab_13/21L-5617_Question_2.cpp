/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

bool Has_Sum(int arry[],int total){
int sum =0;
int i =0,counter =0;
   
  for(int i=0;i<9;i++){
        int sum=0;
    for(int count=i;count<9;count++){
    sum=sum+arry[count];
  
    if(sum==total)
    return true;
}
}
}
int main()
{
    int a[100];
    int Total;
    int i =0;
    for( i;i<9;i++){
        cout<<"element nunmer "<<i<<" = "; 
        cin>>a[i];
}
        cout<<"enter total sum = ";
        cin>>Total;
      if(Has_Sum(a,Total)==1)  
      cout<<"TRUE";
      else
      cout<<"FALSE";
    
    return 0;
}
