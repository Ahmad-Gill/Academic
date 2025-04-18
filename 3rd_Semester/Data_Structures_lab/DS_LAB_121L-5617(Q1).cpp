#include<iostream>
using namespace std;
template <typename T>

T operation(T a,T b,char op)
{
T c;
if(op =='+')
c = a + b;
if(op =='-')
 c = a - b;
if(op =='*')
 c = a *b;
if(op =='/')
 c = a /b;

return c;
}

int main()
{
int a,b;
cout<<"enter the integer value  of a";
cin>>a;
cout<<"enter the integer value  of b";
cin>>b;
float c,d;
cout<<"enter the double/float value  of a";
cin>>c;
cout<<"enter the double/float value  of b";
cin>>d;


char op;
cout<<"enter the character:";
cin>>op;
if(op=='+'||op=='-'||op=='*'||op=='/')
{
cout<<"in case of integers:";
cout<<operation(a,b,op)<<endl;
cout<<"|incase of float value";
cout<<operation(c,d,op)<<endl;
}

else
cout<<"envalid operation";
system("pause");

return 0;
}
