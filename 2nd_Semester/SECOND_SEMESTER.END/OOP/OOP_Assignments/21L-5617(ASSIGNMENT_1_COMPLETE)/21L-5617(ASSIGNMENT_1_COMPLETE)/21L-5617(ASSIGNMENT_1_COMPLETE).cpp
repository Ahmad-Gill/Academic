//
//  main.cpp
//  21L-5617(ASSIGNMENT_1_COMPLETE)
//
//  Created by Ahmad Gill on 24/05/2022.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <time.h>
using namespace std;



int main()
{
    
    ifstream input ("synonym.txt");
    vector<string> a;
    string b;
    int total = 0;
    
    while (getline (inFile, b)) {
        
        total++;
        
    }
    string **word = new string *[total];
    inFile.clear ();
    inFile.seekg (0, input.beg);
  
    string l;
   
    int No = 0;
    
    while (getline (input, l))
    {
        
        vector<string> lA = split(l, ' ');
        
        int size = lA.size() - 1;
        word[No] = new string[size];
        
        int i = 0;
        while (i <= size){
            if (i == 0) {
                a.push_back(lA[i]);
            } else {
                words[No][i - 1]=lA[i];
            }
            i++;
        }
        No++;
    }
    
    string text;
    cout << "Enter the sentence : ";
    getline(cin, text);
    
    vector<string> sA = split(text, ' ');
    
    for (int i = 0;i<text.size();i++){
        
        string w = sA[i];
        for (int j = 0;j<a.size();j++){
            
            if(w == kA[j]){
                int number = sizeof(words[j]) / sizeof(int);
                int c = 0 + (rand() % number);
                sA[i] = words[j][c];
                break ;
            }
        }
    }
  vector<string> d;
  stringstream s(str); // Turn the string into a stream.
  string t;
 
  while(getline(s, t, delimiter)) {
    d.push_back(t);
}
    int i;
    string e = "";
    for (i = 0; i < size; i++) {
        i = i + f[i];
    }
    for(int k=0; k<sA.size(); k++){
        cout << sA.at(k) << endl;
    }
    

    return 0;
}





#include <iostream>
using namespace std;

   int** fillArray(int**,int[],int);
   int* twoDimToOneDim(int**,int[],int);
   int* sortArr(int*,int);
   void showArr(int*, int);

    int main()
    {
        int row;
        int col[100] = { 0 };
        cout << "Enter Rows of dynamic Array =  " ;
        cin >> row;
        int** arr = new int* [row];
        for (int i = 0;i<row;i++)
        {
            cout << "Enter Column No " << i << " of dynamic Array = " ;
            cin >> col[i];
            arr[i] = new int[col[i]];
        }

        fillArray(arr,col,row);
        cout<<"the orignal array is given below \n";
        for (int i = 0;i < row; i++)
        {
            for (int j = 0; j < col[i];j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }

        int size1= 0; //size of 1d array
        for (int i = 0; i < 100;i++)
        {
            size1 += col[i];
        }
        showArr(sortArr(twoDimToOneDim(arr, col, row), size1),size1);
        for (int i = 0;i < row;i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
        return 0;
    }
 
    int** fillArray(int** arr,int col[],int row)
    {
        for (int i = 0;i < row;i++)
        {
            for (int j = 0; j < col[i];j++)
            {
                cout<<"enter the value";
                cin >> arr[i][j];
            }
        }
        return arr;
    }
    int* twoDimToOneDim(int** arr, int cols[], int row)
    {
        int size=0 , k=0;
        for (int i = 0; i < 100 ;i++)
            size += cols[i];
        int* array = new int[size];
        for (int i = 0;i < row;i++)
        {
            for (int j = 0; j < cols[i];j++)
            {
               array[k]=arr[i][j];
               k++;
            }
        }

        cout << " Elements in 1D array are = ";
         for (int i = 0; i < k;i++)
           {
                cout<<array[i]<<" ";
         }
        
         return array;
    }
    int* sortArr(int* array, int size1)
    {
        int temp;
        for (int i = 0; i < size1 ; i++)
        {
            for (int j = i + 1; j < size1; j++)
            {
                if (array[j] < array[i])
                {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
        return array;
    }
    void showArr(int* array, int size1)
    {
        cout << "\nSorted array is: \n";
        for (int i = 0;i < size1;i++)
        {
            cout << *(array + i)<<" ";
        }
    }
