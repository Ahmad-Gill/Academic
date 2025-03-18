//
//  Q_2.cpp
//  lab_9
//
//  Created by Ahmad Gill on 11/7/22.
//

#include<iostream>
#include<fstream>
using namespace std;
class student;
class MinHeap
{
    string *arr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int totalItems; // Current number of elements in min heap
public:
    // Constructor
    MinHeap()
    {
        totalItems = 0;
        capacity = 20;
        arr = new string[10];
    }
    void swap(string *x, string *y)
    {
        string temp = *x;
        *x = *y;
        *y = temp;
    }
    // to heapify a subtree with the root at given index
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < totalItems && arr[l] < arr[i])
            smallest = l;
        if (r <totalItems && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(&arr[i], &arr[smallest]);
            MinHeapify(smallest);
        }
    }
  
    int parent(int i) {
        return (i-1)/2;
        
    }
  
    // to get index of left child of node at index i
    int left(int i) {
        return (2*i + 1);
        
    }
  
    // to get index of right child of node at index i
    int right(int i)
    {
        return (2*i + 2);
        
    }
  
    // to extract the root which is the minimum element
    string extractMin()
    {
        if (totalItems <= 0)
        {
            
        }
        if (totalItems == 1)
        {
            totalItems--;
            return arr[0];
        }
      
        // Store the minimum value, and remove it from heap
        string root = arr[0];
        arr[0] = arr[totalItems-1];
        totalItems--;
        MinHeapify(0);
      
        return root;
    }
  
    // Decreases key value of key at index i to new_val
    void decreaseKey(int i, int new_val)
    {
        arr[i] = new_val;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
           swap(&arr[i], &arr[parent(i)]);
           i = parent(i);
        }
    }
  
    // Returns the minimum key (key at root) from min heap
    string getMin() {
        return arr[0];
        
    }
  
    // Deletes a key stored at index i
    void deleteKey(int i=0)
    {
        if(totalItems==0)
            cout<<" headp is empty "<<endl;
        decreaseKey(i, INT_MIN);
        extractMin();
    }
  
    // Inserts a new key 'k'
    void insertKey(string k)
    {
        if (totalItems == capacity)
        {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }
      
        // First insert the new key at the end
        totalItems++;
        int i = totalItems - 1;
        arr[i] = k;
      
        // Fix the min heap property if it is violated
        while (i != 0 && arr[parent(i)] > arr[i])
        {
           swap(&arr[i], &arr[parent(i)]);
           i = parent(i);
        }
    }
    bool isEmpty()
    {
        if(totalItems==0)
            return true;
        else
            return false;
    }
    void print()
    {
        cout<<" min heap is given as >> ";
        for(int i=0;i<totalItems;i++)
            cout<<arr[i]<<" ";
    }
};
class student
{
    friend class MinHeap;
    MinHeap m_;
    string rollNumber;
    string name;
    string cgpa;
public:
    student()
    {
        
        rollNumber="";
        name="";
        cgpa="";
    }
    ostream & operator << ( student &c)
    {
       // m_.print();;
        cout <<" students roll number = "<<c.rollNumber<<endl;
        cout <<" students name  = "<<c.name<<endl;
        cout <<" students cpga  = "<<c.cgpa<<endl;
        return cout;
    }
    void buildStudentHeap(string fileName, MinHeap &m)
    {
        fstream input;
        input.open(fileName);
        for(int i=0;i<18;i++)
        {
           
           
            string line;
            line="";
            getline(input, line);
          //  m.insertKey(line);
            m.insertKey(line);
          //  cout<<line;
        }
    }
    void roll(string n)
    {
        rollNumber=n;
    }
    void name_(string n)
    {
        name=n;
    }
    void gpa(string n)
    {
        cgpa=n;
    }
    void setInformation(string s)
    {
        int i=0;
        string n;
        int size=s.length();
        n="";
        int j=0;
        for(;s[i]!=' ';i++)
        {
            n[j]=s[i];
            j++;
        }
        string m="";
        for (int k = 0; k <j; k++)
            m = m + n[k];
        j=0;
        i++;
        roll(m);
        n="";
        m="";
        for(;s[i]!=' ';i++)
        {
            n[j]=s[i];
            j++;
            
        }
         m="";
       
        for (int k = 0; k <j; k++)
            m = m + n[k];
            j=0;
            i++;
            name_(m);
        
        n="";
        m="";
        for(;i<size-1;i++)
        {
            n[j]=s[i];
            j++;
            
        }
         m="";
        for (int k = 0; k <j; k++)
            m = m + n[k];
            j=0;
            i++;
            gpa(m);
        
    }
};
int main()
{
    student s;
    MinHeap stdHeap;
    s.buildStudentHeap("/Users/Ahmad_gill/Downloads/students.txt",stdHeap);
   // s.operator<<(s);
   // stdHeap.print();
   // stdHeap.print();
    for(int i=0;i<10;i++)
    {
        cout<<"\n data of "<<i+1<<" student \n ";
        string a="";
        a= stdHeap.extractMin();
      //  cout<<a<<endl;
        s.setInformation(a);
        s.operator<<(s);
        stdHeap.extractMin();
        //stdHeap.print();
    }
    
}

