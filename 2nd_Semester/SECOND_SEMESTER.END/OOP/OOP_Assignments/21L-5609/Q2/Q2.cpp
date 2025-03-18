#include <iostream>
#include<vector>
using namespace std;
int **fillArray(int **TD , int r , int c[100])
{

    cout<<"enter the elements for 2-D Array"<<endl;
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c[i] ; j++)
        {
            cin >> TD[i][j];
           if(TD[i][j] < 0)
            {
                cout<<"The program does not support negative values"<<endl;
                cout<<"please enter the value again"<<endl;
            }
        }
    }
    return TD;
}
int* twoDimToOneDim(int **TD , int r , int size , int a[100])
{
    int *OD = new int[size];
    cin.ignore();
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < a[i] ; j++)
    {
        OD[i] = TD[i][j];
    }
    }
     return OD;
}
int *SortArr(int *OD , int size)
{
    int temp = 0 ;
    for(int i = 0 ; i < size ; i++)
    {
        if(OD[i+1] < OD[i])
        {
            temp = OD[i];
            OD[i] = OD[i+1];
            OD[i+1] = temp;
         }
    }
    return OD;
}
void showArr(int *OD , int size)
{
    cout<<"The Contents Of The Updated Array Are : ";
    for(int i = 0 ; i < size ; i++)
    {
        cout << OD[i];
    }
}
/*void Deallocation(sortArr(twoDimToOneDim(OD,  r , size , a) , int size),size)
{
     for (int i = 0 ; i < r ; i++)
        {
            delete[] OD[i];
        }
        delete[] OD;
}*/
int main()
{
    int r , c , size = 0  ;
    cout<<"enter the rows for an array : ";
    cin>>r;
    int a[100];
    int **TD;
    TD = new int *[r];
    cin.ignore();
     for(int i = 0 ; i < r ; i++)
    {
        cout<<"Enter the number of columns for row no."<<i<<" : ";
        cin >> a[i];
        size = size + a[i];
        TD[i]=new int[a[i]];
    }
    int *OD;
    fillArray(TD , r ,  a);
    twoDimToOneDim(TD , r , size , a);
    SortArr( OD , size);
    showArr( OD , size);
   // Deallocation( SortArr(twoDimToOneDim(TD , r , size , a) , size) , size);
    return 0;
}
