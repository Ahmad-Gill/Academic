#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
char file[20] = "infile.txt";
char name[10][15];
int Quantity[10];
float Price[10];
int n = 10;
  
ifstream infile("infile.txt");
if(!infile.is_open())
{
cout << "Could not open input file " << file << endl;
return 1;
}
  

cout << left << setw(7) << "Code" << setw(15) << "Name" << setw(10) << "Quantity" << setw(10) << "Price" << endl;
for(int i = 0; i < n; i++)
{
infile >> name[i] >> Quantity[i] >> Price[i];
cout << setw(7) << (i+1) << setw(15) << name[i] << setw(10) << Quantity[i] << setw(10) << Price[i] << endl;

}
infile.close();
cout << endl;
  
  
  
string bill = "";
int code;
float total = 0, subtotal;
string answer;
do
{
cout << "Enter the code of the item to buy [1- 10]: ";
cin >> code;
if(code < 1 || code > n)
cout << "Invalid code " << endl;
else
{
int qty;
cout << "How many ? ";
cin >> qty;
subtotal = qty * Price[code-1];
total+= subtotal;
Quantity[code-1] -= qty;
bill = bill + name[code-1] + " " + to_string(qty) + " @ $" + to_string(Price[code-1]) + " = " + to_string(subtotal) + "\n";
}
  
cout << "Do you want to buy more y/n ? ";
cin >> answer;
  
}while(answer == "y" || answer == "Y");
  
cout << "Your bill is " << endl << bill << "Total $" << total << endl;
  

ofstream outfile("file.txt");
  
for(int i = 0; i < n; i++)
outfile << name[i] << " " << Quantity[i] << " " << Price[i] << endl;
outfile.close();
}