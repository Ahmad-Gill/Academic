/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main(){
    int code ;
    cout << "Enter any asci cod ";
    cin >> code ;
    if (code > 64 & code < 91){
        cout<< "represent an upper case English alphabet "<< endl;
    }
    else{
        if (code > 96 & code< 123) {
            cout << "represent a lower case alphabet "<<endl;
        }
        else{
            if (code >47 & code < 58 ) {
                cout << "represent a digfit" << endl;
            }
            else{
                if (code < 128){
                    cout << "dose not represent a asci code ";
                }
            }
        }
    }
}