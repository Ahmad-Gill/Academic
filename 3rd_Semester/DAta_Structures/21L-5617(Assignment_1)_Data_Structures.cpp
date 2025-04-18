//
//  main.cpp
//  21L-5617(Assignment_1)
//
//  Created by Ahmad Gill on 9/16/22.
//

#include <iostream>
using namespace std;
class DoublyLinkedList;
class node
{
    
    friend class DoublyLinkedList;
public:
    int data;
    node* next,*pre;
    
};
class DoublyLinkedList
{
    node * head;
public:
    DoublyLinkedList()
    {
        head=NULL;
    }
    bool InsertAtStart(int val)
    {
        node*temp =new node;
        temp->data=val;
        temp->next=head;
        head=temp;
        return true;
    }
    bool DeleteFromStart()
    {
        if (head==nullptr)
        {
            cout<<"array is empty : ";
            return 0;
        }
        node*curr=head;
        head=curr->next;
        delete curr;
        curr=0;
        
        return 1;
    }
    bool InsertAtEnd(int val)
    {
        node*temp=new node;
        temp->data=val;
        temp->next=NULL;
        temp->pre=NULL;
        node*curr=head;
        if(head==nullptr)
        {
            head=temp;
        }
        else
        {
            while(curr->next!=0)
            {
                curr=curr->next;
                
            }
            
            curr->next=temp;
            temp->pre=curr;
        }
        return 1;
    }
    bool DeleteFromEnd()
    {
        node*curr=new node;
        curr=head;
        node*last=NULL;
        
        if(head==0)
        {
            cout<<"the linkedlist is empty : \n";
            return 0;
        }
        
        else
        {
            while(curr->next!=NULL)
            {
                last=curr;
                curr=curr->next;
            }
            if(last==0)
            {
                head=NULL;
            }
            else
                last->next=NULL;
        }
        return 1;
        
    }
    bool sortedIsert(int val){
        node*temp=new node;
        temp->data=val;
        
        if(head==NULL){
            head=temp;
        }
        else if(head->data>=temp->data)
        {
            temp->next=head;
            temp->next->pre=temp;
            head=temp;
        }
        else{
            node*curr=head;
            while(curr->next!= nullptr&&curr->next->data<temp->data){
                curr=curr->next;
            }
            temp->next=curr->next;
            if (curr->next != NULL)
                temp->next->pre = temp;
            
            curr->next = temp;
            temp->pre = curr;
            
        }
        return true;
    }
    bool deleteSearch(int val)
    {
        if(head==NULL)
        {
            cout<<" the linklist is empty : "<<endl;
            return true;
        }
        
        node*temp=new node;
        temp->data=val;
        node*curr=head;node*last=head;
        if(curr->data
           ==val)
        {
            head=curr->next;
            return true;
            
        }
        int i=0;
        while(curr!=NULL)
        {
            if(curr->data!=val)
                curr=curr->next;
            
            else
            {
                i++;
                curr=curr->next;
                
            }
        }
        if(i==0)
        {
            cout<<"the number does not exist ";
            return true;
        }
        curr=head;
        while(curr!=NULL)
        {
            if(curr->data==val)
            {
                last->next=curr->next;
                delete curr;
                curr=0;
            }
            else
            {
                last=curr;
                curr=curr->next;
            }
            
        }
        return true;
    }
    node *searchValue(int value,int &val)
    {
        int i=0;
        node *curr = head;
        if(head == nullptr)
        {
            return curr;
        }
        else
        {
            while(curr != nullptr)
            {
                if(curr -> data == value)
                {
                    i++;
                    
                    curr -> next = nullptr;
                    curr -> pre = nullptr;
                    return curr;
                    break;
                }
                val++;
                curr = curr -> next;
            }
        }
        return curr;
    }
    void display ()
    {
        node*curr;
        curr=head;
        cout<<"( ";
        while(curr!=0)
        {
            cout<<curr->data<<", ";
            curr=curr->next;
        }
        cout<<" )";
    }
    ~DoublyLinkedList()
    {
        while(head!=0)
        {
            node *curr = head;
            head=curr->next;
            delete curr;
            curr=0;
            
        }
    }
};

