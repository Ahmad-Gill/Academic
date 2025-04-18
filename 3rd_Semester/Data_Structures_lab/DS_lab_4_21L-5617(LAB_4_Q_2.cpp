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
public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    bool insertAtStart(int val)
    {
        Node *temp = new Node;
        temp -> data = val;
        temp -> next = head;
        temp -> prev = head;
        head = temp;
        return 1;
    }


    bool insertAtEnd(int val)
    {
        Node *temp = new Node;
        temp -> data = val;
        temp -> next = nullptr;
        temp -> prev = nullptr;
        Node *curr = head;
        while(curr != nullptr)
        {
            temp -> prev = curr;
            curr = curr -> next;
        }
        if(temp -> prev == 0)
        {
            head = temp;
            return 1;
        }
        else
        {
            temp -> prev -> next = temp;
            return 1;
        }
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
head->prev=NULL;
            delete curr;
            curr = 0;
            return 1;
        }
}

    bool deleteFromEnd()
    {
        if(head == nullptr)
        {
            cout << "List Is Empty" << endl;
            return 0;
        }
        else
        {
            Node *curr = head , *last = 0 , *secondlast = 0;
            while(curr != nullptr)
            {
                secondlast = last;
                last = curr;
                curr = curr->next;
            }
            if(secondlast -> next == nullptr)
            {
              head = nullptr;
              curr -> next = nullptr;
              curr -> prev = nullptr;
              delete last;
              last -> next = nullptr;
              last -> prev = nullptr;
              cout << "Last Block Deleted" << endl;
            }
            else
            {
                secondlast -> next = nullptr;
                delete last;
                last -> next = nullptr;
                last -> prev = nullptr;
                cout << "Last Block Deleted" << endl;
                return 1;
            }
}
}
void Display_backward()
{
Node *curr = head;
while(curr->next != 0)
        {
            curr = curr-> next;
        }
while(curr!= NULL)
        {
cout<<curr->data<<" ";
curr = curr-> prev;
        }


}
void display()
   {
        Node *curr = head;
        while(curr != 0)
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
         delete curr;
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
L.display();
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
L.display();
    }
    if((I=='E'||I=='e')||(I=='S'||I=='s')){
        cout<<"\nyour input is \n ";
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
    cout<<endl<<"output of array backward ";
L.Display_backward();
cout<<endl;
system("pause");
return 0;
 }
