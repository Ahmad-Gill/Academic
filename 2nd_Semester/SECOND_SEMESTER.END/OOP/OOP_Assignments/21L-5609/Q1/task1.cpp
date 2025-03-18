#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <time.h>
using namespace std;

vector<string> split(string str, char delimiter) { 
  vector<string> internal; 
  stringstream ss(str); // Turn the string into a stream. 
  string tok; 
 
  while(getline(ss, tok, delimiter)) { 
    internal.push_back(tok); 
  } 
 
  return internal; 
}

string convertToString(string* a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}

int main()
{
    
    ifstream inFile ("/Users/ahma-gill/Desktop/21L-5617/Question 1/synonym.txt");
    vector<string> keywordArray;
    string unused;
    int totalLines = 0;
    
    while (getline (inFile, unused)) { totalLines++; }
    string **synonyms = new string *[totalLines];
    inFile.clear ();
    inFile.seekg (0, inFile.beg);
  
    string line;
   
    int lineNo = 0;
    
    while (getline (inFile, line))
    {
        
        vector<string> lineArray = split(line, ' '); 
        
        int sizeOfArray = lineArray.size() - 1;
        synonyms[lineNo] = new string[sizeOfArray];
        
        int i = 0;
        while (i <= sizeOfArray){
            if (i == 0) {
                keywordArray.push_back(lineArray[i]);
            } else {
                synonyms[lineNo][i - 1]=lineArray[i];
            }
            i++;
        }
        lineNo++;
    }
    
    string sentence;
    cout << "Enter Text : ";
    getline(cin, sentence);
    
    vector<string> sentenceArray = split(sentence, ' '); 
    
    for (int i = 0;i<sentenceArray.size();i++){
        
        string word = sentenceArray[i];
        for (int y = 0;y<keywordArray.size();y++){
            
            if(word == keywordArray[y]){
                int noOfSynonyms = sizeof(synonyms[y]) / sizeof(int);
                int random = 0 + (rand() % noOfSynonyms);
                sentenceArray[i] = synonyms[y][random];
                break ;
            }
        }
    }
    
    for(int q=0; q<sentenceArray.size(); q++){
        cout << sentenceArray.at(q) << endl;
    }
    

    return 0;
}
