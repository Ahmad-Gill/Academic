#include <iostream>
#include <fstream>
using namespace std;

int main(){
	int option;
	char a[100];
	cout<<" ENCRYPT DATA"<< endl << " DECRYPT DATA";
	cin>>option;
	
	if(option==1){
		ifstream inFile;
		ofstream outFile;
		inFile.open("input.txt");
		outFile.open("encrypt.txt");
		inFile.getline(a,100);
		for(int i=0; i<100 && a[i] !='\0';i++){
			a[i]++;
			}
		cout<<a;
		outFile << a;
		inFile.close();
		outFile.close();
	}
	
	else if(option == 2){
		ifstream inFile;
		ofstream outFile;
		inFile.open("encrypt.txt");
		outFile.open("decrypt.txt");
		
		inFile.getline(a,100);
		
		for(int i=0;i<100 && a[i] !='\0';i++){
			a[i]--;
		}
		cout<<a;
		outFile<<a;
		inFile.close();
		outFile.close();
			}
	else
	cout<<"TRY AGAIN"<<endl;
	system ("pause");
	return 0;
}