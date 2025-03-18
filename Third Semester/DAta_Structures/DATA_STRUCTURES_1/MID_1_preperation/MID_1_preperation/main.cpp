#include<iostream>
using namespace std;
class stak
{
    int maxsize;
    int currDize;
    int top;
    int * arr;
public:
    stak(int n=10)
    {
        maxsize=n;
        currDize=0;
        top =-1;
        arr=new int [maxsize];
    }
    bool is_full()
    {
        if (currDize==maxsize)
            return true;
        
        
        return false;
    }
    bool is_empty()
    {
        if(currDize==0)
            return true;
        return false;
    }
    bool stack_push(int val)
    {
        if(is_full())
            return false;
        else
        {
            top++;
            currDize++;
            arr[top]=val;
        }
        return true;
    }
    bool stak_pop()
    {
        if(is_empty())
            return false;
        else
        {
            top--;
            currDize--;
        }
        return true;
    }
    
};
 int main()
 {
     stak S;
     
     S.is_empty();
     S.is_full();
     cout<<endl;
return 0;
 }
