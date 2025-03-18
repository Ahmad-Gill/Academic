//
//  main.cpp
//  PF
//
//  Created by Ahmad Gill on 18/05/2022.
//

#include <iostream>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//int mat_1[6][6],mat_2[6][6],mat_3[6][6],row1=0,row2=0,col1=0,col=0,frow1=0,frow2=0,fcol1=0.fcol2=0;
void FileInput(int M1[][6], int M2[][6], int &r1,int &r2, int &c1, int &c2){
ifstream infile("/Users/ahma-gill/Desktop/Matrix.txt");
if(infile.is_open())
{
    
    infile>>r1>>c1;
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            infile>>M1[i][j];
        }
        cout<<endl;
        }
        infile>>r2>>c2;
        for(int a=0;a<r2;a++){
        for(int b=0;b<c2;b++){
            infile>>M2[a][b];
        }
        cout<<endl;
    }
}
cout<<"now the data has been fetched from the file\n";
}
void Print(int M1[][6], int r, int c)
    {
    for(int i=0;i<r;i++)
    {
        for (int j=0; j<c; j++) {
            cout<<M1[i][j]<<" ";
        }
        cout<<endl;
    }
        
    }
void Addition(int M1[][6],int M2[][6],int M3[][6],int r1,int r2 ,int r3,int c1,int c2,int c3)
{
   // cout<<r1<<r2<<endl;
    r3=3;
    c3=4;
    if (r1==r2&&c1==c2)
    {
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c1;j++)
        {
            M3[i][j]=M1[i][j]+M2[i][j];
        }
    }
        for(int i=0;i<r3;i++)
        {
        for(int j=0;j<c3;j++)
        {
            cout<<M3[i][j]<<" ";
    }
        cout<<endl;
        }
    }
    else
        cout<<"No of rows != No of Coloums  Addition is not posible \n";
        
}
void Multipliction(int M1[][6],int M2[][6],int M3[][6],int r1,int r2 ,int r3,int c1,int c2,int c3)
{
   // cout<<r1<<r2<<endl;
    r3=3;
    c3=4;
    if (c1==r2)
    {
        for(int i = 0; i < r1; ++i)
        {
              for(int j = 0; j < c2; ++j)
              {
                  for(int k = 0; k < c1; ++k)
                  {
                      M3[i][j] += M1[i][k] * M2[k][j];
                  }
              }
        }
        for(int i=0;i<r3;i++)
        {
            
        for(int j=0;j<c3;j++)
        {
            cout<<M3[i][j]<<" ";
    }
        cout<<endl;
        }
    }
    else
        cout<<"column of first matrix != roes  of second matrix   Multiplication is not posible \n";
        
}

int main(){
    int mat_1[6][6],mat_2[6][6],mat_3[6][6];
    int r1=0,r2=0,c1=0,c2=0;
    FileInput(mat_1,mat_2,r1,r2,c1,c2);
    cout<<"first matrix \n";
    Print(mat_1, r1, c1);
    cout<<"\nsecond  matrix \n";
    Print(mat_2, r2, c2);
    int c3=0,r3=0;
    cout<<"\n Addition \n";
    Addition(mat_1,mat_1,mat_3, r1, r2 , r3, c1, c2, c3);
    cout<<"\nMultiplication \n";
    Multipliction(mat_1,mat_1,mat_3, r1, r2 , r3, c1, c2, c3);
    return 0;
}
