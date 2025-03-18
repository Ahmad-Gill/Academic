#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;
// PART_A
class Teacher
{
    private:
       string Name;
       string Address;
       string ContactInfo;
       string E_mail;
       string Institution;
       string Department;
       string Type;
       string Designation;
       int Experience;
       int Publications;
       string Qualifications;
       int Credit_hrs[30];
       int Monthly_Salary;
       string Allocated_Courses[30];
       int Credit_hrs_per_week;
       int calculateSalary;
       int onOfCources;
    public:
        Teacher()
        {
             Name = "" , Address = "" , ContactInfo = "" , E_mail = "" , Institution = "";
             Department = "" , Type = "" , Designation = "" , Allocated_Courses[10] = {} ;
             Credit_hrs[30] = {0} , Credit_hrs_per_week = 0 , Monthly_Salary = 0;
             Publications = 0 , Qualifications = "" , Experience = 0 , calculateSalary = 0;
        }
    // PART_B

    void SetName(string N)
    {
        Name = N;
    }
    void SetAddress(string A)
    {
        Address = A;
    }
    void SetContactInfo(string C)
    {
        ContactInfo = C;
    }
    void SetE_mail(string E)
    {
        E_mail = E;
    }
    void SetDepartment(string D)
    {
        Department = D;
    }
    void SetType(string T)
    {
        Type = T;
    }
    void SetDesignation(string DS)
    {
        Designation = DS;
    }
    void SetExperience(int EX)
    {
        Experience = EX;
    }
    void SetPublications(int P)
    {
        Publications = P;
    }
    void SetQualifications(string Q)
    {
        Qualifications = Q;
    }
    void SetMonthly_Salary(int M)
    {
        Monthly_Salary = M;
    }
    void SetInstitution(string I)
    {
        Institution = I;
    }
    void SetCredit_hrs_per_week(int W)
    {
        Credit_hrs_per_week = W;
    }
    void SetCredit_hrs(int CH[30],int onOfCources)
    {
        //Assignment each index of CH to each index of Credit_hrs
        for(int i=0;i<=onOfCources;i++){
            Credit_hrs[i] = CH[i];
        }
    }
    void SetAllocated_Courses(string AC[30],int onOfCources)
    {
        //Assignment each index of AC to each index of Allocated_Courses
        for(int i=0;i<=onOfCources;i++){
            Allocated_Courses[i] = AC[i];
        }
    }

    string GetName()
    {
        return Name;
    }
    string GetAddress()
    {
        return Address;
    }
    string GetContactInfo()
    {
        return ContactInfo;
    }
    string GetE_mail()
    {
        return E_mail;
    }
    string GetInstitution()
    {
        return Institution;
    }
    string GetDepartment()
    {
        return Department;
    }
    string GetType()
    {
        return Type;
    }
    string GetDesignation()
    {
        return Designation;
    }
    string* GetAllocated_Courses()
    {
        return Allocated_Courses;
    }
    int GetCredit_hrs_per_week()
    {
        return Credit_hrs_per_week;
    }
    int GetMonthly_Salary() const
    {
        return Monthly_Salary;
    }
    int GetExperience()
    {
        return Experience;
    }
    int GetPublications()
    {
        return Publications;
    }
    string GetQualifications()
    {
        return Qualifications;
    }

    // PART_C

