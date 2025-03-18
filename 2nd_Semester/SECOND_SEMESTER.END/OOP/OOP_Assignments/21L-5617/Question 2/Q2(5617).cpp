#include <iostream>
using namespace std;

   int** fillArray(int**,int[],int);
   int* twoDimToOneDim(int**,int[],int);
   int* sortArr(int*,int);
   void showArr(int*, int);

    int main()
    {
        int row;
        int col[100] = { 0 };
        cout << "Enter Rows of dynamic Array =  " ;
        cin >> row;
        int** arr = new int* [row];
        for (int i = 0;i<row;i++)
        {
            cout << "Enter Column No " << i << " of dynamic Array = " ;
            cin >> col[i];
            arr[i] = new int[col[i]];
        }

        fillArray(arr,col,row);
        cout<<"the orignal array is given below \n";
        for (int i = 0;i < row; i++)
        {
            for (int j = 0; j < col[i];j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }

        int size1= 0; //size of 1d array
        for (int i = 0; i < 100;i++)
        {
            size1 += col[i];
        }
        showArr(sortArr(twoDimToOneDim(arr, col, row), size1),size1);
        for (int i = 0;i < row;i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        return 0;
    }
 
    int** fillArray(int** arr,int col[],int row)
    {
        for (int i = 0;i < row;i++)
        {
            for (int j = 0; j < col[i];j++)
            {
                cout<<"enter the value";
                cin >> arr[i][j];
            }
        }
        return arr;
    }
    int* twoDimToOneDim(int** arr, int cols[], int row)
    {
        int size=0 , k=0;
        for (int i = 0; i < 100 ;i++)
            size += cols[i];
        int* array = new int[size];
        for (int i = 0;i < row;i++)
        {
            for (int j = 0; j < cols[i];j++)
            {
               array[k]=arr[i][j];
               k++;
            }
        }

        cout << " Elements in 1D array are = ";
         for (int i = 0; i < k;i++)
           {
                cout<<array[i]<<" ";
         }
        
         return array;
    }
    int* sortArr(int* array, int size1)
    {
        int temp;
        for (int i = 0; i < size1 ; i++)
        {
            for (int j = i + 1; j < size1; j++)
            {
                if (array[j] < array[i])
                {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
        return array;
    }
    void showArr(int* array, int size1)
    {
        cout << "\nSorted array is: \n";
        for (int i = 0;i < size1;i++)
        {
            cout << *(array + i)<<" ";
        }
    }