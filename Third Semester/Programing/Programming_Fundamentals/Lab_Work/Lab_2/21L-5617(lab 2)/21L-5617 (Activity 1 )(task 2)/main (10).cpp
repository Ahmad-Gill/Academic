/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main(){
    int Year;
    cin>>Year;
    if (Year % 400 == 0){
        cout<<Year <<"is aleap year";
    }
    else{
        if (Year % 100 == 0){
            cout<<Year <<"is not aleap year";
        }
        else{
            if (Year % 4 ==0){
                cout<< Year <<"is aleap year";
            }
            else {
                cout<<Year << "is not aleap year";
            }
            
        }
    }

    return 0;
}
