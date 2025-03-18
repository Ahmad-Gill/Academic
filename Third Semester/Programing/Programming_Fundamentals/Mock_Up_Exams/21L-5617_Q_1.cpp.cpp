#include<iostream>
using namespace  std ;

void Encrypt(char MessageBlock[],char Encrypted_Message[]){
  char copy[5][5];
  char copy1[5][5];
  cout<<"please enter the same message = \n";
  int j=0;
  int i=0;
	for( i=0;i<5;i++){
		for( j=0;j<5;j++)
		cin>>copy[i][j];
	}
	while(i<=5){
	
for( i;i<5;){
		for( j=0;j<5;j++)
		cout<<copy1[i][j];
	}
	i++;
}
	for( i=0;i<5;i++){
		for( j=0;j<5;j++)
		cout<<copy1[i][j];
	}
}

void Decrypt(char Encrypted_message[],char Message[]){
char	copy[5][5];
char	copy1[5][5];
int j;
int i;
	cout<<"enter the encrypted message";
		for( i=0;i<5;i++){
		for( j=0;j<5;j++)
		cin>>copy[i][j];
}
	while(j<=5){
	
for( i;i<5;i++){
		for( j=0;j<5;j)
		cout<<copy1[i][j];
	}
	j++;
}
	for( i=0;i<5;i++){
		for( j=0;j<5;j++)
		cout<<copy1[i][j];
	}


}
int main(){

 char Message[25];
 char Orignal_message[25];
 cout<<"enter the message = ";
 cin>>Message;
 cout<<"the orignal message is given as";
 cout<<Message;
 char a[25];
 
 char Encrypted_message[100]={0};
  cout<<"the incrypted_message is = ";
  Encrypt(Message,Encrypted_message);
 
 cout<<"the orignal mesaage is = ";
 Decrypt(a,Orignal_message);
 
	return 0;
}