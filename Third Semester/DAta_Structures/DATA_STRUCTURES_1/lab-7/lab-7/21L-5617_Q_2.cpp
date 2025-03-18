//
//  Q_2.cpp
//  lab-7
//
//  Created by Ahmad Gill on 10/17/22.
//

#include<iostream>
using namespace std;
class stack;
class node
{
    friend class stack;
    char data;
    node*next;
};
class stack
{ friend class node;
node *top;
    node*S_top;
    node*curr_=0;
    int currSize;
    int currsize;
int s;
int maxSize;
public:
    stack()
    {
        top=NULL;
        currSize=0;
        currsize=0;
    }
    void push(char n)
    {
        node*temp=new node;
        temp->next=top;
        temp->data=n;
            top=temp;
        curr_=top;
            currSize++;
            s=currSize;
    }
    void Spush(char n)
    {
        node*temp=new node;
        temp->next=S_top;
        temp->data=n;
            S_top=temp;
        currsize++;
    }
    bool pop()
    {
        if(currSize==0)
            return false;
        else
        {
            top=top->next;
            currSize--;
        }
        return true;
    }
   
    void reverse()
    {
        if(curr_!=NULL)
        {
            Spush(curr_->data);

            curr_=curr_->next;
            reverse();
        }
        
        
    }
    bool chek_palendrome()
    {
        if(currsize/2!=0)
        {
            if(top->data==S_top->data)
            {
                top=top->next;
                S_top=S_top->next;
                currsize--;
                chek_palendrome();
            }
            else
                return false;
        }
        return true;
    }
    void display()
{
    node*curr=top;
    int s=currSize;
  while(s>0)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
        s--;

    }
}
    void Sdisplay()
{
    node*curr=S_top;
    int s=currsize;
  while(s>0)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
        s--;
    }
}
};
int main()
{
    cout<<"enter the string ";
    string s;
    cin>>s;
    cout<<" the orignal string is \n";
    int size=s.length();
   cout<<s;
    stack S;
    for(int  i=0;i<size;i++)
    {
        S.push(s[i]);
    }
   S.reverse();
    cout<<"\n";
   if( S.chek_palendrome())
       cout<<"the given string is palendrome ";
        else
        {
            cout<<" the given string is not palendrome ";
        }
    return 0;
}

