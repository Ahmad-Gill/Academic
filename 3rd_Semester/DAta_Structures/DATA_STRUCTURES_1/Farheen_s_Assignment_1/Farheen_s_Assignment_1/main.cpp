//
//  main.cpp
//  Farheen's_Assignment_1
//
//  Created by Ahmad Gill on 9/29/22.
//

#include <iostream>
using  namespace std;
class strings
{
    char* string_ ;
    int size;
    int word_count;
    int unique_word;
    int total_frequency=0;
public:
    strings( )
    {
        string_=new char[1000];
    }
    void   string_input()
    {
        cout<<" ehter the string ";
        cin.ignore();
        cin.get(this->string_,1000);
        cin.ignore();
        this->size=strlen(string_);
    }
    char * string_out()
    {
        cout<<"the orignal string is {> "<<this->string_<<" <} ";
        return this->string_;
    }
    int  get_size()
    {
        return this->size;
    }
    int get_word_count()
    {
        for(int i=0;i<=this->size;i++)
        {
            if(this->string_[i]!=' ')
                word_count++;
        }
        return this->word_count;
    }
    int unique_words()
    {
        char *c =new char[100];
        int length=0;
        int h=0;
        int b=0;
        for(int i=0;i<this->size;i++)
            c[i]=' ';
        for(int i=0;i<this->size;i++)
        {
            if(string_[i]!=' '&&string_[i+1]!=' ')
            {
                for(int d=0;d<this->size;d++)
                    c[d]=' ';
                for(int j=0;string_[i]!=' '&&i<size;j++)
                {
                    c[j]=string_[i];
                    i++;
                }
                length=0;
                for(int z=0;c[z]!=' ';z++)
                    length++;
                for(int k=i;k<size;k++)
                {
                    int q=0;
                    if(c[q]==string_[k])
                    {
                        h=0;
                        b=0;
                        for(int x=0;c[q]!=' '&&string_[k]!=' ';x++)
                        {
                            
                            if(c[b]==string_[k])
                            {
                                h++;
                            }
                            b++;
                            k++;
                            q++;
                        }
                        if(h==length)
                        {
                            total_frequency++;
                            break;
                        }
                    }
                }
                
            }
            
        }
        
        return this->total_frequency;
    }
    void UNIGRAM()
    {
        cout<<" ehter the string ";
        char*new_string_=new char[1000];
        for(int i=0;i<1000;i++)
            new_string_[i]=' ';
        
        cin.get(new_string_,1000);
        cin.ignore();
        int new_size=strlen(new_string_);
        int length=0;
        int d=0;
        int h=0;
        int b=0;
        char *c =new char[100];
        for(int i=0;i<new_size;i++)
            c[i]=' ';
        for(int i=0;i<new_size;i++)
        {
            for(int n=0;n<100;n++)
                c[i]=' ';
            if(new_string_[i]!=' '&&new_string_[i+1]!=' ')
            {
                d=0;
                for(int m=0;m<100;m++)
                    c[m]=' ';
                for(int j=0;new_string_[i]!=' '&&i<new_size;j++)
                {
                    c[j]=new_string_[i];
                    i++;
                }
                length=0;
                for(int z=0;c[z]!=' ';z++)
                    length++;
                for(int k=0;k<this->size;k++)
                {
                    int q=0;
                    if(c[q]==string_[k])
                    {
                        h=0;
                        b=0;
                        for(int x=0;x<size;x++)
                        {
                            if(b==length)
                            {
                                k++;
                                b=0;
                            }
                            if(c[b]==string_[k])
                            {
                                h++;
                                b++;
                            }
                            k++;
                            q++;
                        }
                        if((h/length))
                        {
                            d++;
                        }
                    }
                }
                cout<<"the word ";
                for(int r=0;r<length;r++)
                    cout<<c[r];
                cout<<" repeats "<<(h/length)<<" times "<<endl;;
                
            }
        }
    }
    void BI_IGRAM()
    {
        cout<<" ehter the string ";
        char*new_string_=new char[1000];
        for(int i=0;i<1000;i++)
            new_string_[i]=' ';
        cin.get(new_string_,1000);
        cin.ignore();
        int new_size=strlen(new_string_);
        int length=0;
        int index_=0;
        int g=0;
        int d=0;
        int h=0;
        int b=0;
        int z=0;
        int s=0;
        int k=0;
        char *c =new char[100];
        for(int i=0;i<100;i++)
            c[i]=' ';
        int i=0;
        for( ;i<new_size;i++)
        {
            for(int n=0;n<100;n++)
                c[n]=' ';
            if(new_string_[i]!=' '&&new_string_[i+1]!=' ')
            {
                d=0;
                for(int m=0;m<100;m++)
                    c[m]=' ';
                int j=0;
                s=0;
                for( j=0;new_string_[i]!=' ';j++)
                {
                    c[j]=new_string_[i];
                    i++;
                    s++;
                    index_=1;
                }
                for( g=j;new_string_[i+1]!=' '&&i<new_size-1;g++)
                {
                    c[g]=string_[i];
                    i++;
                    s++;
                    index_=2;
                }
                if(index_==2)
                {
                    c[g]=string_[i];
                    i++;
                    s++;
                }
                if(index_==2)
                {
                    length=0;
                    for( z=0;z<s;z++)
                        length++;
                    
                    for( k=0;k<this->size;k++)
                    {
                        int q=0;
                        if(c[q]==string_[k]&&c[q+1]==string_[k+1])
                        {
                            h=0;
                            b=0;
                            for(int x=k;x<size;x++)
                            {
                                if(b==length)
                                {
                                    k++;
                                    b=0;
                                }
                                
                                if(c[b]==string_[k])
                                {
                                    h++;
                                    b++;
                                }
                                k++;
                                q++;
                            }
                            if(h/2==length-1)
                            {
                                d=d+2;
                            }
                            if(h==length-1)
                            {
                                d=d+1;
                            }
                        }
                    }
                }
                else
                {
                    cout<<" this is not a BI_word "<<endl;
                    break;
                }
                cout<<"the word ";
                for(int r=0;r<length+1;r++)
                    cout<<c[r];
                cout<<" repeats "<<h/length<<" times "<<endl;;
            }
        }
    }
    void TRI_IGRAM()
    {
        cout<<" ehter the string ";
        char*new_string_=new char[1000];
        for(int i=0;i<1000;i++)
            new_string_[i]=' ';
        cin.get(new_string_,1000);
        cin.ignore();
        int new_size=strlen(new_string_);
        int length=0;
        int index_=0;
        int g=0;
        int d=0;
        int h=0;
        int b=0;
        int z=0;
        int s=0;
        int k=0;
        int l=0;
        char *c =new char[100];
        for(int i=0;i<100;i++)
            c[i]=' ';
        int i=0;
        for( ;i<new_size;i++)
        {
            for(int n=0;n<100;n++)
                c[n]=' ';
            if(new_string_[i]!=' '&&new_string_[i+1]!=' ')
            {
                d=0;
                for(int m=0;m<100;m++)
                    c[m]=' ';
                int j=0;
                s=0;
                for( j=0;new_string_[i]!=' ';j++)
                {
                    c[j]=new_string_[i];
                    i++;
                    s++;
                    index_=1;
                }
                for( g=j;new_string_[i+1]!=' '&&i<new_size-1;g++)
                {
                    c[g]=new_string_[i];
                    i++;
                    s++;
                    index_=2;
                }
                if(index_==2)
                {
                    c[g]=new_string_[i];
                    i++;
                    s++;
                }
                for( l=g+1;new_string_[i+1]!=' '&&i<new_size-1;l++)
                {
                    c[l]=string_[i];
                    i++;
                    s++;
                    index_=3;
                }
                if(index_==3)
                {
                    c[l]=string_[i];
                    i++;
                    s++;
                }
                if(index_==3)
                {
                    length=0;
                    for( z=0;z<s;z++)
                        length++;
                    for( k=0;k<this->size;k++)
                    {
                        int q=0;
                        if(c[q]==string_[k]&&c[q+1]==string_[k+1])
                        {
                            h=0;
                            b=0;
                            for(int x=k;x<size;x++)
                            {
                                if(b==length)
                                {
                                    k++;
                                    b=0;
                                }
                                
                                if(c[b]==string_[k])
                                {
                                    
                                    h++;
                                    b++;
                                }
                                k++;
                                q++;
                            }
                            if(h/2==length-1)
                            {
                                d=d+2;
                            }
                            if(h==length-1)
                            {
                                d=d+1;
                                
                            }
                        }
                    }
                }
                else
                {
                    cout<<" this is not a BI_word "<<endl;
                    break;
                }
                cout<<"the word ";
                for(int r=0;r<length+1;r++)
                    cout<<c[r];
                cout<<" repeats "<<h/length<<" times "<<endl;;
            }
        }
    }
    ~strings()
    {
        delete [] string_;
        string_=0;
        
    }
    
};
void rorate(int *&n1,int *&n2,int *&n3)
{
    cout<<"---------------<the old values are>----------------------------\n";
    cout<<"  n1= "<<*n1<<" n2 = "<<*n2<<" n3 = "<<*n3<<endl;
    int *temp;
    temp=n1;
    n1=n3;
    n3=n2;
    n2=temp;
    cout<<"---------------<the new values are>----------------------------\n";
    cout<<" n1= "<<*n1<<" n2 = "<<*n2<<" n3 = "<<*n3<<endl;
}
char * INPUT_A(char *SET_A,int n1)
{
    for(int i=0;i<n1;i++)
    {
        cout<<"enter the "<<i+1<<" value of set ";
        cin>>SET_A[i];
        while(SET_A[i]<='A'||SET_A[i]>='z')
        {
            cout<<"please enter char only ";
            cin>>SET_A[i];
        }
        for(int j=0;j<i;j++)
        {
            while(SET_A[i]==SET_A[j])
            {
                cout<<" invalid input please enter non repeqating value ";
                cin>>SET_A[i];
            }
        }
    }
    return SET_A;
}
void display(char *set,int n)
{
    cout<<" { ";
    for(int i=0;i<n;i++)
    {
        cout<<set[i]<<" , ";
    }
    cout<<" } ";
    
}
char* union_of_array(int size1,int size2,char *arr1,char *arr2,int &size_union_array)
{
    int i=0;
    int k=0;
    int j=0;
    char*new_array=new char [size1+size2];
    for(int a =0;a<size1+size2;a++)
        *(new_array+a)=' ';
    for(;i<size1;i++)
    {
        *(new_array+i)=*(arr1+i);
    }
    
    for(j=0;j<size2;j++)
    {
        int  index=0;
        for(k=0;k<size1;k++)
        {
            if(arr1[k]==arr2[j])
            {
                index=1;
                break;
            }
        }
        if(index!=1)
        {
            *(new_array+i)=arr2[j];
            i++;
        }
    }
    int count=0;
    for(int a =0;a<size1+size2;a++)
    {
        if( *(new_array+a)==' ')
            count++;
    }
    size_union_array=(size1+size2)-count;
    return new_array;
}
char* Intersection_of_array(int size1,int size2,char *arr1,char *arr2,int &size_union_array)
{
    int i=0;
    int k=0;
    int j=0;
    char*new_array=new char [size1+size2];
    for(int a =0;a<size1+size2;a++)
        *(new_array+a)=' ';
    for(j=0;j<size2;j++)
    {
        int  index=0;
        for(k=0;k<size1;k++)
        {
            if(arr1[k]==arr2[j])
            {
                index=1;
                break;
            }
        }
        if(index==1)
        {
            *(new_array+i)=arr2[j];
            i++;
        }
    }
    int count=0;
    for(int a =0;a<size1+size2;a++)
    {
        if( *(new_array+a)==' ')
            count++;
    }
    size_union_array=(size1+size2)-count;
    return new_array;
}
char* UNION_INPUT(char*setA)
{
    char c='a';
    char*new_array=new char [26];
    for(int a =0;a<26;a++)
    {
        *(new_array+a)=c;
        c++;
    }
    return new_array;
}
char* U_MINUS_(int U_size,int A_U_B_S,char *U,char *A_U_B,int &size_u_B_array)
{
    int i=0;
    int k=0;
    int j=0;
    char*new_array=new char [U_size+A_U_B_S];
    for(int a =0;a<U_size+A_U_B_S;a++)
        *(new_array+a)=' ';
    for(j=0;j<U_size;j++)
    {
        int  index=0;
        for(k=0;k<A_U_B_S;k++)
        {
            if(U[j]==A_U_B[k])
            {
                index=1;
                break;
            }
        }
        if(index!=1)
        {
            *(new_array+i)=U[j];
            i++;
        }
        
    }
    int count=0;
    for(int a =0;a<U_size+A_U_B_S;a++)
    {
        if( *(new_array+a)==' ')
            count++;
    }
    size_u_B_array=(U_size+A_U_B_S)-count;
    return new_array;
}
void Histogram(int size)
{
    char * Histogram=new char [size+size];
    for(int i=0;i<size+size;i++)
        *(Histogram+i)='*';
    for(int i=0;i<size+size;i++)
        cout<< *(Histogram+i);
}
int main() {
    char *str=new char [100];
    int p=0,e=0,i=0,o=0,u=0;
    int *sorted_array=new int [5];
    for(int k = 0; k<100; k++)
        str[k]=' ';
    cout<<"--------------------------------------------------------------\n";
    cout<<"//////////////////<QUESTION NO 1>/////////////////////////////\n";
    cout<<"--------------------------------------------------------------\n";
    cout<<"ENTER THE STRING ";
    cin.get(str,100);
    int consonants=-1;
    int v=0;
    for(int k=0;k<100;k++)
    {
        if(str [k]=='a')
            p++;
        else  if(str [k]=='e')
            e++;
        else if(str [k]=='i')
            i++;
        else  if(str [k]=='o')
            o++;
        else  if(str [k]=='u')
            u++;
        if(str[k]!='a'&&str[k]!='i'&&str[k]!='e'&&str[k]!='o'&&str[k]!='u'&&str[k]!=' ')
            consonants++;
    }
    if(p>0)
        v++;
    if(e>0)
        v++;
    if(i>0)
        v++;
    if(o>0)
        v++;
    if(u>0)
        v++;
    sorted_array[0]=p;
    sorted_array[1]=e;
    sorted_array[2]=i;
    sorted_array[3]=o;
    sorted_array[4]=u;
    int temp;
    for(int k=0; k<5; k++)
    {
        for(int j=0; j<4; j++)
        {
            if(sorted_array[j]>sorted_array[j+1])
            {
                temp = sorted_array[j];
                sorted_array[j] = sorted_array[j+1];
                sorted_array[j+1] = temp;
            }
        }
    }
    cout<<" VOVEL WORDS = "<<v<<endl;
    cout<<" number of  consonants = "<< consonants<<endl;;
    for(int k= 4; k>=0; k--)
    {
        int index=0;
        if(str[k]>0)
        {
            if(sorted_array[k]==p&&p>0)
            {
                cout<<"Total a values = "<<p<<endl;
                index++;
            }
            if(sorted_array[k]==e&&e>0)
            {
                index++;
                cout<<"Total e values = "<<e<<endl;
            }
            if(sorted_array[k]==i&&i>0)
            { index++;
                cout<<"Total i values = "<<i<<endl;
            }
            if(sorted_array[k]==o&&o>0)
            {
                index++;
                cout<<"Total o values = "<<o<<endl;
            }
            if(sorted_array[k]==u&&u>0)
            {
                index++;
                cout<<"Total u values = "<<u<<endl;
            }
            if (index==2)
                k--;
            if(index==3)
                k=k-2;
            if(index==4)
                k=k-3;
            if(index==5)
                k=k-4;
        }
    }
    cout<<"--------------------------------------------------------------\n";
    cout<<"//////////////////<QUESTION NO 2>/////////////////////////////\n";
    cout<<"--------------------------------------------------------------\n";
    int *number_1 = nullptr,*number_2 = nullptr,*number_3 = nullptr;
    cout<<"ENTER THE FIRST NUMBER ";
    number_1=new int;
    number_2=new int;
    number_3=new int;
    cin>>*number_1;
    cout<<"ENTER THE SECOND NUMBER ";
    cin>> *number_2;
    cout<<"ENTER THE THIRD NUMBER ";
    cin>> *number_3;
    int *a,*b,*c;
    a=new int;
    b=new int;
    c=new int;
    a=number_1;
    b=number_2;
    c=number_3;
    rorate(a,b, c);
    cout<<"--------------------------------------------------------------\n";
    cout<<"//////////////////<QUESTION NO 3>/////////////////////////////\n";
    cout<<"--------------------------------------------------------------\n";
    int n1,n2;
    cout<<"\n---------------<FIRST SET-----------------------------------\n";
    cout<<"enter size of first array = ";
    cin>>n1;
    while(n1<=0)
    {
        cout<<" size must be greater than zero ";
        cin>>n1;
    }
    char * SET_A=new char[n1];
    SET_A=INPUT_A(SET_A, n1);
    display(SET_A, n1);
    cout<<"\n--------------<SECOND SET>----------------------------------\n";
    cout<<"enter size of second array = ";
    cin>>n2;
    while(n2<=0)
    {
        cout<<" size must be greater than zero ";
        cin>>n2;
    }
    char * SET_B=new char [n2];
    SET_B=INPUT_A(SET_B, n2);
    
    display(SET_B, n2);
    int U_size=n1+n2;
    int I_size=n1+n2;
    cout<<"\n--------------<UNION OF TWO SETS>---------------------------\n";
    char * SET_U=new char [U_size];
    SET_U=union_of_array(n1, n2, SET_A, SET_B, U_size);
    display(SET_U, U_size);
    cout<<"\n--------------<INTERSECTION OF TWO SETS>--------------------\n";
    char * SET_I=new char [I_size];
    SET_I=Intersection_of_array(n1, n2, SET_A, SET_B, I_size);
    display(SET_I, I_size);
    cout<<"\n--------------<U-(AUB)>-------------------------------------\n";
    int size=26;
    char*U_SET=new char[size];
    U_SET=UNION_INPUT(SET_U);
    char * U_MINUS_A_U_B=new char [size];
    U_MINUS_A_U_B=U_MINUS_(size, U_size, U_SET, SET_U,size);
    display(U_MINUS_A_U_B, size);
    cout<<"\n--------------<U- A>----------------------------------------\n";
    int size1=26;
    char * U_MINUS_A=new char [size1];
    U_MINUS_A=U_MINUS_(size1, n1, U_SET, SET_A,size1);
    display(U_MINUS_A, size1);
    cout<<"\n--------------<U- B>----------------------------------------\n";
    int size3=26;
    char * U_MINUS_B=new char [size3];
    U_MINUS_B=U_MINUS_(size3, n2, U_SET, SET_B,size3);
    display(U_MINUS_B, size3);
    cout<<"\n------------------------------------------------------------\n";
    cout<<"//////////////////<QUESTION NO 4>/////////////////////////////\n";
    cout<<"--------------------------------------------------------------\n";
    int H_Size;
    cout<<" ENTER THE SIZE OF HISTOGRAM ";
    cin>>H_Size;
    while(H_Size<0)
    {
        cout<<" size must be positive enter again ";
        cin>>H_Size;
    }
    Histogram(H_Size);
    cout<<endl;
    
    cout<<"---------------------------------------------------------------\n";
    cout<<"//////////////////<QUESTION NO 5>//////////////////////////////\n";
    cout<<"---------------------------------------------------------------\n";
    cout<<"-------------------PART A--------------------------------------\n";
    strings S;
    S.string_input();
    int string_size=S.get_size();
    cout<<"total length of string = "<<string_size<<endl;
    int word_count=S.get_word_count();
    cout<<"total number of words = "<<word_count<<endl;
    cout<<"-------------------PART A--------------------------------------\n";
    cout<< "Total repeating words = "<<S.unique_words()<<endl;
    cout<<"-------------------UNI_GRAM------------------------------------\n";
    S.UNIGRAM();
    cout<<"-------------------BI_GRAM-------------------------------------\n";
    S.BI_IGRAM();
    cout<<"-------------------TRI_GRAM------------------------------------\n";
    S.TRI_IGRAM();
    return 0;
}