int main() {
    
    DoublyLinkedList L;
    
    char I,SI,D,SE,DSP;
    cout<<"\n--------------------<INSERT OPERATION>-----------------------\n";
    cout<<"\n if you want to insert the value form start press S else press E ";
    cin>>I;
    if(I=='S'||I=='s'){
        int size;
        cout<<"\nenter the size of array : ";
        cin>>size;
        while(size<=0){
            cout<<"\nsize must be greater than 0 :input please ";
            cin>>size;
        }
        int value;
        for(int i=0;i<size;i++){
            cout<<"enter the value : ";
            cin>>value;
            L.InsertAtStart(value);
        }
    }
    if(I=='E'||I=='e'){
        int size;
        cout<<"\nenter the size of array : ";
        cin>>size;
        while(size<=0){
            cout<<"size must be greater than 0 :input please ";
            cin>>size;
        }
        int value;
        for(int i=0;i<size;i++){
            cout<<"enter the value : ";
            cin>>value;
            L.InsertAtEnd(value);
        }
    }
    if((I=='E'||I=='e')||(I=='S'||I=='s')){
        cout<<"\nyour input is \n ";
        L.display();
    }
    else{
        cout<<"you enter nothing your array is empty :\n";
    }
    cout<<endl;
    cout<<"\n--------------------<DELETE OPERATION>-----------------------\n";
    cout<<"\n if you want to delete the value form start press S else press E ";
    cin>>D;
    if(D=='s'||D=='S'){
        int size;
        cout<<"\n how many array do you want to dell enter ";
        cin>>size;
        for(int i=0;i<size;i++)
            L.DeleteFromStart();
    }
    if(D=='e'||D=='E'){
        int size;
        cout<<"\n how many array do you want to dell enter ";
        cin>>size;
        for(int i=0;i<size;i++)
            L.DeleteFromEnd();
    }
    if((D=='E'||D=='e')||(D=='S'||D=='s')){
        cout<<"\n your array is ";
        L.display();
    }
    else{
        cout<<"you enter wrong comand your array remain same  :\n";
        L.display();
    }
    cout<<endl;
    cout<<"\n--------------------<DELETE SPECIFIF VALUEx>-----------------\n";
    cout<<"to delete specific valye press y ";
    cin>>DSP;
    if(DSP=='y'||DSP=='Y'){
        int value;
        cout<<"enter the value ";
        cin>>value;
        L.deleteSearch(value);
        L.display();
    }
    else
        cout<<"you delete nothing : ";
    cout<<"\n--------------------<SORTED INSERTION>-----------------------\n";
    cout<<"press y if you want to insert sorted ";
    cin>>SI;
    if(SI=='y'||SI=='Y'){
        int size=0;
        cout<<"enter the size of array : ";
        cin>>size;
        while(size<1){
            cout<<"Size can never be lessthan one : enter again :";
            cin>>size;
        }
        int value=0;
        for(int i=0;i<size;i++){
            cout<<"enter the "<<i+1<<" value :";
            cin>>value;
            L.sortedIsert(value);
        }
        cout<<"\n--THE SORTED ARRAY IS :----\n";
        L.display();
    }
    else
        cout<<" you enter the wrong choice : ";
    
    cout<<"\n--------------------<DELETE SPECIFIC VALUE>------------------\n";
    cout<<" press y to delete specific value ";
    cin>>SE;
    if(SE=='y'||SE=='y'){
        int value=0;
        cout<<"enter the specific that you want to dell ";
        cin>>value;
        L.deleteSearch(value);
        cout<<"\narray after deletion : \n";
        L.display();
    }
    else
        cout<<"\n you enter the wrong comand  \n";
    cout<<"\n--------------------<SEARCH SPECIFIC VALUE>------------------\n";
    int val =0;
    int value;
    cout<<"nter the value to search :";
    cin>>value;
    node *L1= L.searchValue(value,val);
    if(L1==0){
        cout<<" value not fount \n";
    }
    else{
        cout<<"data fount at index : "<<val<<endl;;
        cout<<"the data at index : "<<val <<" and at node refer to "<<L1<<" is = "<<L1->data;
    }
    cout<<"\n--------------------<THE END>--------------------------------\n";
    
    return 0;
}
