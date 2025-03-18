#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> split(string strings, char delimiter) {
  vector<string> tokanize_words;
  stringstream ss(strings); // Turn the string into a stream.
  string tokanize;
 
  while(getline(ss, tokanize, delimiter))
  {
    tokanize_words.push_back(tokanize);
  }
 
  return tokanize_words;
}
int main()
{
    
    ifstream inFile ("/Users/ahma-gill/Desktop/21L-5617/Question 1/synonym.txt");
    vector<string> array_of_words;
    string lines;
    int totalLines = 0;
    while (getline (inFile, lines))
    {
        totalLines++;
        
    }
    string **synonyms = new string *[totalLines];
    inFile.clear ();
    inFile.seekg (0, inFile.beg);
    string line;
    int lineNo = 0;
    while (getline (inFile, line))
    {
        vector<string> lineArray = split(line, ' ');
        int sizeOfArray = lineArray.size();
        synonyms[lineNo] = new string[sizeOfArray];
        for (int i=0;i < sizeOfArray;i++){
            if (i == 0)
            {
                array_of_words.push_back(lineArray[i]);
            }
            else
            {
                synonyms[lineNo][i - 1]=lineArray[i];
            }
}
        lineNo++;
    }
    
    string sentence;
    cout << "Enter Text : ";
    getline(cin, sentence);
    
    vector<string> sentenceArray = split(sentence, ' ');
    
    for (int i = 0;i<sentenceArray.size();i++){
        
        string word = sentenceArray[i];
        for (int y = 0;y<array_of_words.size();y++){
            
            if(word == array_of_words[y]){
                int noOfSynonyms = sizeof(synonyms[y]) / 4;
                int random =(rand() % noOfSynonyms);
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
