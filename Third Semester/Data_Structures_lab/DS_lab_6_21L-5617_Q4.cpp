#include <iostream>
using namespace std;
void Merge(int *arr , int l1 , int l2 , int r1 , int r2);
void mergeSort(int *arr , int start , int end)
{
    if(start<end)
    {
        int mid=(start + end)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid + 1,end);
        Merge(arr,start,mid,mid + 1,end);
    }
}
void Merge(int *arr , int l1 , int l2 , int r1 , int r2)
{
    int *temp=new int[r2 - l1 + 1];
    int i = l1,j = r1,k = 0;
    while(i <= l2 && j <= r2)
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= l2)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= r2)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    int start;
    for(start = l1 , k = 0 ; start <= r2 ; start++ , k++)
    {
        arr[start] = temp[k];
    }
    delete [] temp;
    temp = 0;
}
int main()
{
    int size_of_array = 0;
    cout << "Enter Size : ";
    cin >> size_of_array;
    int *arr;
    arr = new int [size_of_array];
    cout << "Enter The Elements For The Array :- " << endl;
    for(int i = 0 ; i < size_of_array ; i++)
    {
        cin >> arr[i];
    }
    cout << "The Entered Array is : ";
    for(int i = 0 ; i < size_of_array ; i++)
    {
        cout << arr[i] << " ";
    }
    mergeSort(arr , 0 , size_of_array-1);
    cout<<endl;
    cout << "Final Array ";
    for(int i = 0 ; i < size_of_array ; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
