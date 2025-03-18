

//  main.cpp

//  Q_1

//

//  Created by Ahmad Gill on 18/04/2022.

//
#include <iostream>
#include <cmath>

using namespace std;

class VectorType

{

    double *x;

    double *y;

    double *z;

public:

   VectorType(double a=0.0,double b= 0.0,double c=0.0)

    {

        x=new double;

        y= new double;

        z= new double;
       *x = a;
       *y = b;
       *z = c;
    }
    friend istream & operator >>(istream &, VectorType & );
    friend ostream & operator <<(ostream &, VectorType & );
    friend void operator == (const VectorType & , const VectorType &);
    friend void operator !=(const VectorType &,const VectorType &);
    
    VectorType(VectorType&obj)

    {
        obj.x =this->x;

        obj.y = this->y;

        obj.z= this->z;
    }
    double operator*(VectorType & obj)

    {
        double W;
        W = ((*this->x)*(*(obj.x)))+((*this->y)*(*(obj.y)))+((*this->z)*(*(obj.z)));
        return W;
    }
    double Length()
    {
        double P;
        P=   sqrt((((*this->x)*(*this->x))+((*this->y)*(*this->y))+((*this->z)*(*this->z))));
        return P;
    }
    double Angle(double dot_product,double L_U,double L_V)
    {
        double x= L_V*L_U;
        double angle;
        angle =acos((dot_product/x));
        angle =  angle*(180/3.14);
        return angle;
    }
    VectorType operator+(VectorType & obj)
    {
        VectorType A;
        *A.x= (*this->x)+(*obj.x);
        *A.y= (*this->y)+(*obj.y);
        *A.z= (*this->z)+(*obj.z);
        
        return A;
    }
    VectorType operator-(VectorType & obj)
    {
        VectorType A;
        *A.x= (*this->x)-(*obj.x);
        *A.y= (*this->y)-(*obj.y);
        *A.z= (*this->z)-(*obj.z);
        
        return A;
    }
    void operator ++()
    {
      
        cout<<"("<<(*this->x)++<<" , "<<(*this->y)++<<" , "<<(*this->z)++<<" ) \n";
      
    }
    void operator ++(int)
    {
    
        cout<<"("<<++(*this->x)<<" , "<<++(*this->y)<<" , "<<++(*this->z)<<" ) \n";
       
    }
    void operator --()
    {
     
        cout<<"("<<(*this->x)--<<" , "<<(*this->y)--<<" , "<<(*this->z)--<<" ) \n";
       
    }
    void operator --(int)
    {
      
        cout<<"("<<--(*this->x)<<" , "<<--(*this->y)<<" , "<<--(*this->z)<<" ) \n";
    }
    double get_x()
    {
        return *this->x;
    }
    double get_y()
    {
        return *this->y;
    }
    double get_z()
    {
        return *this->z;

    }
    ~VectorType()
    {
    x=NULL;
    y=NULL;
    z=NULL;
    }
};
istream & operator >>(istream  & input,VectorType & obj )
{
    cout<<"enter the value of first integer : ";
    input>>*obj.x;
    cout<<"enter the value of second integer : ";
    input>>*obj.y;
    cout<<"enter the value of third integer : ";
    input>>*obj.z;
  
    return input;
}
ostream & operator <<(ostream  & output,VectorType & obj )
{
    output<<"("<<*obj.x<<" , "<<*obj.y<<" , "<<*obj.z<<" ) \n";
  
    return output;
}

void  operator ==(VectorType &obj,VectorType &obj1)

{
    
   
   if(((obj.get_x())==(obj1.get_x()))&&((obj.get_y())==(obj1.get_y()))&&((obj.get_z())==(obj1.get_z())))
       cout<<"the vectors are same :";
    else
        cout<<" the given vectors are not same ";
}

void   operator !=(VectorType &obj,VectorType obj1)
{
   
    if(((obj.get_x())!=(obj1.get_x()))&&((obj.get_y())!=(obj1.get_y()))&&((obj.get_z())!=(obj1.get_z())))
        cout<<" the given vectors are not same";
    else
        cout<<"  ";
    
}
int main() {
   
    VectorType U;
    VectorType V;
    cout<<"input of first vector : \n";
    cin>>U;
    cout<<"\ninput of second vector : \n";
    cin>>V;
    cout<<"output of first vector : ";
    cout<<U;
    cout<<"output of second vector : ";
    cout<<V;
 
    cout<<"equality test : = ";
    U==V;
    cout<<endl;
      VectorType W1;
    cout<<"the Dot product of two vectors : = ";
    double product;
    product = U*V;
    cout<<product;
    cout<<endl;
    double P = U.Length();
    double P1 = V.Length();
    cout<<"length of first vectore : = "<<P<<endl;
    cout<<"length of second vectore : = "<<P1<<endl;
    double Anglel;
    Anglel =    U.Angle(product, P, P1);
    cout<<"angle between these two vectors is : = ";
    cout<<Anglel<<endl;
    VectorType Plus;
    cout<<"the sum of two vectors : ";
    Plus =   U+V;
    cout<<"("<<  Plus.get_x()<<" , "<<Plus.get_y()<<" , "<<Plus.get_z()<<" ) \n";
    VectorType Minus;
    cout<<"the subtraction of two vectors : ";
    Minus = U-V;
    cout<<"("<<Minus.get_x()<<" , "<<Minus.get_y()<<" , "<<Minus.get_z()<<" ) \n";
    cout<<"=======for first vector======\n";
    cout<<"pre increment in first vector ";
    ++U;
    cout<<"post increment in first vector ";
    U++;
    cout<<"pre decrement  in first vector ";
    --U;
    cout<<"post decrement in first vector ";
    U--;
    cout<<"=======for second vectoe=======\n";
    cout<<"pre increment in first vector ";
    ++V;
    cout<<"post increment in first vector ";
    V++;
    cout<<"pre decrement  in first vector ";
    --V;
    cout<<"post decrement in first vector ";
    V--;
  
  
    return 0;
    

}
