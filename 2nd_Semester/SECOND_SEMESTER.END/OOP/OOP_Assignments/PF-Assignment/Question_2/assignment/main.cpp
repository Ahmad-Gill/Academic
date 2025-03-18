#include<iostream>
using namespace std;
int main()
{
    int i, j, rowNum,rowNumTemp, space, num=1,num2=7;
    cout<<"Enter the Number of Rows: ";
    cin>>rowNumTemp;
    if(rowNumTemp%2!=0&&rowNumTemp>0&&rowNumTemp<9)
    {
  rowNum=(rowNumTemp+2)/2;
    space = rowNum-1;
    for(i=1; i<=rowNum; i++)
    {
        for(j=1; j<=space; j++)
            cout<<" ";
        space--;
        for(j=1; j<=(2*i-1); j++)
        {
            cout<<num;
            num+=2;
            
       if(num==11)
          {
            num=7;
            cout<<num;
            num=5;
            cout<<num;
            num=3;
            cout<<num;
            num=1;
            j+=3;
          }
        }
        cout<<endl;
        if(num==11)
      {
        num=1;
      }
    }
    space = 1;
    
  
  
  for(i=1; i<=(rowNum-1); i++)
    {
        for(j=1; j<=space; j++)
            cout<<" ";
        space++;
        for(j=1; j<=(2*(rowNum-i)-1); j++)
        {
            cout<<num;
            num+=2;
         if(num==11)
         {
           for(num2=7;num2<3;num2-=2)
             {
               j++;
               cout<<num2;
             }
           num2=7;
          }
        }
      cout<<endl;
        if(num==11)
      {
        num=1;
      }
    }
    cout<<endl;
    }
    else
        cout<<"envalid input \n";
    return 0;
}
