#include<iostream>
using namespace std;
void swap(int &a,int& b)
{
  int c;
  c=a;
  a=b;
  b=c;
}
class Matrix
{
int rows;
int col;
int **ary;

public:
void set_No_rows(int s)
{
rows = s;
}
void set_No_col(int s)
{
col = s;
}
int get_rows()
{
return rows;
}
int get_col()
{
return col;
}
void Allpcate_memory()
{
ary = new int*[rows];
for(int i = 0; i < rows; i++) {
    ary[i] = new int[col];
}


}
void input()
{

for(int i=0;i<rows;i++)
{
for(int r=0;r<col;r++)
{
cout<<"enter the valus of matrix row wise: ";

cin>>ary[i][r];
}
}


}
void rotate()
{



int n=0,m=0;
  int r=4,c=4;



  int round=1;
  int col=0;
  int row=0;
for(int c=0;c<12;c++)
  {
    int i=0;int j=0;
    if(round==1)
    {


          m= ary [i+1][j] ; //m=4
          ary [i+1][j] = ary [i][j]; // 0,0
        //n=ary [i+2][j];
          swap(ary [i+2][j],m);//0,0,4 m=8
          swap(ary [i+3][j],m);////0,0,4,8 m=12
        cout<<"\n m= "<<m<<endl;
      round=2;
      }
    if(round==2)
    {
      //m=12


      swap(ary [i+3][j+1],m);//0,0,4,8,12 m=13
swap(ary [i+3][j+2],m);//0,0,4,8,12,13 m=14
      swap(ary [i+3][j+3],m);//0,0,4,8,12,13,14 m=15

         round =3;
    }

     if(round==3)
    {


      swap(ary [i+2][j+3],m);
swap(ary [i+1][j+3],m);//0,0,4,8,12,13
      swap(ary [i][j+3],m);//0,0,4,8,12,13,14

         round =4;
    }

     if(round==4)
    {
     cout<<"\n m last="<<m;
      swap(ary [i][j+2],m);//0,0,4,8,12
swap(ary [i][j+1],m);//0,0,4,8,12,13
    swap(ary [i][j],m);//0,0,4,8,12,14

       round =5;
    }
    if(round ==5)
    {
      break;
    }
  }

}

void display()
{
for(int i=0;i<rows;i++)
{
for(int r=0;r<col;r++)
{

cout<<ary[i][r]<<" ";
}
cout<<endl;
}
}

};
int main()
{
Matrix M;
cout<<"enter the value of rows: ";
int r;
cin>>r;
cout<<"enter the value of col: ";
int c;
cin>>c;
M.set_No_rows(r);
M.set_No_col(c);
M.Allpcate_memory();
M.input();
M.rotate();
M.display();
system("pause");
}
