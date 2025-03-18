//
//  Q_4.cpp
//  lab-7
//
//  Created by Ahmad Gill on 10/17/22.
//

#include <iostream>
using namespace std;
void print01(int &k,int &i)
{
 
  //  cout<<i<<k<<endl;
    if(i<=k)
    {
        if(k==1)
        {
            int q=k/i;
            int r=k%i;
            i++;
            cout<<r<<q;
            print01(k,i);
        }
        else{
            int q=k/i;
            int r=k%i;
            i++;
         //   cout<<q<<r;
            if(q==k&&r==0)
                cout<<r<<r;
            if(r==0&q<k)
                cout<<r;
            if(q==1&&r==1)
                cout<<r<<r;
            if(q==1&&r==0)
                cout<<q<<q;
            print01(k,i);
        }
    }
    
}
int main()
{
    
    int k=0;
    cout<<"enter the value of k";
    cin>>k;
    int K=k*k;
    int i=1;
    print01(K,i);
}
