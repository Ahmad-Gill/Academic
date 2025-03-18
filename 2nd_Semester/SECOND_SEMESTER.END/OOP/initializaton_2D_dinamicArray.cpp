#include<iostream>
using namespace std;
int main()
{
    int c,r;
    cout<<"enter the value of rows ";
    cin>>r;
    int **arr=new int *[r];
    for(int i=0;i<r;i++)
    {
        cout<<"enter the value of col ";
        cin>>c;
        for(int j=0;j<c;j++)
        {
            arr[i]=new int [c];
        }
    }
     for(int i=0;i<r;i++)
     {
      for(int j=0;j<c;j++)
      {
          cin>>arr[i][j];
      }
     }
for(int i=0;i<r;i++)
     {
      for(int j=0;j<c;j++)
      {
          cout<<arr[i][j]<<"  ";
      }
      cout<<endl;
     }
}