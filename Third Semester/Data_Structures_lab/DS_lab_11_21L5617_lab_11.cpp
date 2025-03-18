#include<iostream>
using namespace std;
class Heap
{
	int maxSize, currSize;
	int* h;
public:
	Heap(int n)
	{
		maxSize = n;
		currSize = 0;
		h = new int[maxSize];
	}
		Heap()
	{
		maxSize = 0;
		currSize = 0;
		h = NULL;
	}
	~Heap()
	{
		if (h != 0)
		{
			delete[] h;
			h = 0;
		}
	}
	
	void heapify(int i)
	{
		int left, right, largest;
		while (1)
		{
			left = 2 * i, right = 2 * i + 1, largest = i;
			if (left <= currSize && h[left] > h[largest])
				largest = left;
			if (right <= currSize && h[right] > h[largest])
				largest = right;
			if (largest==i)
				break;
			else
			{
				swap(h[i],h[largest]);
				i = largest;
			}
		}
	}
	
	void buildHeap(int* a, int n)
	{
		if (h != 0)
		{
			delete[] h;
			h = 0;
		}
		h = new int[n + 1];
		maxSize = n;
		for (int i = 0; i < n; i++)
		{
			h[i + 1] = a[i];
		}
		currSize = n;
		for (int i = currSize/2; i >= 1; i--)
		{
			heapify(i);
		}
	}
	void display()
		
	{
		cout<<"MAX HEAP IS GIVEN BELOW: \n";
		for (int i = 0; i < currSize; i++)
		{
			cout<<h[i + 1]<<" ";
		}
	}
	void removeMax(int & a)
	{
		a = h[1];
		h[1] = h[currSize];
		currSize--;
		heapify(1);
	}
	
};
void heapSort(int* a, int n)
{
	Heap mh;
	mh.buildHeap(a, n);
	for (int i = n - 1; i >= 0; i--)
	{
		mh.removeMax(a[i]);
	}
}
int main()
{
	int size;
	cout<<"enter the size of array = ";
	cin>>size;

	int *arr=new int[size];
	for (int i = 0; i <size; i++)

	{
		cout<<"enter the "<<i+1<<" value of Array = ";
		cin>> arr[i];
	}
	cout<<" orignal Array is given beloe\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout<<endl<<endl;
	
	Heap mh;
	mh.buildHeap(arr, size);
	mh.display();
	cout << endl;
	
	cout << endl;
	heapSort(arr, size);
	cout<<"Sorted array is given \n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 0;
}