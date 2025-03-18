/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main() {
    int x1, x2, x3, y1, y2, y3;
    cout<< "enter x1 cordinate of P";
    cin>>x1;
    cout << "enter x2 left top corner P ";
    cin>>x2;
    cout << "enter x3 right bottom corner P";
    cin>>x3;
    cout << "enter y1 cordinate of P ";
    cin >> y1;
    cout << "enter y2 left top corner P ";
    cin>> y2;
    cout << "enter y3 right bottom corner ";
    cin >> y3;
    if (x1 >=x2 & y1 >= y3 & x1<=x3 & y1 <=y3){
        cout << "P lise in region ";}
        else {
            cout << "p lies outside the region "; 
        }
    return 0;
    
}
    