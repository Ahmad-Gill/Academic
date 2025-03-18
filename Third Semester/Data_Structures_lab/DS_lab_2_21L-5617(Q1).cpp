#include<iostream>
using namespace std;
class Shape
{
	
	float length;
	float width;

public:
	friend class rectangle;
	Shape()
	{
		length=0;
		width=0;
	}
void	Set_value(float l,float w)
	{
		length=l;
		width=w;
}
float get_lengh()
{
	return length;
}
float get_width()
{
	return width;
}
};
class rectangle 
{

	float area;
	float perimeter;
	Shape S;
public:
	//friend Shape ;
	rectangle()
	{
		area=0.0;
		perimeter =0.0;
	}

void set_values(float l,float w)
{
	S.Set_value(l,w);
}

void calulate_area()
{

	cout<<"the area of length  = "<<S.get_lengh()<<" and width = "<<S.get_width()<<"  is = "<<S.get_lengh()*S.get_width()<<endl;

}
void calculate_premeter()

{
	cout<<"the perimeter of length =  "<<S.get_lengh()<<" and width = "<<S.get_width()<<"  is = "<< 2*(S.get_lengh()+S.get_width())<<endl;
}



};

int main()




{




	float l,w;
	cout<<"enter the value of length : ";
	cin>>l;
	cout<<"enter the value of width : ";
	cin>>w;
	rectangle R;
	R.set_values(l,w);
	R.calulate_area();
	R.calculate_premeter();

	system("pause");
}