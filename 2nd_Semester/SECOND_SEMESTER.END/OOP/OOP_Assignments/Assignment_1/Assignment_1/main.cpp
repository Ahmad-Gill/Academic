#include <iostream>
using namespace std;
class BiggerInt
{
    int *big_int;
    int int_length_;
    int size;
public:
    BiggerInt()
    {
        big_int = NULL;
        int_length_ = 0;
    }
    BiggerInt(const int *obj , int size)
    {
          int_length_ = size;
          obj = new int[int_length_];
          for(int i = 0 ; i < int_length_ ; i++)
          {
              big_int[i] = obj[i];
              cout<<big_int[i]<<" , ";
          }
              cout<<endl;
    }

    BiggerInt(const BiggerInt &obj)
    {
       int_length_ = obj.int_length_;
       big_int = new int[obj.int_length_];
       for(int i = 0 ; i < obj.int_length_ ; i++)
       {
           big_int[i] = obj.big_int[i];
           cout<<big_int[i];
       }
    }

    void assign(const BiggerInt &obj)
    {
        this -> int_length_ = obj.int_length_;
        big_int = new int[obj.int_length_];
        for(int i = 0 ; i < obj.int_length_ ; i++)
            this -> big_int[i] = obj.big_int[i];
    }
    void assign(const int*big_int , int size)
    {
        int_length_ = size;
        for(int i = 0 ; i < size ; i++)
            this -> big_int[i] = big_int[i];
    }

    void append(const BiggerInt &obj)
    {
        int *big_int_1;
        int size1;
        size1 = int_length_ + obj.int_length_;
        big_int_1 = new int[size1];
        for(int i = 0 ; i < size1 ; i++)
        {
            big_int_1[i] = big_int[i];
            if(i >= int_length_)
                big_int_1[i] = obj.big_int[i];
        }
    }
    void append(const int* big_int, int size)
    {
        int *big_int_1 = nullptr;
        int size1;
        size1 = size + this -> int_length_;
        for(int i = 0 ; i < size1 ; i++)
        {
            big_int_1[i] = big_int[i];
            if(i >= int_length_)
                big_int_1[i] = big_int[i];

        }
    }

    int CompareTo(const BiggerInt &obj)
    {
        this -> int_length_ = obj.int_length_;
        big_int = new int [obj.int_length_];
        if(int_length_ > obj.int_length_)
            return 2;
        if(int_length_ < obj.int_length_)
            return 1;
        if(int_length_ == obj.int_length_)
            for(int i = 0 ; i < int_length_ ; i++)
            {
                if(big_int[i] > obj.big_int[i])
                    return 2;
        if(big_int[i] < obj.big_int[i])
                    return 1;
            }
            return 0;
    }
    int CompareTo(const int *big_int , int size ){
        big_int = new int[size];
        if(size > int_length_)
            return 2;
        else if(size < int_length_)
            return 1;
        else if(size == int_length_)
            return 0;

    return 0;
}
    void display()
    {
        if(big_int == 0)
            cout<<"No Value Assigned";
        else
        {
            for(int i = 0 ; i < int_length_ ; i++)
                cout<<big_int[i];
        }
    }
    ~ BiggerInt()
    {
        delete [] big_int;
    }
};

 int main()
 {
     BiggerInt b1;
     int  S;
     cout<<"Enter the size of array : ";
     cin >> S;
     int *N;
     N = new int [S];
     cout<<"enter the elements for array";
     for(int i = 0 ; i < S ; i++)
         cin >> N[i];
     b1:BiggerInt(N , S);
     b1.assign(N , S);
     b1.append(N,S);
     return 0;
 }
