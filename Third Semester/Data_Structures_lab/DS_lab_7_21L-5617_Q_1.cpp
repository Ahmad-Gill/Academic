#include<iostream>
using namespace std;
class stack;
class node
{
    friend class stack;
    int data;
    node*next;
    

};
class stack
{ friend class node;
node *top;
    node*S_top;

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
    void push(int n)
    {
        node*temp=new node;
        temp->next=top;
        temp->data=n;
            top=temp;
            currSize++;
            s=currSize;

    }
    void Spush(int n)
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
    void sort()
    {
        node*temp=new node;
         node*curr=top;
        node*last=0;
        
        for(int i=0;i<currSize;i++)
        {
            if(curr!=NULL)
            {
                if(curr->next!=nullptr&&curr!=NULL)
                {
                    
                    if(curr->data>curr->next->data)
                    {
                        temp->data=curr->next->data;
                        temp->next=curr->next->next;
                        curr->next=temp->next;
                        if(last!=0)
                            last->next=temp;
                        temp->next=curr;
                        if(i==0)
                            top=temp;
                        last=curr;
                        curr=curr->next;
                        
                    }
                    else
                    {
                        last=curr;
                        curr=curr->next;
                    }
                }
                
            }
        }
        
        if(s>0)
        {
            s--;
            sort();

        }
       
    }
    void reverse()
    {
        if(top!=NULL)
        {
            Spush(top->data);

            top=top->next;
            reverse();
        }
        
        
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
    stack S;
    S.push(80);
    S.push(11);
    S.push(9);
    S.push(1);
    S.push(20);
    cout<<"orignal array \n";
    S.display();
    S.sort();
    cout<<" \n sorted array \n";
    S.display();
  //  system("pause");
    cout<<"\nreverse order \n";
    S.reverse();
    S.Sdisplay();
    cout<<"\n";
    return 0;
}
