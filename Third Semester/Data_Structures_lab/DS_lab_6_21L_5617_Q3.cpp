//
//  21L_5617_Q3.cpp
//  21L-5617_LAB_6_Q1
//
//  Created by Ahmad Gill on 10/10/22.
//


#include <iostream>
using namespace std;
void flip(int start,int end,float*arr,int size)
{
    if(start!=end)
    {
        float temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
        flip(start, end, arr, size);
        
        
    }
    else{
        for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
    }
        
    
    
    
}
int main()
{
    int x,size;
    int i=0;
    cout<<"enter the size of array ";
    cin>>size;
    float *array=new float [size];
    for( i;i<size;i++)
    {
        cout<<"enter the "<<i+1<<" value of array ";
        cin>>array[i];
    }
    flip(0,i-1,array,size);
}

