//  main.cpp
//  OOP_Assignment_2
//
//  Created by Ahmad Gill on 28/03/2022.
#include <iostream>
#include<cstring>
#include<fstream>
#include <sstream>

using namespace std;
class Teacher
{
    string Name;
    string Adress;
    string Contact_Info;
    string Mail_ID;
    string Institution;
    string Department;
    char   type;
    string Designation;
    string  Courses ;
    int Hours[30]  ={0};
    int Hours_Per_week;
    float Monthly_Salary;
    int Experence =0;
    int Publications =0;
    string Qualification;

public:
    
    void set_Name(string a)
    {
        Name =a;
    }
    void set_Adress(string a)
    {
        Adress =a;
    }
    void set_Contect_Info(string a)
    {
        Contact_Info =a;
    }
    void set_Mail_ID(string a)
    {
        Mail_ID =a;
    }
    void set_Institution(string a)
    {
        Institution =a;
    }
    void set_Department (string a)
    {
        Department =a;
    }
    void set_Type(char a)
    {
        type =a;
    }
    void set_Designation(string a)
    {
        Designation =a;
    }
    void set_cources(string a)
    {
        Courses =a;
    }
    
    void set_ced_hours(int arr[])
    {
        
        for(int i=0;arr[i]!='\0';i++)
        {
            
            Hours[i] =  arr[i];
        }
        
    }
    void set_qualification(string a)
    {
        Qualification =a;
    }
    void set_Experience(int *arr)
    {
        Experence = arr[0];
    }
    void set_Publication(int *arr)
    {
        Publications = arr[0];
    }
    void Get_Hours(int arr[])
    { for(int i=0;arr[i]!='\0';i++)
    {
        Hours[i] =  arr[i];
        
    }
    }
    void Getter()
    {
        cout<<"Teacher's Name is :"<<Name<<endl;
        cout<<"Teacher's Adress is : "<<Adress<<endl;
        cout<<"Teacher's contact information is :"<<Contact_Info<<"\n";
        cout<<"Teacher's Mil_ID is :"<<Mail_ID<<endl;
        cout<<"Teacher's institutionis name is : "<<Institution<<"\n";
        cout<<"Teacher's Department name is :"<<Department<<"\n";
        cout<<"Teacher's Type is :"<<type<<endl;
        cout<<"Teacher's DESIGNATION is : "<<Designation<<"\n";
        cout<<"Teacher's cources names are : "<<Courses;
        cout<<"\nTeacher's Crated_Hours is : ";
        for(int i=0;Hours[i]!='\0';i++)
        {
            cout<<Hours[i]<<"  ";
        }
        cout<<"\nTeacher's Experience is : "<<Experence<<"\n";
        cout<<"Teacher's Publications is "<<Publications<<"\n";
        cout<<"Teacher's Qualifications are :"<<Qualification<<endl;
        
    }
    int calculateSalary()
    {
        int size1 = sizeof(Hours)/sizeof(Hours[0]);
        int Total = 0;
        for(int i = 0 ; i < size1 ; i++)
        {
            Total = Total + Hours[i];
        }


        int Monthly_Salary_1 = 0;

        if(type == 'v' || type == 'V')
        {
            int v_Lecturer = 2000 , v_Assisstant_Professor = 4000 , v_Associate_Professor = 7000 , v_Professor = 9000;
            Hours_Per_week = Total * 6;

            if(Designation == "Lecturer")
            {
               int Monthly_Salary_1 = v_Lecturer * Hours_Per_week;
            }
            if(Designation == "AssisstantProfessor")
            {
                int Monthly_Salary_1 = v_Assisstant_Professor * Hours_Per_week;
            }
            if(Designation == "AssociateProfessor")
            {
                int Monthly_Salary_1 = v_Associate_Professor * Hours_Per_week;
                cout<<Monthly_Salary_1;
            }
            if(Designation == "Professor")
            {
               int Monthly_Salary_1 = v_Professor *Hours_Per_week;
            }

            Monthly_Salary = Monthly_Salary_1 + ( Monthly_Salary_1 * (Experence*5)/100);

            if(Publications != 0)
            {
                Monthly_Salary = Monthly_Salary + (Publications * 8000);
            }
            return Monthly_Salary;
        }

        if(type == 'P' || type == 'p')
        {
            int p_Lecturer = 100000 , p_Assisstant_Professor = 175000 , p_Associate_Professor = 250000 , p_Professor = 325000;
           
            if(Designation == "Lecturer")
            {
               int Monthly_Salary_1 = p_Lecturer;
            }
            if(Designation == "Assisstant Professor")
            {
                int Monthly_Salary_1 = p_Assisstant_Professor;
            }
            if(Designation == "AssociateProfessor")
            {
                int Monthly_Salary_1 = p_Associate_Professor;
                
            }
            if(Designation == "Professor")
            {
               int Monthly_Salary_1 = p_Professor;
            }
            Monthly_Salary = Monthly_Salary_1 + ( Monthly_Salary_1 * (Experence * 5)/100);

         
            if(Publications != 0)
            {
            Monthly_Salary = Monthly_Salary + (Publications * 8000);
            }
           
        }
        return Monthly_Salary;
    }
    void Update_Record()
    {
        cout<<"welcome to the Updating Section:\n press 1 to update Qualifications \n press 2 to update contact\n press 3 to update institution \n";
        cout<<"enter your choice";
        int choice;
        cin>>choice;
        
        if(choice == 1)
        {
            cout<<"the current qualification is : "<<Qualification;
            cout<<"enter the updated qualification : ";
            string x;
            cin>>x;
            set_qualification(x);
        }
        if(choice == 2)
        {
            cout<<"the current contact in formation  is : "<<Contact_Info;
            cout<<"enter the updated contact information : ";
            string y;
            cin>>y;
            set_Contect_Info(y);
        }
        if(choice == 3)
        {
            cout<<"the current institution name  is : "<<Institution;
            cout<<"enter the updated Institution name  : ";
            string z;
            cin>>z;
            set_Institution(z);
        }
    }
    void show_data()
    {
      
        Getter();
        float x = calculateSalary();
        cout<<"Monthly salary : "<<x;
        
    }
    
    
};
void Split(string s)
{
    int i=0;
    cout<<s<<endl;
    std::string word;
    string *str;
    str =new string[30];
    for ( std::istringstream is( s ); is >> word; )
    {
        str[i] = word;
        i++;
    }
    
}
char string_TO_char(string str)
{
    char a[10] ={0};
    string sample;
    sample = str;
    strcpy(a, sample.c_str());
    char b;
    b = a[0];
    return b;
}
int *convertStrtoArr(string str)
{
    int *arr;
    arr =new int [10];
    int j = 0, i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            continue;
        if (str[i] == ','){
            j++;
        }
        else {
            arr[j] = (arr[j]*10) + (str[i] - 48);
        }
    }
    
    return arr;
}
int main()
{
    Teacher *T = nullptr;
    cout<<"Enter the size of array with range >=5 : ";
    int size;
    cin>>size;
    if(size>=5)
    {
        T = new Teacher [size];
    }
    else
    {
        for(;size<5; )
        {
            cout<<"invalid input"<<endl;
            cout<<"Enter the size again";
            cin>>size;
        }
    }
    
    // File Handling
    ifstream indata;
    indata.open("/Users/ahma-gill/Desktop/synonym.txt");
    string str1;
    int i=0;
    for(int j=0;j<size;j++)
    {
       
            getline(indata,str1);
   //     cout<<str1;
      
    std::string word;
    string *str;
    str =new string[30];
        int i=0;
    for (std::istringstream is( str1 ); is >> word; )
    {
        str[i] = word;
        i++;
    }
    char a;
    a = string_TO_char(str[6]);
    T[j].set_Name(str[0]);
    T[j].set_Adress(str[1]);
    T[j].set_Contect_Info(str[2]);
    T[j].set_Mail_ID(str[3]);
    T[j].set_Institution(str[4]);
    T[j].set_Department(str[5]);
    T[j].set_Type(a);
    T[j].set_Designation(str[7]);
    T[j].set_cources(str[8]);
    T[j].set_qualification(str[10]);
    int*arr = convertStrtoArr(str[9]);
    T[j].Get_Hours(arr);
    int *c = convertStrtoArr(str[11]);
    int *b = convertStrtoArr(str[12]);
    T[j].set_Experience(c);
    T[j].set_Publication(b);
        int x;
        cout<<"=======the record of========"<<j+1<<"=========== teacher is given below==============\n";
        T[j].show_data();
       
        cout<<"\npress 1 to update  records : ";
        cin>>x;
        if(x==1)
        {
            T[j].Update_Record();
            cout<<"the updated record is given as:\n";
    T[j].show_data();
            cout<<"\n====================================================\n";
        }
  
        cout<<"\n=======================================================\n";
        cout<<"the data of nsext teacheer is :\n";
    }
    return 0;
}
