#include <iostream>
using namespace std;
class LinkedList;

class Node {
    friend class LinkedList;
    int data;
    Node* next;//end of class
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;
    }
    bool sortedInsert(int val)
    {
        Node* temp = new Node;
        temp->data = val;
        Node* curr = head, *prev = 0;
        while (curr != NULL && curr->data<val)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev == 0)
        {
            head = temp;
        }
        else
        {
            prev->next = temp;
        }
        temp->next = curr;
        return 1;
    }
    
    
    
    bool deleteFromStart() {
        if (head == nullptr) {
            return 0;
        }
        else {
            Node* curr = head;
            head = curr->next;
            //head=head->next;
            delete curr;
            return 1;
        }
    }//end of deleteFromStart
    
    void Display() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }//end of Display
    
    
    
    bool deleteFromEnd()
    {
        if (head == 0) {
            cout << "List is empty \n ";
            return 0;
        }
        else
        {
            Node* curr = head, * last = 0, * secondLast = 0;
            while (curr != NULL) {
                secondLast = last;
                last = curr->next;
            }
            if (secondLast == 0) {
                head = NULL;
                delete last;
                last = 0;
                cout << "Last Block deleted \n";
                return 1;
            }
            else
            {
                secondLast->next = NULL;
                delete last;
                last = 0;
                cout << "Last Block deleted \n";
                return 1;
            }
        }
    }
    
    void searchindex(int value)
    {
        int i=0;
        Node *curr = head,*pre=0;
        if(head == nullptr)
        {
            cout<<"the link list is empty";
        }
        else
        {
            while(curr != nullptr&&i<=value)
            { pre=curr;
                curr=curr->next;
                i++;
                
            }
            cout<<"the data at index "<< value<<" is = "<<pre->data;
        }
    }
    
    ~LinkedList() {
        while (head != NULL) {
            Node* curr = head;
            head = curr->next;
            delete curr;
            curr = head;
        }
    }
    
};
int main() {
    LinkedList l1;
    cout<<"enter the size of array ";
    int size;
    cin>>size;
    for(int i=0;i<size;i++)
    {
        cout<<"enter the "<<i+1<<" element of array ";
        int n;
        cin>>n;
        l1.sortedInsert(n);
    }
    
    l1.Display();
    cout<<endl;
    cout<<"enter the index to find ";
    int index;
    cin>>index;
    while(index>=0&&index>size)
    {
        
        cout<<" invalid value enter the value again";
        cin>>index;
    }
    l1.searchindex(index);
    //l1.deleteFromEnd();
    //l1.deleteFromStart()
    
    
    system("pause");
    return 0;
}
