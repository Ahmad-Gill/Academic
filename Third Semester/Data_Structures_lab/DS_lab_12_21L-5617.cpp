//
//  main.cpp
//  lab_12
//
//  Created by Ahmad Gill on 11/28/22.
//
#include <iostream>
#include <fstream>
using namespace std;

template <class t>
struct HashItem
{
    int key;
    t value;
    int status=0;
    int getKey()
    {
        return key;
    }
};

template <typename t>
class HashMap
{
private:
    HashItem<t> *hashArray;
    bool flag=1;
    int currentElements;
    virtual int getNextCandidateIndex(int key, int i)
    {
        return (key + i) % capacity;
    }

public:
    int capacity;
    HashMap()
    {
        capacity = 20;
        currentElements = 0;
        hashArray = new HashItem<t>[capacity];
    }
    HashMap(int const capacity)
    {
        this->capacity = capacity;
        currentElements = 0;
        hashArray = new HashItem<t>[capacity];
    }
    void insert(int const key, t const value)
    {
        int arrayIndex = key % capacity;
        if (currentElements > capacity )
        {
            doubleCapacity();
        }
        if (hashArray[arrayIndex].status == 0 || hashArray[arrayIndex].status == 1)
        {
            
            hashArray[arrayIndex].value = value;
            hashArray[arrayIndex].key = key;
            hashArray[arrayIndex].status = 2;
            currentElements++;
        }
        else
        {
            for (int k = 1; hashArray[arrayIndex].status == 2; k++)
            {
                arrayIndex = getNextCandidateIndex(key, k);
            }
            hashArray[arrayIndex].value = value;
            hashArray[arrayIndex].key = key;
            hashArray[arrayIndex].status = 2;
            currentElements++;
        }
    }
    void doubleCapacity()
    {
        capacity *= 2;
        HashItem<t> *temp = new HashItem<t>[capacity];
        for (int k = 0; k < capacity / 2; k++)
        {
            temp[k] = hashArray[k];
        }
        hashArray = temp;
    }
    bool deleteKey(int const key)
    {
        int index = key % capacity;
        if (hashArray[index].status == 2)
        {
            hashArray[index].status = 1;
            currentElements--;
            return 1;
        }
        return 0;
    }
    t *get(int const key)
    {
        int arrayIndex = key % capacity;
        t* temp;
        if(hashArray[arrayIndex].status==2){
            temp=&hashArray[arrayIndex].value;
        }
        else
            temp=nullptr;
        return temp;
    }
    ~HashMap()
    {
        delete[] hashArray;
        hashArray = nullptr;
    }
    void display()
    {
        
        for(int i=0;i<capacity;i++)
            cout<<hashArray[i].key<<" "<<hashArray[i].value<<endl;
    }
};
template <typename v>
class QHashMap : public HashMap<v>
{
    public:
    int getNextCandidateIndex(int key, int i)
    {
        i *= i;
        return (key + i) % this->capacity;
    }
};
template <typename v>
class DHashMap : public HashMap<v>
{
    public:
    int getNextCandidateIndex(int key, int i)
    {
        int first = key % this->capacity;
        int second = (2 - (key % 2));
        first=(first + i * second) % this->capacity;
        return first;
    }
};

void populateHash(string filename, HashMap<string> *&hash)
{
    ifstream file;
        file.open(filename);
    int n, key;
    string name;
    file >> n;
    file.ignore(100, '\n');
    for (int k = 0; k <18 ; k++)
    {
        file >> key;
       // cout<<key;
        file.ignore();
        file >> name;
       // cout<<name<<endl;
        hash->insert(key, name);
        file.ignore(100, '\n');
    }
}

int main()
{
    cout<<"--------populateHash-------------------------\n";
    HashMap<string> *map;
    map = new HashMap<string>;
    populateHash("/Users/Ahmad_gill/Downloads/students-2.txt", map);
    cout<<"enter the value to get; = ";
    int get1;
    cin>>get1;
   // map->display();
    string *value= map->get(get1);
    if(value==NULL)
        cout<<" value not present ";
    else
        cout<<"the value at key "<<get1<<" is = "<<*value;

 cout<<"\n--------QHashMap-------------------------\n";
    map = new QHashMap<string>;
    populateHash("/Users/Ahmad_gill/Downloads/students-2.txt", map);
    cout<<"enter the value to get; = ";
    int get2;
    cin>>get2;
    string *value2= map->get(get2);
    if(value2==NULL)
        cout<<" value not present ";
    else
        cout<<"the value at key "<<get2<<" is = "<<*value2;
    delete map;
    
 cout<<"\n-----------DHashMap----------------------\n";
    map = new DHashMap<string>;
    populateHash("/Users/Ahmad_gill/Downloads/students-2.txt", map);
    cout<<"enter the value to get; = ";
    int get3;
    cin>>get3;
    string *value3= map->get(get3);
    if(value==NULL)
        cout<<" value not present ";
    else
        cout<<"the value at key "<<get3<<" is = "<<*value3;
    delete map;
    cout<<endl;
    return 0;
}
