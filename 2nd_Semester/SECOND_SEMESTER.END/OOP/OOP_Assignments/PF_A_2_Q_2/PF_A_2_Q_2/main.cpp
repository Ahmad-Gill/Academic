#include <iostream>
using namespace std;
int Maximum_Absolute_Difference(int arr1[],int arr2[] ,int size1,int size2)
{
    int max_size=0;
    if(size1>size2)
        max_size =size1;
    else
        max_size = size2;
    int Maximum_Adsolute =0;
    int  Sample_Maximum_Adsolute =0;
    Maximum_Adsolute= arr1[0]-arr2[0];
    Sample_Maximum_Adsolute = arr1[1]-arr2[1];
    for (int i=2;i<=max_size;i+=2)
    {
   

        if(Maximum_Adsolute<0)
        {
            Maximum_Adsolute *=-1;
        }
        if(Sample_Maximum_Adsolute<0)
        {
            Sample_Maximum_Adsolute *=-1;
        }
        if(Maximum_Adsolute>Sample_Maximum_Adsolute)
       Maximum_Adsolute =Maximum_Adsolute;
        if(Maximum_Adsolute<Sample_Maximum_Adsolute)
             Maximum_Adsolute=Sample_Maximum_Adsolute;
        Sample_Maximum_Adsolute = arr1[i]-arr2[i];
    }
    return Maximum_Adsolute;
}
void  Rotate_Cyclic(int Arr[],int size,int K)
{
    int Sample_Arr[size+1];

    int No_Of_Rotations = size - K;
    while(No_Of_Rotations>0)
    {
    for(int i=0;i<size;i++)
    {
        Sample_Arr[0] = Arr[size-1];
        Sample_Arr[i+1]=Arr[i];
    }
    for(int i=0;i<size;i++)
        Arr[i]=Sample_Arr[i];
        No_Of_Rotations--;
    }
    for(int i=0;i<size;i++)
        cout<<Arr[i]<<",";
    cout<<endl;
   

}
void Rotate_ACyclic(int Arr[],int size,int K)
{
    int Sample_Arr[size];

    int No_Of_Rotations = size - K;
    while(No_Of_Rotations>0)
    {
    for(int i=0;i<size;i++)
        Sample_Arr[i]=Arr[i+1];
        Sample_Arr[size-1] = Arr[0];
    for(int i=0;i<size;i++)
        Arr[i]=Sample_Arr[i];
        No_Of_Rotations--;
    }
    for(int i=0;i<size;i++)
        cout<<Arr[i]<<",";
    cout<<endl;
}
int main() {
    int Arr1_size=0,Arr2_size=0;
   


    cout<<"enter the size of first array : ";
    cin>>Arr1_size;
    while(Arr1_size<5)
    {
        cout<<"invalid Input . enter the size again : ";
        cin>>Arr1_size;
    }
    int Sample_Array1[Arr1_size];
    int Sample_Arr1_1[Arr1_size];
    int Arr1[Arr1_size];
    for (int i=0; i<Arr1_size; i++) {
        cout<<"enter the "<<i+1<<" element of array : ";
        cin>>Arr1[i];
    }
    cout<<endl;
    cout<<"enter the size of second  array : ";
    cin>>Arr2_size;
    while(Arr2_size<5)
    {
        cout<<"invalid Input . enter the size again : ";
        cin>>Arr2_size;
    }
    int Sample_Arr2[Arr2_size];
    int Sample_Arr2_2[Arr2_size];
    int Arr2[Arr2_size];
    for (int i=0; i<Arr2_size; i++) {
        cout<<"enter the "<<i+1<<" element of array : ";
        cin>>Arr2[i];
    }
    for(int i=0;i<Arr1_size;i++)
    {
        Sample_Array1[i]=Arr1[i];
        Sample_Arr1_1[i]=Arr1[i];
    }
    for(int i=0;i<Arr1_size;i++)
    {
        Sample_Arr2[i]=Arr2[i];
        Sample_Arr2_2[i]=Arr2[i];
    }
    int Roration_Factor_For_Cyclik=0;
    int Rotation_Factor_For_Acyclik=0;
    cout<<"enter the rotaion factor for cylic : ";
    cin>>Roration_Factor_For_Cyclik;
    while(Roration_Factor_For_Cyclik<0 || Roration_Factor_For_Cyclik>Arr1_size)
    {
        cout<<"invalid input . Enter the Rotation factor again : ";
    cin>>Roration_Factor_For_Cyclik;
}
    cout<<"enter the rotation factor for AcyClic : ";
    cin>>Rotation_Factor_For_Acyclik;
    while(Rotation_Factor_For_Acyclik<0||Rotation_Factor_For_Acyclik>Arr2_size)
    {
        cout<<"invalid input . Enter the Rotation factor again : ";
        cin>>Rotation_Factor_For_Acyclik;
}
   

    cout<<"==========OUTPUT OF FIRST ARRAY=================\n";
    for (int i=0; i<Arr1_size; i++) {
        cout<<Arr1[i]<<",";
    }
    cout<<"\n==========OUTPUT OF SECOND ARRAY=================\n";
    for (int i=0; i<Arr1_size; i++) {
        cout<<Arr2[i]<<",";
    }
    cout<<endl;
    cout<<"\n======= CYLIC_ROTATIONS of Arr1 BY SIZE-3===========\n ";
    Rotate_Cyclic(Sample_Array1, Arr1_size,Roration_Factor_For_Cyclik);
    cout<<"\n======= CYLIC_ROTATIONS of Arr2 BY SIZE-3===========\n ";
    Rotate_Cyclic(Sample_Arr2, Arr2_size, Roration_Factor_For_Cyclik);
    cout<<"\n=======NO OF ACYLIC_ROTATIONS BY SIZE-4===========\n ";
    Rotate_ACyclic(Sample_Arr1_1, Arr1_size, Rotation_Factor_For_Acyclik);
    cout<<"\n======= ACYLIC_ROTATIONS of Arr2 BY SIZE-4===========\n ";
    Rotate_ACyclic(Sample_Arr2_2, Arr2_size, Rotation_Factor_For_Acyclik);
    cout<<"\n=============MAXIMUM ABSOLUTE DIFFERENCE OF Simple Arrays===============\n ";
    int First_Maximum_Absolute_Difference =0;
    int Second_Maximum_Absolute_Difference =0;
    int Third_Maximum_Absolute_Difference =0;
    int Fourth_Maximum_Absolute_Difference =0;
    First_Maximum_Absolute_Difference =Maximum_Absolute_Difference(Arr1,Arr2, Arr1_size,Arr2_size);
    Second_Maximum_Absolute_Difference = Maximum_Absolute_Difference(Sample_Array1, Sample_Arr2, Arr1_size,Arr2_size);
    Third_Maximum_Absolute_Difference =Maximum_Absolute_Difference(Arr1,Sample_Arr2_2, Arr2_size,Arr2_size);
    Fourth_Maximum_Absolute_Difference = Maximum_Absolute_Difference(Sample_Array1, Sample_Arr2_2, Arr1_size,Arr2_size);
    cout<<"\n First Difference : = "<<First_Maximum_Absolute_Difference;
    cout<<"\n Second Difference : = "<<Second_Maximum_Absolute_Difference;
    cout<<"\n Third Difference : = "<<Third_Maximum_Absolute_Difference;
    cout<<"\n Fourth Difference : = "<<Fourth_Maximum_Absolute_Difference;
    int max=0;
   
        if(First_Maximum_Absolute_Difference>=Second_Maximum_Absolute_Difference)
            max = First_Maximum_Absolute_Difference;
       
        if(First_Maximum_Absolute_Difference<Second_Maximum_Absolute_Difference)
            max = Second_Maximum_Absolute_Difference;
         
        if(max>=Third_Maximum_Absolute_Difference)
            max = max;
       
        if(max<Third_Maximum_Absolute_Difference)
            max =Third_Maximum_Absolute_Difference;
         
        if(max>=Fourth_Maximum_Absolute_Difference)
            max =max;
           
        if(max<Fourth_Maximum_Absolute_Difference)
            max =Fourth_Maximum_Absolute_Difference;
           
    cout<<"\nMaximum_Absolute_Difference : = "<<max<<endl;
   

    cout<<"========CHECKING DIFFERENCE IN ARRAYS ================\n";
    cout<<"\n=============FOR FIRST ARRAY===========================\n";
    for (int i=0; i<Arr1_size; i++) {
        if(Arr1[i]==max)
            cout<<"the maximum value "<<max<<" exist in first simple array \n ";
        if(Sample_Array1[i]==max)
            cout<<"the maximum value "<<max<<" exist in first  CYLCIC array \n ";
        if(Sample_Arr1_1[i]==max)
            cout<<"the maximum value "<<max<<" exist in first ACYCLIC array \n ";
    }
        cout<<"\n=============FOR SECOND ARRAY===========================\n";
        for(int i=0;i<Arr2_size;i++)
        {
        if(Arr2[i]==max)
            cout<<"the maximum value "<<max<<" exist in Second  simple array \n ";
        if(Sample_Arr1_1[i]==max)
            cout<<"the maximum value "<<max<<" exist in Second   CYCLIC array \n ";
        if(Sample_Arr2_2[i]==max)
            cout<<"the maximum value "<<max<<" exist in Second ACYCLIC array \n ";
       

       

    }
                                                         

    return 0;
}
