#include <iostream>
#include<vector>
using namespace std;

int **fillArray(int **TD , int r , int a[100])
{
   cout<<"Enter the elements for 2-D Array"<<endl;
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < a[i] ; j++)
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

int *twoDimToOneDim(int **TD , int r , int size , int a[100])
{
    int *OD = new int[size];
    cin.ignore();
    cout << "Two Dimensional to one dimensional "<<endl;
    int index = 0;
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < a[i] ; j++)
        {
            OD[i] = TD[i][j];
            index++;
         }
    }
     return OD;
}

int *SortArr(int *OD , int size)
{
    int  min, temp = 0;
    for ( int i = 0; i < size - 1; i++) {
      min = i;
      for (int j = i + 1; j < size; j++)
        if (OD[i+1] < OD[i])
          min = j;
          temp = OD[i];
          OD[i] = OD[min];
          OD[min] = temp;
   }
   return OD;
}

void showArr(int *OD , int size)
{
    for(int i = 0 ; i < size ; i++)
    {
        cout<< OD[i] << endl;
    }
}
int main()
{
    int r , c , size = 0;
    cout << "Enter the rows for the array : ";
    cin >> r;
    int a[100];
    int **TD;
    TD = new int *[r];
    cin.ignore();
     for(int i = 0 ; i < r ; i++)
    {
        cout<<"Enter the number of columns for row no." << i << ": ";
        cin >> a[i];
        size = size + a[i];
        TD[i] = new int[a[i]];
    }

    fillArray(TD , r ,  a);
    int *OD = twoDimToOneDim(TD , r , size , a);
    SortArr(OD , size);
    showArr( OD , size);
    return 0;
}

