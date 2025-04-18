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

	void insertAtHead(int element)
	{
		Node *temp = new Node;
		temp -> data = element;
		temp -> next = head;
		temp -> prev = head;
		head = temp;
	}

	void insertAtTail(int element)
	{
		Node *temp = new Node;
		temp -> data = element;
		temp -> next = nullptr;
		temp -> prev = nullptr;
		Node *curr = head;
		while(curr != nullptr)
		{
			temp -> prev = curr;
			curr = curr -> next;
		}
		if(temp -> prev == nullptr)
		{
			head = temp;
		}
		else
		{
			temp -> prev -> next = temp;
		}
	}

    void deleteAtStart()
	{
		if(head == nullptr)
		{
			cout << "List is Empty" <<endl;
		}

		{
			Node *curr = head;
			head = curr -> next;
			curr = nullptr;
			delete curr;
			curr = 0;
		}
	}

	void deleteAtEnd()
	{
		if(head == nullptr)
		{
			cout << "List is empty" << endl;
		}
		else
		{
			Node *curr = head , *last = 0 , *secondlast = 0;
			while(curr != nullptr)
			{
				secondlast = last;
				last = curr;
				curr = curr-> next;
			}
			if(secondlast -> next == nullptr)
			{
				head = nullptr;
				curr -> next = nullptr;
				curr -> prev = nullptr;
				delete last;
				last -> next = nullptr;
				last -> prev = nullptr;
			}
			else
			{
				secondlast -> next = nullptr;
				delete last;
				last -> next = nullptr;
				last-> prev = nullptr;
			}
		}
	}

	void printReverse()
	{
		Node *curr = head;
		while(curr->next != nullptr)
		{
			curr = curr -> next;
		}
		while(curr != nullptr)
		{
			cout << curr-> data << " ";
			curr = curr -> prev;
		}
	}

	void print()
	{
		Node *curr = head;
		while(curr != 0)
		{cout << curr-> data << " ";
		curr = curr -> next;
		}
	}

	~DoublyLinkedList()
	{
	     Node *curr = head;
	    while(curr != nullptr)
        {
            head = curr -> next;
            delete curr;
            head = curr -> prev;
            delete curr;
            curr = head;
        }
	}
};

int main()
{
	DoublyLinkedList DL;
	DL.insertAtHead(5);
	DL.insertAtHead(7);
	DL.insertAtHead(4);
	DL.insertAtTail(10);
	DL.insertAtTail(16);
	cout<<"Linked List : "<<endl;
	DL.print();
	cout<<endl;
	cout<<"Deletition At Start : ";
	DL.deleteAtStart();
	DL.print();
	cout<<endl;
	cout << "Deletition At End : ";
	DL.deleteAtEnd();
	DL.print();
	cout << endl;
	cout<< "Linked List In Reverse Order : ";
	DL.printReverse();
	cout << "7";
	cout<<endl;
	return 0;
}

