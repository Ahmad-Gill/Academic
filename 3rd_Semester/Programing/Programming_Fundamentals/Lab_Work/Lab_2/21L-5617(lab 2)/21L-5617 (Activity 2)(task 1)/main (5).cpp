/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    
    int n, r, sum=0, p=1;
    cin>> n;
    if (n< 100000){
        cout << "not a six digit no , too small";
    }
    else{
        if (n >= 100000 & n <= 999999) {
            while (n > 0) {
                r=n%10;
                n=n/10;
                sum=sum + r ;
                p = p * r;
    }
        }
          else {
                cout << "not a six digit number " << "too small";
                
        }
        cout << "sum:" <<sum<<" "<<"product:"<< p;
 
    }
}