#include<iostream>
#include <math.h>
using namespace std;

class Area {
public:
	double height;
	double width;
};

class Rectangle: public Area{
public:
	void seto(double a, double b);
	double area();
};

class Isosceles: public Area{
public:
	void seto(double c, double h);
	double area();		
};

class Cylinder: public Area{
public:
	void seto(double d, double h);
	double area();	
};

void Rectangle::seto(double a, double b){
	height = a;
	width = b;
}

double Rectangle::area(){
	double S;
	S = height*width;
	return S;
}

void Isosceles::seto(double c, double h){
	height = h;
	width = c;
}

double Isosceles::area(){
	double S;
	S = height*width*0.5;
	return S;
}

void Cylinder::seto(double r, double h){
	height = h;
	width = r;
}

double Cylinder::area(){
	double S;
	S = 2*M_PI*(width)*(width+height);
	return S;
}

int main(){
	Rectangle rect;    
	Isosceles is;
	Cylinder cyl;
	double a,b,c,h1,r,h2;

	cout<<"Введите стороны прямоугольника\n";
	cin>>a>>b;
	rect.seto(a, b);
	cout<<"Площадь "<<rect.area()<<"\n";
	cout<<"Введите основу и высоту треугольника\n";
	cin>>c>>h1;
	is.seto(c, h1);
	cout<<"Площадь "<<is.area()<<"\n";
	cout<<"Введите диаметр и высоту цилиндра\n";
	cin>>r>>h2;
	cyl.seto(r, h2);
	cout<<"Площадь "<<cyl.area()<<"\n";
	return 0;
}