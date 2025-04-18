//
//  main.cpp
//  lab-5Q2
//
//  Created by Ahmad Gill on 10/3/22.
//

#include <iostream>
using namespace std;
class Queue;
class node
{
    friend class Queue;
    int data ;
    node *next;
};
class Queue
{
    node* front;
    node* rear;
 
    
public:
    Queue()
    { front=0;
        rear=0;
      
       
    }
    
    int front_()
    {
        return  front->data;
    }
    int rear_()
    {
        return rear->data;
    }

    bool isEmpty()
    {
        if (front==NULL)
            return true;
        return 0;
    }
    bool enqueue(int val)
    {
        
        node*temp =new node;
        temp->data=val;
        temp->next=NULL;
        if(rear==NULL)
        {
            front=temp;
            rear=temp;
            
        }
        else{
            
            rear->next = temp;
            rear = rear->next;
          //  cout<<front->next->data;
            return 1;
        }
       // cout<<front->data;
        return true;
    }
        bool degueue()
        {
            if(isEmpty())
                return false;
            else{
                
                node*curr=front;
                front=front->next;
                delete curr;
                curr=0;
            }
            return true;
            
        }
        int size()
    {
            node*curr=front;
            int size=0;
            if(front==0)
                return 0;
            while(curr->next!=NULL)
            {
                size++;
                curr=curr->next;
                
            }
            return size;
        }
    void arrange()
    {
        int* array =new int [(size()+1)/2];
        if(isEmpty())
            cout<<"false ";
        else{
            node*curr=front;
            for(int i=0;i<(size()+1)/2;i++)
            {
                curr=curr->next;
            }
           
            for(int i=0;i<(size()+1)/2;i++)
            {
                array[i]=curr->data;
                curr=curr->next;
            }
        }
   
        node*last_main=0,*last_second=0;
        node* curr_main=this->front;
   
        for(int i=0;i<(size()+1)/2;i++)
        {
            node *temp=new node;
            temp->data=array[i];
            last_main=curr_main;
            curr_main=curr_main->next;
            last_main->next=temp;
            temp->next=curr_main;
            
        }
        curr_main->next=NULL;
        rear->next=NULL;
        
    }
    void dislay()
    {
        node*curr=front;

        for(int i=0;i<=(size()/2);i++)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
    }
    
};
int main() {
    Queue Q,Q1;
    Q.enqueue(3);
    Q.enqueue(2);
    Q.enqueue(5);
    Q.enqueue(6);
    Q.enqueue(7);
    Q.enqueue(9);
    Q.enqueue(8);
    Q.enqueue(4);
   // cout<<Q.front_();
   // Q.dislay();
  // cout<< Q.rear_();
    Q.arrange();
    Q.dislay();
    return 0;
}
