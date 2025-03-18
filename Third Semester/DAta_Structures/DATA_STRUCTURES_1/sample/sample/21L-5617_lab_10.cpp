//
//  main.cpp
//  lab_9
//
//  Created by Ahmad Gill on 11/7/22.
//

#include<iostream>
using namespace std;
class MaxHeap
{
    int *arr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int totalItems; // Current number of elements in min heap
    int count=0;
public:
    MaxHeap()
    {
    
        arr = nullptr;
    }
    // Constructor
    MaxHeap(int cap)
    {
        totalItems = 0;
        capacity = cap;
        arr = new int[cap];
    }
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    // to heapify a subtree with the root at given index
    void MaxHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l > totalItems && arr[l] > arr[i])
            smallest = l;
        if (r >totalItems && arr[r] > arr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(&arr[i], &arr[smallest]);
            MaxHeapify(smallest);
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
    int extractMax()
    {
        if (totalItems <= 0)
            return INT_MAX;
        if (totalItems == 1)
        {
            totalItems--;
            return arr[0];
        }
      
        // Store the minimum value, and remove it from heap
        int root = arr[0];
        arr[0] = arr[totalItems-1];
        totalItems--;
        MaxHeapify(0);
      
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
    int getMax() {
        return arr[0];
        
    }
  
    // Deletes a key stored at index i
    void deleteKey(int i=0)
    {
        if(totalItems==0)
            cout<<" headp is empty "<<endl;
        decreaseKey(i, INT_MIN);
        extractMax();
    }
  
    // Inserts a new key 'k'
    void insertKey(int k)
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
        while (i != 0 && arr[parent(i)] < arr[i])
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
    
        cout<<" MAX heap is given as >> ";
        for(int i=0;i<totalItems;i++)
            cout<<arr[i]<<" ";
    }
    ~MaxHeap()
    {
        delete arr;
        arr=0;
    }
    bool CheckMaxHeap()
    {
        int x=0;
        int i=0;
        for(i=0;arr[(2*i)+1]!=NULL&&arr[(2*i)+2]!=NULL;i++)
        {
            if(arr[i]>arr[(2*i)+1]&&arr[i]>arr[(2*i)+2])
                x++;
        }
        if(x==i)
            return true;
             else
                 return false;
    }
    int detKthMAX(int k)
    {
        while(k>totalItems)
        {
            cout<<"invalid k shuld be less or equal totalnumber ";
            cin>>k;
        } // first the array is merged then check
        return arr[k];
    }
    void merge(MaxHeap&h,MaxHeap&h1,MaxHeap&h2)
    {
        int i=0;
        for(int k=h.totalItems;k>0;i++,k--)
        {
            int t= h.arr[k-1];
            h2.totalItems++;
            h2.arr[i]=t;
          
        }
        for(int j=h1.totalItems;j>0;j--,i++)
        {
            
            int t= h1.arr[j-1];
            h2.totalItems++;
            h2.arr[i]=t;
          
        }
       // cout<<h2.arr[0];
        //cout<<" the Combine Heap is = ";
        //h2.print();
    }
    void count_rotation(int *x, int *y)
    {
        count++;
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    void posible_rotations(MaxHeap&h0,MaxHeap&h,MaxHeap&h1,MaxHeap&h2)
    {
        int k=0;
    
     
        //cout<<" h2.array = >> ";
        for(int j=0;j<h1.totalItems;j++)
        {
           // cout<<h1.arr[j]<<"  ";
        }

        cout<<endl;
        int x=-1;
        for( k=0;k<h1.totalItems;k++)
        {
            
          
            x++;
            h2.arr[x]=h1.arr[k];
          
            
            // Fix the min heap property if it is violated
            while (x != 0 && h2.arr[parent(x)] < h2.arr[x])
            {
                count_rotation(&h2.arr[x], &h2.arr[parent(x)]);
            }
        }
        int i=0;
        for(int k=0;k<h.totalItems;i++,k++)
        {
            int t= h.arr[k];
            h2.totalItems++;
            h2.arr[i]=t;
          
        }
        for(int j=0;j<h0.totalItems;j++,i++)
        {
            
            int t= h0.arr[j];
            h2.totalItems++;
            h2.arr[i]=t;
          
        }
        h2.print();
        cout<<" posible number of rotation to get "<<h2.arr[0]<<" as maximum is = "<<count<<endl;
    }
    
    
        
};
  
int main()
{
    cout<<"enter the capacity of heap ";
    int n;
    cin>>n;
    MaxHeap h(n);
    MaxHeap h1(n);
    h.insertKey(4);
    h.insertKey(5);
    h.insertKey(6);
    h.insertKey(7);
    cout<<"\n----First Heap------\n";
    h.print();
    cout<<endl;
    cout<<endl;
    cout<<"\n----check that the heap is max or not ------\n";
    if(h.CheckMaxHeap())
        cout<<" the given heap is MAX_HEAP \n";
    else
        cout<<" The given Heap is  Max_Heap \n";
    int k;
    cout<<"\n----KTH Maximum ------\n";
    cout<<" enter the value of k ";
    cin>>k;
    int x=h.detKthMAX(k-1);
    cout<<"\n kth maximum = "<<x<<endl;

   
    h1.insertKey(10);
    h1.insertKey(100);
    cout<<"\n----second Heap------\n";
    h1.print();
    cout<<endl;
    MaxHeap h2(n);
    
    h1.merge(h, h1,h2);
    MaxHeap h3(n);
    cout<<"\n----Mearage the given heaps ------\n";
   h1.posible_rotations(h,h1,h2, h3);
    
    return 0;
}

