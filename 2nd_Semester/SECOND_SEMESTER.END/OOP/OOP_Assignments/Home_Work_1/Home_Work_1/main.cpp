#include<iostream>
using namespace std;
class SET

{
int *data;
int no_of_Elements;
int Capacity;
public:
SET(int cap=0,int number=0)
{
    this->no_of_Elements= number;
  this->Capacity = cap;
  this->data = new int [Capacity];

  for(int i=0;i<this->no_of_Elements;i++)
  {
      cout<<"Enter the values of "<<i+1<<" element ";
    cin>>this->data[i];
  }
}
SET(   SET &obj)
{
    this->Capacity =  obj.Capacity;
 this->no_of_Elements=obj.no_of_Elements;
  cout<<"copy constucter called! "<<this->no_of_Elements<<endl;
  this->data = new int [this->Capacity];
    for(int i=0;i<obj.no_of_Elements;i++)
    {
        this->data[i]= obj.data[i];

    }
    for(int i=0;i<obj.no_of_Elements;i++)
        cout<<this->data[i];
    
}
    void insert(int number)
    {
       
        if(Capacity == no_of_Elements)
        {
            cout<<"the array  is completely filled :: resizing  the array .....BY one: \n";
        int *New_data;
        New_data = new int[this->Capacity+1];
        for(int  i=0;i<this->no_of_Elements+1;i++)
        {
            New_data[i]=this->data[i];
        }
            cout<<"enter the new element : ";
        cin>>data[Capacity];
        for(int  i=0;i<this->no_of_Elements+1;i++)
            cout<<data[i]<<" ";
    }
        else
        {
            cout<<"the array has space for "<<Capacity-no_of_Elements<<" elements :\n";
            cout<<"enter the new element : ";
           cin>> this->data[no_of_Elements];
          
            for(int  i=0;i<this->no_of_Elements+1;i++)
                cout<<this->data[i]<<" ";
        }
    }
    
void Remove(int n)
        {

   int size = this->no_of_Elements-1;
           int number =0;
            for(int  i=0;i<size+2;i++)
            {
                if(data[i]==n)
                    number++;
            }
                 if(number>0)
                 {
                     cout<<"the number present in the array :\n";
                     for (int i=0;i<size+1; i++) {
                     if(this->data[i]==n)
                     {
                         for(int j=i; j<size; j++)
                             this->data[j] =this->data[j+1];
                     }
                     }
                     cout<<"the updated array after removing in is given below :\n";
                     for(int i=0;i<size;i++)
                         cout<<this->data[i]<<" ";
                     cout<<endl;
                     if((size/2)<=Capacity)
                     {
                          this->Capacity=this->Capacity-((this->Capacity*25)/100);
                         cout<<"new capacity is = "<<this->Capacity<<endl;
                         cout<<"array after resizing \n";
                         for(int i=0;i<size;i++)
                         {
                         cout<<data[i]<<" ";
                         }
                     }
                         
                 }
                else
                 {
                     cout<<"the given number does not exist  ";
                     
                 }
   
  
}
    int getCardinality() const
    {
        return this->no_of_Elements;
    }
    SET Union(SET &s2)
    {
        SET S1;
        int number=0;
        int max=0;
        int i=0;
        int j=0;
        if(this->no_of_Elements >= s2.no_of_Elements)
            max = this->no_of_Elements;
        else
            max = s2.no_of_Elements;
        int compare[100];int count=0;
        for( j =0 ; j < this->no_of_Elements ; j++)
        {
                S1.data[number]=this->data[j];
            number++;
        }
        int k=0;
          for( i = 0 ; i < max ;i++)
            {
                for(int l=0;l<s2.no_of_Elements;l++)
                {
                    
                if(this->data[i] == s2.data[l])
                {
                    //cout<<s2.data[i]<<" ";
                   compare[k] = s2.data[l];
                    count++ ;
                    k++;
                }
                else
                {
                    continue;
                }
                
                }
            }
        for( i = 0 ; i < max ;i++)
        {
            if(compare[i] != s2.data[i])
            {S1.data[number]=s2.data[i];
                number++;
            }
              
          }
        S1.no_of_Elements=number;
        return S1;
    }
    SET intersection(SET &s2)
    {
        SET S2;
   
        int i=0;
     
        int compare[100];int count=0;
        int k=0;
          for( i = 0 ; i < s2.no_of_Elements ;i++)
            {
                for(int l=0;l<s2.no_of_Elements;l++)
                {
                    
                if(this->data[i] == s2.data[l])
                {
                   
                   compare[k] = s2.data[l];
                    count++ ;
    
                    k++;
                }
                else
                {
                    continue;
                }
                
                }
            }
        for(int i=0;i<count;i++)
        {
          S2.data[i]=compare[i];
        }
        S2.no_of_Elements= count;
     
        return S2;
    }
    SET Difference(SET&s2)
    {
        SET S2;
        int i=0;
        cout<<endl;
    
        int compare[100];int count=0;
        int k=0;
          for( i = 0 ; i < this->no_of_Elements ;i++)
            {
                for(int l=0;l<this->no_of_Elements;l++)
                {
                    
                if(this->data[i] == s2.data[l])
                {
                  
                   compare[k] = s2.data[i];
                    count++ ;
    
                    k++;
                }
                else
                {
                    continue;
                }
                
                }
            }
        int compare_1[100];
       int m=0;
        for( int a = 0 ; a < this->no_of_Elements ;a++)
            if(compare[a] != this->data[a])
            { compare_1[m]=this->data[a];
                m++;
            }
   
       for(int h=0;h<m;h++)
        {
            S2.data[h]=compare_1[h];
         
        }
        S2.no_of_Elements= m;
     
        return S2;
    }
    int isMember (int val ) const
    {
        int x=0;
        
        for(int i=0;i<this->no_of_Elements;i++)
        {
            if(val==this->data[i])
                x=1;
        }
        if(x==1)
            return 1;
        else
            return 0;
    }
    int isSubSet (const SET & s2) const
    {
        int x=0;int y=0;
        if(this->no_of_Elements>=s2.no_of_Elements)
           y=1;
        for(int i=0;i<this->no_of_Elements;i++)
        {
            if(this->data[i]==s2.data[i])
            {
                x=1;
            }
           
        }
        if(x==1&&y==0)
        
            return 1;
        
        if(x==1&&y==1)
        
            return 2;
        else
            return 0;
    }
    void reSize (int newcapacity)
    {
        this->Capacity=newcapacity;
    }
    void update(int prVal, int curVal)
    {
        int x=0,y=0;
        for(int i=0;i<this->no_of_Elements;i++)
        {
            if(prVal==this->data[i])
                x=1;
            if(curVal==this->data[i])
                
            {
                y=1;
                cout<<"“Violation set property. ";
                break;
            }
    }
        if(x==0)
        {
            cout<<"Target value not found ";
        }
        
        if(x==1)
        {
            for(int i=0;i<this->no_of_Elements;i++)
            {
                if(prVal==this->data[i])
                {
                    this->data[i]=curVal;
                }
            }
                
        }
           
        for(int i=0;i<this->no_of_Elements;i++)
            cout<<this->data[i];
    }
void show()
{

    for(int i=0;i<this->no_of_Elements;i++)
      cout<<data[i]<<" ";
}
    ~SET()
    {
       // delete data;
        
    }

};
int main()
{
  int y,x;
    cout<<"=======================FIRST SET =====================================\n";
  cout<<"Enter the value of Capacity for first set  : ";
  cin>>x;
    cout<<"enter the no of elements for first set  = ";
    cin>>y;
    while(y>x)
    {
        cout<<"number of elements must be smaller than the capacity : \n enter the number of elements again : ";
        cin>>y;
    }
  SET S1(x,y);
   cout<<"==========================Second Set======================================\n";
    int r,t;
    cout<<"Enter the value of Capacity for first set  : ";
    cin>>r;
      cout<<"enter the no of elements for first set  = ";
      cin>>t;
      while(t>r)
      {
          cout<<"number of elements must be smaller than the capacity : \n enter the number of elements again : ";
          cin>>t;
      }
    SET S2(r,t);
    cout<<" \n=========================    UNION     =============================\n";

   SET Unions = S1.Union(S2);
     Unions.show();
     cout<<" \n====================    Intersection         ========================\n";
   SET Intersection=   S1.intersection(S2);
      
     Intersection.show();
     cout<<" \n====================   DIFFERENCE  ========================\n";
     SET Differences= Unions.Difference(Intersection);
     Differences.show();
     int q;
    cout<<" \n====================   FIND ========================\n";
     cout<<"enter the element to find";
     cin>>q;
   if( S1.isMember(q))
       cout<<"the number present in SET ";
     else
         cout<<"the number is not  present in SET ";
    cout<<" \n==================== proper/improper  ========================\n";
     if(S1.isSubSet(S2)==1)
         cout<<"the given sets are proper Subset ";
     if(S1.isSubSet(S2)==2)
         cout<<"the given sets are improper Subset ";
     if(S1.isSubSet(S2)==0)
         cout<<"the given sets are either  proper nor improper Subset ";
    cout<<" \n====================   NEW CAPACITY ======================\n";
     int a;
     cout<<"enter the new capacity = ";
     cin>>a;
     S1.reSize(a);
     int b,c;
    cout<<" \n====================  UPDATE  ======================\n";
     cout<<"enter the previous value = ";
     cin>>b;
     cout<<"\nenter the current value = ";
     cin>>c;
     S1.update(b, c);
    cout<<" \n====================   Insert value ======================\n";

    S1.insert(1);
    cout<<" \n====================   ELEMENT REMOVE  ======================\n";
    cout<<"enter the element to remove : ";
    int remove;
    cin>>remove;
    S1.Remove(remove);
    cout<<" \n==================== getCardinality   ======================\n";
    cout<<S1.getCardinality()<<endl;

  return 0;
  }
