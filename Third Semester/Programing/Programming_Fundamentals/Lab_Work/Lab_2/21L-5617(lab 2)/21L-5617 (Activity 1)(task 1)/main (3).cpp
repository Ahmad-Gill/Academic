/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>

using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B>> C;
    if(A<=0|| B<=0||C<=0){
        cout << " All angles must be positive: ";
    }
    else 
        if(A + B +C == 180){
            cout << "A triangles can be created";
        } 
        else{ 
            cout << "a triangle cannot be created ";
        }
    return 0;
}
