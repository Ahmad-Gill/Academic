//
//  main.cpp
//  lab_9
//
//  Created by Ahmad Gill on 11/7/22.
//

#include<iostream>
using namespace std;
class MinHeap
{
    int *arr; // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int totalItems; // Current number of elements in min heap
public:
    MinHeap()
    {
    
        arr = nullptr;
    }
    // Constructor
    MinHeap(int cap)
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
    int extractMin()
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
    int getMin() {
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
    ~MinHeap()
    {
        delete arr;
        arr=0;
    }
    
};
  
int main()
{
    cout<<"enter the capacity of heap ";
    int n;
    cin>>n;
    MinHeap h(n);
    
    h.insertKey(3);
    h.insertKey(2);
    h.deleteKey();
  //  h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    h.print();
   // cout << h.extractMin() << " ";
   // cout << h.getMin() << " ";
   // h.decreaseKey(2, 1);
   // cout << h.getMin();
    return 0;
}