    int SetcalculateSalary()
    {
        int size1 = sizeof(Credit_hrs)/sizeof(Credit_hrs[0]);
        int Total = 0;

        for(int i = 0 ; i < size1 ; i++)
        {
            Total = Total + Credit_hrs[i];
        }

        int count = 0;
        for(int i = 0 ; i < sizeof(Allocated_Courses)/sizeof(Allocated_Courses[0]) ; i++)
        {
            count = count + 1;
        }
        if( count < 3)
        {
            cout << "Less Number Of Courses";
        }

        int Monthly_Salary_1 = 0;

        if(Type == "visitor" || Type == "Visitor")
        {
            int v_Lecturer = 2000 , v_Assisstant_Professor = 4000 , v_Associate_Professor = 7000 , v_Professor = 9000;
            Credit_hrs_per_week = Total * 6;
            if(Designation == "Lecturer")
            {
               int Monthly_Salary_1 = v_Lecturer * Credit_hrs_per_week;
            }
            if(Designation == "Assisstant Professor")
            {
                int Monthly_Salary_1 = v_Assisstant_Professor * Credit_hrs_per_week;
            }
            if(Designation == "Associate Professor")
            {
                int Monthly_Salary_1 = v_Associate_Professor * Credit_hrs_per_week;
            }
            if(Designation == "Professor")
            {
               int Monthly_Salary_1 = v_Professor * Credit_hrs_per_week;
            }

            Monthly_Salary = Monthly_Salary_1 + ( Monthly_Salary_1 * (Experience*5)/100);

            if(Publications != 0)
            {
                int Salary_against_Publications;
                Salary_against_Publications = Monthly_Salary + (Publications * 8000);
                cout<<"Monthly Salary after Publications : "<<Salary_against_Publications;
            }
        }

        if (Type == "Permanent" || Type == "permanent")
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
            if(Designation == "Associate Professor")
            {
                int Monthly_Salary_1 = p_Associate_Professor;
            }
            if(Designation == "Professor")
            {
               int Monthly_Salary_1 = p_Professor;
            }

            Monthly_Salary = Monthly_Salary_1 + ( Monthly_Salary_1 * (Experience * 5)/100);

            if(Publications != 0)
            {
                int Salary_against_Publications;
                Salary_against_Publications = Monthly_Salary + (Publications * 8000);
                cout<<"Monthly Salary after Publications : "<<Salary_against_Publications;
            }
        }
        return Monthly_Salary;
    }

    // PART_D

    void UpdateRecord(string *Information)
    {
        int choice;
        cout<<"Enter 1 to update qualification"<<endl;
        cout<<"Enter 2 to update contact"<<endl;
        cout<<"Enter 3 to update institution"<<endl;
        cin>>choice;

        string Q , C , I;

        if(choice == 1)
        {
            cout << "Enter the new Qualification : ";
            cin >> Qualifications;
        }
        else if(choice == 2)
        {
            cout << "Enter the new Contact Info : ";
            cin >> ContactInfo;
        }
        else if(choice == 3)
        {
            cout << "Enter the name of new Institution : ";
            cin >> Institution;
        }
        else
        {
            cout << "Invalid Choice";
        }
    }
    // PART_E

    void showData()
    {
        cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"BASIC INFORMATION"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"NAME : "<<GetName()<<endl;
        cout<<"ADDRESS : "<<GetAddress()<<endl;
        cout<<"CONTACT INFO : "<<GetContactInfo()<<endl;
        cout<<"E-MAIL ADDRESS : "<<GetE_mail()<<endl;
        cout<<"INSTITUTION : "<<GetInstitution()<<endl;
        cout<<"DEPARTMENT : "<<GetDepartment()<<endl;
        cout<<"PERMENENT / VISITING : "<<GetType()<<endl;
        cout<<"DESIGNATION : "<<GetDesignation()<<endl;

        cout<<"Allocated Courses : ";
           int all_course_len = sizeof(Allocated_Courses)/sizeof(Allocated_Courses[0]);
         for(int i = 0 ; i < all_course_len ; i++)
         {
             cout << Allocated_Courses[i];
             if(!Allocated_Courses[i+1].empty()){
                 cout<<",";
            } else{
                break;
            }

         }

         cout<<endl<<"Credit Hours : ";
         int credit_hrs_len = sizeof(Credit_hrs)/sizeof(Credit_hrs[0]);

         for(int j = 0 ; j < credit_hrs_len ; j++)
         {

             cout << Credit_hrs[j];
             if(!Allocated_Courses[j+1].empty()){
                 cout<<",";
            } else{
                break;
            }

         }
        cout<<endl;
         cout<<"CREDIT HOURS PER WEEK : "<<GetCredit_hrs_per_week()<<endl;
         cout<<"MONTHLY SALARY : "<<GetMonthly_Salary()<<endl;
         cout<<"EXPERIENCE : "<<GetExperience()<<endl;
         cout<<"PUBLICATIONS : "<<GetPublications()<<endl;
         cout<<"QUALIFICATION : "<<GetQualifications()<<endl;

    }
};

// PART_F
int main()
{
    int N;
    int size = 13;
    cout<< "Enter the number of Teachers of which you want to access the information : ";
    cin >> N;


    while(N < 5) {
        cout << "Invalid Input" << endl;
        cout << "Enter the number again : ";
        cin >> N;
    }

    Teacher* T = new Teacher[N];

    fstream File;
    File.open("/Users/ahma-gill/Desktop/OOP.txt");

    string temp="";
    int num=0;

    string temCourses[30];
    int tempCreditHours[30];
    int x=0;
    for(int i = 0 ; i < N ; i++)
    {
        
            File >> temp;

            T[i].SetName(temp);
            File >> temp;
            T[i].SetAddress(temp);
            File >> temp;
            T[i].SetContactInfo(temp);
            File >> temp;
            T[i].SetE_mail(temp);
            File >> temp;
            T[i].SetInstitution(temp);
            File >> temp;
            T[i].SetDepartment(temp);
            File >> temp;
            T[i].SetType(temp);
            File >> temp;
            T[i].SetDesignation(temp);
            File >> temp;

             T[i].SetExperience(num);

             File >> num;
             T[i].SetPublications(num);

             File >> temp;
             T[i].SetQualifications(temp);

              T[i].SetcalculateSalary();
    }

     for(int i = 0 ; i < N ; i++){

         T[i].showData();
     }
    return 0;
}
