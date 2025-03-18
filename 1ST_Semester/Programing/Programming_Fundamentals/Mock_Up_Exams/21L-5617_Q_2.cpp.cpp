#include<iostream>
using namespace  std ;
void Ballance_point(int arr[][5]){
	int counter=0;int i=0;int j=0;
	cout<<"the input array is given as :\n\n";
	for( i;i<5;i++){
		for( j;j<5;j++)
		cout<<arr[i][j]<<" ";
		cout<<"\n";
	}
	for( i;i<5;i++){
		for( j;j<5;j++){
		if(arr[i][1]+arr[i][j-1] ==arr[i][j+1]+arr[i][j+2])
		counter ++;
		if(arr[0][j]+arr[1][j] ==arr[i+1][j]+arr[i+2][j])
		counter ++;
}
}
cout<<"the requird ballance points is = "<<counter;
}
int main(){
	int array[5][5];
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++)
		cin>>array[i][j];
	}


Ballance_point(array);
return 0;
}

