//6.11

#include<iostream>
using namespace std;
float f(float t){
	return t / 2.0;
}
double f(double t){
	return t / 3.0;
}
int main(){
	float x = 10.09;
	cout<<f(x);
	double y = 10.09;
	cout<< f(y);
	cout<< f(10);
	return 0;
}
