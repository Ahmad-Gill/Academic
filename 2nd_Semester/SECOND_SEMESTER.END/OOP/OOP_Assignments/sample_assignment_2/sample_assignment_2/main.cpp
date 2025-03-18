#include <iostream>
#include<cstring>
#include<fstream>
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
       char Type;
       string Designation;
       int Experience;
       int Publications;
       string Qualifications;
       int Credit_hrs[30];
       int Monthly_Salary;
       string Allocated_Courses;
       int Credit_hrs_per_week;
    public:
        Teacher()
        {
            Name = " " , Address = " " , ContactInfo = " " , E_mail = " " , Institution = " ";
            Department = " " , Type = '\0 ' , Designation = " " , Allocated_Courses = " " ;
            Credit_hrs[30] = {0} , Credit_hrs_per_week = 0 , Monthly_Salary = 0;
            Publications = 0 , Qualifications = " " , Experience = 0;
        }
    // PART_B

    SetName(string N)
    {
        Name = N;
    }
    SetAddress(string A)
    {
        Address = A;
    }
    SetContactInfo(string C)
    {
        ContactInfo = C;
    }
    SetE_mail(string E)
    {
        E_mail = E;
    }
    SetDepartment(string D)
    {
        Department = D;
    }
    SetType(char T)
    {
        Type = T;
    }
    SetDesignation(string DS)
    {
        Designation = DS;
    }
    SetExperience(int EX)
    {
        Experience = EX;
    }
    SetPublications(int P)
    {
        Publications = P;
    }
    SetQualifications(string Q)
    {
        Qualifications = Q;
    }
    SetMonthly_Salary(int M)
    {
        Monthly_Salary = M;
    }
    SetInstitution(string I)
    {
        Institution = I;
    }
    SetCredit_hrs_per_week(int W)
    {
        Credit_hrs_per_week = W;
    }
    SetCredit_hrs(int CH)
    {
        Credit_hrs[30] = CH;
    }
    SetAllocated_Courses(string AC)
    {
        Allocated_Courses[30] = AC[30];
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
    char GetType()
    {
        return Type;
    }
    string GetDesignation()
    {
        return Designation;
    }
    string GetAllocated_Courses()
    {
        return Allocated_Courses;
    }
    int GetCredit_hrs_per_week()
    {
        return Credit_hrs_per_week;
    }
    int GetMonthly_Salary()
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

    int calculateSalary()
    {
        int size1 = sizeof(Credit_hrs);
        int Total = 0;

            for(int i = 0 ; i < size1 ; i++)
            {
                Total = Total + Credit_hrs[i];
            }

        int count = 0;
        for(int i = 0 ; i < sizeof(Allocated_Courses) ; i++)
        {
            count = count + 1;
        }
        if( count < 3)
        {
            cout << "Less Number Of Courses";
        }
        int Monthly_Salary_1 = 0;
        if(Type == 'v' || Type == 'V')
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

        if (Type == 'P' || Type == 'p')
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

    void UpdateRecord()
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
          //  T[i].SetQualifications(Information[j][k])
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
        for(int i = 0 ; i < sizeof(Allocated_Courses) ; i++)
        {
            cout << Allocated_Courses[i] << " , ";
        }
        cout<<"Credit Hours : ";
        for(int j = 0 ; j < sizeof(Credit_hrs) ; j++)
        {
            cout << Credit_hrs[j] << " , ";
        }
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
     cout<< "Enter the number of Teachers of which you want to access the information : ";
     cin >> N;
     if(N < 5)
     {
         cout << "Invalid Input"<<endl;
         cout << "Enter the number again : ";
         cin >> N;
     }
     Teacher T[N];
     int Total_Lines = 0;
     ifstream input("OOP");
     int Number = 0;
     string **Information;
     Information = new string*[N];
     for(int i = 0 ; i < N ; i++)
     {
         Information[i] = new string [Number];
         Number++;
         if(Number > 5)
         {
             i = Total_Lines;
         }
     }
     for(int i = o ; i < Total_Lines ; i++)
     {
         for(int j = 0 ; j < Number ; j++)
         {

         }
     }
     int i = 0;
         for(int j = 0 ; j < Number ; j++)
         {
           for(int k = 0 ; k < Totsl_Lines ; k++)
           {
             T[i].SetName(Information[j][k]);
             T[i].SetAddress(Information[j][k]);
             T[i].SetContactInfo(Information[j][k]);
             T[i].SetE_mail(Information[j][k]);
             T[i].SetInstituion(Information[j][k]);
             T[i].SetDepartment(Information[j][k]);
             T[i].SetType(Information[j][k]);
             T[i].SetDesignation(Information[j][k]);
             T[i].SetAllocated_Courses(Information[j][k]);
             T[i].SetCredit_hrs(Information[j][k]);
             T[i].SetExperience(Information[j][k]);
             T[i].SetPublications(Information[j][k]);
             T[i].Qualifications(Information[j][k]);
             T[i].calculateSalary(Information[j][k]);
           UpdateRecord(T[] , Information);
       }
       T[i].showData();
       input >> calculateSalary();
     }
         i++;
     }
     return 0;
     }
