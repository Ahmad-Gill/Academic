//
//  Q1.cpp
//  21L-5617_LAB_6_Q1
//
//  Created by Ahmad Gill on 10/10/22.
//


#include <iostream>
using namespace std;
int i=0;
bool isMember(int x,int size,int *arr)
{
    if( arr[i]==x){
        cout<<" value matched \n";
        return true;
    }
    if(i>=size){
        cout<<" value does not match \n";
        return false;
    }
    i++;
    isMember(x, size, arr);
    return false;
}
int main() {
   // int i=0;
    int x,size;
    cout<<"enter the size of array ";
    cin>>size;
    cout<<"enter the number to find ";
    cin>>x;
    int *array=new int [size];
    for(int i=0;i<size;i++)
    {
        cout<<"enter the "<<i+1<<" value of array ";
        cin>>array[i];
    }
    isMember(x, size, array);
    return 0;
}

