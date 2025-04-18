//
//  main.cpp
//  Assignment_2(21L-5617)
//
//  Created by Ahmad Gill on 11/1/22.
//
#include<iostream>
#include<fstream>
#include <stdio.h>

using namespace std;
class BST;
class Node {
    friend class BST;
    string data;
    int repetation;
    Node *next , *prev;
};
class TreeNode
{
    friend class BST;
    string data; // The value in the node
    int  number[5000];//array use in storage of duplicates
    TreeNode *left; // Pointer to left child node
    TreeNode *right; // Pointer to right child node
    int x=0;
public:
    TreeNode()
    {
        for(int i=0;i<5000;i++)
            number[i]=-1;
    }
};
class BST
{
    Node* head;
    TreeNode* root;
    int count=0;
    int x=0;
    bool insertAtEnd(string val) // function to save URL`s
    {
        Node *temp = new Node;
        temp -> data = val;
        temp->repetation=0;
        temp -> next = nullptr;
        temp -> prev = nullptr;
        Node *curr = head;
        if(curr==0)
        {
            head=temp;
        }
        while(curr!= nullptr)
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
    
    void inOrder(TreeNode* t)
    {
        if (t != 0)
        {
            inOrder(t->left);
            cout << t->data << " ";
            inOrder(t->right);
        }
    }
    //We are catching the root value by-reference so we dont need any extra function to connect the newly created node
    //to the tree.
    void insert(TreeNode*& t,string val,int x)
    {
        if (t == 0)
        {
            t = new TreeNode;
            t->data = val;
            t->left = nullptr;
            t->right = nullptr;
            t->number[0]=x;
            
        }
        else if (val < t->data)
        {
            insert(t->left, val,x);
        }
        else if (val > t->data)
        {
            insert(t->right, val,x);
        }
        else if(val==t->data)
        {
            int v=0;
            for(int i=0;t->number[i]!=-1;i++)
                v++;
            t->number[v]=x;
        }
    }
public:
    BST()
    {
        root = nullptr;
        head = nullptr;
    }
    void DESTROY(TreeNode* cur) {
        if(cur != nullptr) {
            
            if( (cur->left == nullptr) && (cur->right == nullptr) ) {
                cur = nullptr;
            } else {
                DESTROY(cur->left);
                DESTROY(cur->right);
            }
        }
        return;
    }
    ~BST()
    {
        DESTROY(root);
    }
    void inOrder()
    {
        inOrder(root);
    }
    void insertURL(string URL)
    {
        
        insertAtEnd(URL);
    }
    void insert(string key,int x)
    {
        insert(root, key,x);
    }
    int search(string val)
    {
        int x=-1;
        TreeNode* t=root;
        
        while (t != 0)
        {
            if (t->data == val)
            {
                cout << val<<" exists...!\n";
                for(int i=0;t->number[i]!=-1;i++)
                {
                    x++;
                    if(t->number[i]!=t->number[i+1])
                    {
                        
                        Display(t->number[i],x);
                    }
                    
                }
                return x;
            }
            else if (val < t->data)
                t = t->left;
            else
                t = t->right;
        }
        cout << val << " does not exist...!\n";
        return -1;
    }
    bool remove(string val)
    {
        TreeNode* curr = root, *parent = 0;
        while (curr != 0 && curr->data != val)
        {
            parent = curr;
            if (val < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (curr == 0)
            return false;
        else
        {
            if (curr->left != 0 && curr->right != 0)
            {
                TreeNode *l = curr->left, *pl = curr;
                while (l->right != 0)
                {
                    pl = l;
                    l = l->right;
                }
                curr->data = l->data;
                curr = l;
                parent = pl;
            }
            TreeNode* child;
            if (curr->left != 0)
            {
                child = curr->left;
            }
            else
            {
                child = curr->right;
            }
            if (curr == root)
            {
                root = child;
            }
            else
            {
                if (curr == parent->left)
                    parent->left = child;
                else
                    parent->right = child;
            }
            delete curr;
            curr = 0;
            return true;
        }
    }
    void Display(int x,int y) {
        Node* curr = head;
        int i=0;
        while (i!=x) {
            curr = curr->next;
            i++;
        }
        if(y==1)
            cout <<y<<"st URL >> "<< curr->data << " "<<endl;
        else if(y==2)
            cout <<y<<"nd URL >> "<< curr->data << " "<<endl;
        else if(y==3)
            cout <<y<<"rd URL >> "<< curr->data << " "<<endl;
        else
            cout <<y<<"th URL >> "<< curr->data << " "<<endl;
    }//end of Display
};
bool search(string s,BST b1)
{
    clock_t start, end;
    
    if(s!="-")
    {
        start = clock();
        cout<<"\n\n";
        int m= b1.search(s);
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout <<m+1<<"reults found in " << fixed
        << time_taken << setprecision(1);
        cout << " seconds " << endl;
        double microseconds = time_taken * 1000000;
        cout<<" and in "<<microseconds<<" Microseconds \n"<<endl;
        string s="";
        cout<<"enter the world to search or press - to exit >> ";
        cin>>s;
        search(s,b1);
        
    }
    else
    {
        cout<<" exit the program \n";
        return true;
    }
    return true;
    
}
int main()
{
    BST b1;
    string uRL[58];
    string key[58];
    string kewwords[58];
    fstream input;
    string name;
    cout<<"please enter the file name >> ";
    cin>>name;
    while(name!="data.txt")
    {
        cout<<" the file does not exist enter the existing file >> ";
        cin>>name;
    }
    input.open("/Users/Ahmad_gill/Downloads/data.txt");
    
    int i=0;
    clock_t start, end;
    start = clock();
    while( i<=53){; //read data from file object and put it into string.
        
        string URL;
        getline(input, URL);
        uRL[i]=URL;
        b1.insertURL(uRL[i]);
        string Keywords;
        getline(input, Keywords);
        kewwords[i]=Keywords;
        string space;
        getline(input, space);
        i++;
    }
    int x=0;
    for(int i=0;i<=53;i++)
    {
        string s=kewwords[i];
        s[201]=' ';
        int size_=s.length();
        char b[100];
        for(int x=0;x<100;x++)
            b[x]=' ';
        int k=0;
        for(int j=0;j<=size_;j++)
        {
            if(s[k]!='\0')
            {
                if(s[k]!=' ')
                {
                    b[j]=s[k];
                    k++;
                }
                else
                {
                    j=-1;
                    k++;
                    string m="";
                    int size=0;
                    for ( int n=0;b[n]!=' '; n++)
                        size++;
                    for (int n = 0; n <=size-1; n++)
                        m = m + b[n];
                    b1.insert(m,x);
                    for(int x=0;x<100;x++)
                        b[x]=' ';
                }
            }
            else
            {
                x++;
                break;
            }
        }
    }
    end = clock();
    cout<<"\n\n";
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout <<"File loaded into the BST successfully. 53 URLs loaded from the file in " << fixed
    << time_taken << setprecision(5);
    cout << " seconds " << endl;
    double microseconds = time_taken * 1000000;
    cout<<" and in "<<microseconds<<" Microseconds "<<endl;
    cout<<endl;
    cout<<" enter the value to delete  or press 0 to exit ";
    string del;
    cin>>del;
    while(del!="0")
    {
        if(b1.remove( del))
        {
            cout<<"\nthe world "<<del<<" delete successfully \n";
        }
        else
            cout<<" the value does not exist ";
        cout<<"\n enter the value to delete  or press 0 to exit >> ";
        del="";
        cin>>del;
    }
    cout<<endl;
    string search_;
    cout<<"enter the word to search or press - to exit >> ";
    cin>>search_;
    search(search_,b1);
    return 0;
}
