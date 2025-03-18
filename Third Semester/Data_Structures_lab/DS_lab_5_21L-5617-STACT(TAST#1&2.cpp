#include <iostream>
using namespace std;
class stack
{
    int maxSize;
    int currSize;
    int top;
    char *arr;
public:
    stack(int n=10)
    {
        maxSize  = n;
        top=1;
        currSize=0;
        arr=new char [maxSize];
    }
    ~stack()
    {
        if(arr!=0)
        {
            delete [] arr;
            arr =0;
        }
    }
    bool is_empty()
    {
        if(currSize==0)
        {
            return 1;
        }
        return 0;
        
    }
    bool is_full()
    {
        if(currSize==maxSize)
            return 1;
        return 0;
    }
    void push(int val)
    {
        if(is_full())
            cout<<" the stack is full"<<endl;
        else
        {
            top++;
            arr[top]=val;
            currSize++;
            
        }
    }
    void pop()
    {
        if(is_empty())
        {
            cout<<"the stact is empty "<<endl;
        }
        else
        {
            top--;
            currSize--;
        }
        
        
    }
    bool top_find()
    {
        if(is_empty())
            return 0;
        else
        {
            
            int val=arr[currSize+1];
            cout<<"the value at tope is= "<<val;
            return 1;
        }
        
    }
    bool check(char a,char b)
    {
        if(a=='}'&&b=='{')
            return true;
        if(a==']'&&b=='[')
            return true;
        if(a==')'&&b=='(')
            return true;
        return false;
        
        
    }
    
    bool IsEqual(char a,char b)
    {
        if(a=='{'&&b=='}')
            return true;
        if(a=='['&&b==']')
            return true;
        if(a=='('&&b==')')
            return true;
        return false;
        
        
    }
    bool Is_2_Equal(char a,char b)
    {
        if(a=='{'&&b=='{')
            return 2;
        if(a=='{'&&b=='[')
            return 2;
        if(a=='{'&&b=='(')
            return 2;
        if(a=='['&&b=='{')
            return 2;
        if(a=='['&&b=='[')
            return 2;
        if(a=='['&&b=='(')
            return 2;
        if(a=='('&&b=='{')
            return 2;
        if(a=='('&&b=='[')
            return 2;
        if(a=='('&&b=='(')
            return 2;
        return 0;
        
        
    }
    bool Is_inverse_Equal(char a,char b)
    {
        if(a=='}'&&b=='}')
            return 1;
        if(a=='}'&&b==']')
            return 2;
        if(a=='}'&&b==')')
            return 2;
        if(a==']'&&b=='}')
            return 2;
        if(a==']'&&b==']')
            return 2;
        if(a==']'&&b==')')
            return 2;
        if(a==')'&&b==']')
            return 2;
        if(a==')'&&b==']')
            return 2;
        if(a==')'&&b==')')
            return 2;
        return 0;
        
        
    }
    bool isBallanced(char *array,int size)
    {
       
        if(is_full())
        {
            cout<<"the stak is full ";
            return 0;
        }
        if(size==0)
        {
            cout<<" the array is null ";
            return 0;
        }
        else{
            push(array[0]);
            push(array[1]);
            if(arr[top-1]=='{'||arr[top-1]=='['||arr[top-1]=='(')
            {
                for(int i=2;i<=size;i=i+2)
                {
                    if(Is_inverse_Equal(arr[top-1], arr[top]))
                    {
                        if(IsEqual(arr[top-3], arr[top]))
                        {
                            if(IsEqual(arr[top-2], arr[top-1]))
                            {
                                pop();
                                pop();
                                pop();
                                pop();
                            }
                        }
                    }
                    if(IsEqual(arr[top-1], arr[top]))
                    {
                        pop();
                        pop();
                        if(i!=size&&is_empty())
                        {
                            push(array[i]);
                            push(array[i+1]);
                        }
                    }
                  
                    if(Is_2_Equal(arr[top-1], arr[top]))
                        
                    {
                         if (i!=size)
                        {
                            push(array[i]);
                            push(array[i+1]);
                        }
                        
                    }
                    
                        if(IsEqual(arr[top], arr[top-1]))
                        {
                                pop();
                                    pop();
                                
                            }
                
                }
            }
                else
                {
                    cout<<" first bracket can never be closing bracket so it not ballance ";
                }
        }
        if(is_empty())
            cout<<" it is the balance equation : ";
        else
            cout<<" it is NOT balance equation : ";
        return true;
    }
    
    
};
int main()
{ int n=10;
 //  cout<<"enter the size of stack ";
  //  cin>>n;
    stack S(n);
   // S.push(2);
  //  S.push(3);
   // S.push(9);
  //  S.top_find();
    int size=1;
  
    cout<<"Enter the  string to match ";

    char *array=new char[100];
    for(int i=0;i<100;i++)
        array[i]=' ';
    cin.get(array,100);
    cin.ignore();
   for(int i=0;array[i]!=' ';i++)
       size=i;

    for(int i=0;i<size;i++)
        cout<<array[i];
    S.isBallanced(array, size);
  
    
  
    return 0;
}
