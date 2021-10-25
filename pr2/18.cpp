#include<iostream>
using namespace std;

class mybox{
	double volume;
public:
	mybox(double a, double b, double c);
	void show();
};

mybox::mybox(double a, double b, double c){
	volume = a*b*c;
}

void mybox::show(){
	cout<<"Об'єм паралелепіпеда = "<<volume;
}

int main(){
	double a,b,c;
	cout<<"Введіть сторони паралелепіпеда\n";
	cin>> a>> b>> c;
	mybox ob(a,b,c);
	ob.show();
	return 0;
}
