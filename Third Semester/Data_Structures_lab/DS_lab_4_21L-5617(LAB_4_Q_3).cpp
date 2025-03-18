#include<iostream>
using namespace std;

class DoublyLinkedList;

class Node
{
    friend DoublyLinkedList;
    int data;
    Node *next , *prev;
};

class DoublyLinkedList
{
    Node *head;
    int count=0;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    bool insertAtStart(int val)
    {
        
        if(head==nullptr)
        {
            Node *temp = new Node;
            temp->data=val;
            temp->next=temp;
            temp->prev=temp;
            head=temp;
            count++;
        }
        else{
            count++;
            int index=0;
            Node*curr=head;
            while(count!=index)
            {
                curr=curr->next;
                index++;
            }
            Node *temp = new Node;
            temp -> data = val;
            curr->next=temp;
               temp -> prev = curr;
            temp->next=head;
            head=temp;
        }
        return 1;
    }


    bool insertAtEnd(int val)
    {
        Node *temp = new Node;
        temp->data=val;
        if(head==nullptr)
        {
            temp->next=temp;
            temp->prev=temp;
            head=temp;
            count++;
        }
       else if(count==1)
        {
            Node *curr = head;
            temp->prev=curr;
            temp->next=head;
            head->prev=temp;
            head->next=temp;
            count++;
        }
        else{
           
          

            Node *curr = head;
            int index=1;
          
            while(count>index)
            {
                
                index++;
                curr = curr -> next;
            }
           
            temp->prev=curr;
            curr->next=temp;
            temp->next=head;
           
            head->prev=temp;
       
            count++;
           
        }
      
        return true;
    }

    bool deleteFromStart()
    {
        if (head == nullptr)
        {
            return 0;
        }
        else
        {
            Node *curr = head;
            head = curr -> next;
            
            int index1=1;
          
            while(count>index1)
            {
                
                index1++;
                curr = curr -> next;
            }
            head->prev=curr;
            curr->next=head;
            count--;
         
            return 1;
        }
}

    void deleteFromEnd()
    {
        Node* curr=head;
        if(head == nullptr)
        {
            cout << "List Is Empty" << endl;
           
        }
        else
        {
            
            int index1=1;
          
            while(count>index1)
            {
                
                index1++;
                    curr = curr->next;
            }
            head->prev=curr->prev;
            curr->prev->next=head;
            count--;
           
}
}

    bool check_list()
    {
        Node* curr=head;
        if(head==NULL)
        {
            cout<<"link list is empty ";
        }
        else{
            int index1=1;
          
            while(count>index1)
            {
                
                index1++;
                    curr = curr->next;
            }
            if(head->prev==curr)
            {
                cout<<" the link list is circular : ";
            }
            else{
                cout<<" the list is not circular ";
            }
        }
        
        return 1;
    }
void display()
   {
    int index=0;
        Node *curr = head;
        while(count>index)
        {
            cout << curr -> data << " ";
            curr = curr-> next;
            index++;
        }
    }
    void display_circular()
       {
 
            Node *curr = head;
            while(curr!=NULL)
            {
                cout << curr -> data << " ";
                curr = curr-> next;
            }
        }
    ~DoublyLinkedList()
     {
         Node *curr = head;
         head = curr -> next;
         delete curr;
         head = curr -> prev;
   
         curr = head;
     }
};

 int main()
 {
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
L.insertAtStart(value);
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
L.insertAtEnd(value);
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
    cout<<"\n--------------------<DELETE OPERATION>----------------------\n";
    cout<<"\n if you want to delete the value form start press S else press E ";
    cin>>D;
    if(D=='s'||D=='S'){
        int size;
        cout<<"\n how many array do you want to dell enter ";
        cin>>size;
        for(int i=0;i<size;i++)
L.deleteFromStart();
    }
    if(D=='e'||D=='E'){
        int size;
        cout<<"\n how many array do you want to dell enter ";
        cin>>size;
        for(int i=0;i<size;i++)
L.deleteFromEnd();
    }
    if((D=='E'||D=='e')||(D=='S'||D=='s')){
        cout<<"\n your array is ";
        L.display();
    }
    else{
        cout<<"you enter wrong comand your array remain same  :\n";
        L.display();
    }
     cout<<"\n--------------------<Check list >--------------------------\n";
     L.check_list();
     cout<<" if you want to check the display in continues form press 1 ";
     int x;
     cin>>x;
     if(x==1)
     {
         L.display_circular();
     }
     else
         cout<<"thnx for not demanding for continues display other wise the compiler gone madddddddd ";
cout<<endl;
return 0;
 }
