//
//  Q_3.cpp
//  lab-7
//
//  Created by Ahmad Gill on 10/17/22.
//

#include <iostream>
using namespace std;
void comaPlacing(string s,string s1,int &coma,int &count,int i)
{
    if(count<s.length())
    {
        if(coma>=1)
        {
            
            if(count==0)
            {
                s1[i]=s[count];
                s1[i+1]=',';
                i++;
                i++;
                count++;
                coma--;
                comaPlacing(s, s1, coma, count, i);
            
                
            }
            else{
                if(count%3==0)
                    
                {
                    s1[i]=s[count];
                    s1[i+1]=',';
                    coma--;
                    i++;
                    i++;
                    count++;
                    comaPlacing(s, s1, coma, count, i);
                }
                else
                {
                    s1[i]=s[count];
                    count++;
                    i++;
                    comaPlacing(s, s1, coma, count, i);
                }
            }
        }
            else
            {
                s1[i]=s[count];
                count++;
                i++;
                comaPlacing(s, s1, coma, count, i);
            }
            
            
        }
    
    else{
        for(int j=0;j<i;j++)
        {
            cout<<s1[j];
            if(j>=i)
                break;
        }

    }

}


int main()
{
    string s;
    int size;
    cout<<"enter the tring ";
    cin>>s;
    cout<<"the orignal string string is ";
    cout<<s<<endl;
    size=s.length();
    int coma=(size/2)-1;
    string s1;

    int i=0;
    int count=0;
    comaPlacing(s, s1, coma, count, i);
    cout<<endl;
    
}

