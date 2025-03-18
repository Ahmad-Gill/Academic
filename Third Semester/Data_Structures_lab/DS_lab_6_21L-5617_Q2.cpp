//
//  21L-5617_Q2.cpp
//  21L-5617_LAB_6_Q1
//
//  Created by Ahmad Gill on 10/10/22.
//



#include <iostream>
using namespace std;
void sum(int x)
{
    int s=0;
   if(x/10!=0)
   {
       while(x%10 !=0)
       {
           s+= (x%10);
           x=x/10;
       }
       sum(s);
   }
    else
    cout<<x<<endl;
}
int main()
{
    int n=0;
 cout<<" enter the number ";
    cin>>n;
    sum(n);
    
}

