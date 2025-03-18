//
//  main.cpp
//  Lab_8
//
//  Created by Ahmad Gill on 14/04/2022.
//

#include <iostream>
using namespace std;
class BiggerInt
{
  
    int *big_Int;
    int Int_size;
public:
    BiggerInt()
    {
        Int_size = 0;
    }
    ~BiggerInt()
    {
        big_Int = NULL;
    }
    
    BiggerInt(int size)
    {
      Int_size=size;
        big_Int = new int [size];
        for(int i=0;i<size;i++)
        {
            cout<<"enter the "<<i+1<<" element of an array : ";
            cin>>big_Int[i];
        }
    }
    void set(int size,int arr[])
    {
       this-> Int_size = size;
        big_Int = new int [size];
        for(int i=0;i<size;i++)
           this-> big_Int[i] = arr[i];
    }
    BiggerInt(const BiggerInt &obj)
    {
       
        Int_size=obj.Int_size;
        big_Int = new int [Int_size];
        for(int i=0;i<Int_size;i++)
        {
            big_Int[i]=obj.big_Int[i];
        }
    }
  
    void Show()
    {
        for(int i=0;i<Int_size;i++)
        {
            cout<<big_Int[i];
        }
    }
   
  
    int  operator[](int index)
    {
        if (index>=0||index<=Int_size)
        return this->big_Int[index];
        else
            cout<<"envalid index";
        return 0;
    }
    
    void operator++()
    {
        for(int i=0;i<this->Int_size;i++)
        {
           // this->big_Int[i]++;
        
        cout<<this->big_Int[i]++<<"  ";
        }
    }
    void operator++(int)
    {
        for(int i=0;i<this->Int_size;i++)
        {
            this->big_Int[i]++;
           cout<<this->big_Int[i]<<"  ";
        }
    }
    void operator--()
    {
        for(int i=0;i<this->Int_size;i++)
        {
          //  this->big_Int[i]--;
           cout<<this->big_Int[i]--<<"  ";
        }
    }
    void operator--(int)
    {
        for(int i=0;i<this->Int_size;i++)
        {
            this->big_Int[i]--;
           cout<<this->big_Int[i]<<"  ";
        }
    }
    void getter()
    {cout<<"the size of array is "<<Int_size<<endl<<"the array elements is : ";
        for(int i=0;i<Int_size;i++)
        {
            cout<<big_Int[i]<<" ";
        }
    }
  
    
};



int main()
{
    BiggerInt B1;
    cout<<"the sise of first array : ";
    int x;
    cin>>x;
    int *p;
    p =new int [x];
    for(int i=0;i<x;i++)
    {
        cout<<"enter the "<<i+1<<"  element of first array";
    cin>>*(p+i);
    }
    cout<<"the orignal data is  :\n ";
    B1.set(x, p);
    B1.getter();
    BiggerInt B2 = B1;
    cout<<"the copy data is  :\n ";
    B2.getter();
   
    cout<<"\n the required index is \n";
 cout<< "index of first array : "<<B1[1]<<endl;
    cout<<"index of second array : "<<B2[1];

    cout<<"\narray of pre incriment\n ";
    ++B1;
    cout<<endl;
    ++B2;
   
    cout<<endl;
    cout<<"\narray of post incriment ";
    B1++;
    cout<<endl;
    B2++;
    cout<<endl;
    cout<<"\narray of pre decrement \n ";
    --B1;
    cout<<endl;
    --B2;
   
    cout<<endl;
    cout<<"\narray of post decrement \n";
    B1--;
    cout<<endl;
    B2--;
    cout<<endl;
   
   ;

    return 0;
}
