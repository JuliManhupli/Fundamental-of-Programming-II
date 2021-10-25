#include <iostream>
using namespace std;

inline int abs1(int n){
	cout<<"In integer abs ()\n";
	return n<0 ? -n : n;
}

inline long abs1(long n){
	cout<<"In long abs()\n";
	return n<0 ? -n : n;
}

inline double abs1(double n){
	cout<<"In double abs()\n";
	return n<0 ? -n : n;
}

int main(){
	cout<<"Absolute value of -10:"<< abs1(-10)<<"\n";
	cout<<"Absolute value of -10L:"<<abs1(-10L)<<"\n";
	cout<<"Absolute value of -10.01:"<<abs1(-10.01)<<"\n";
	return 0;
}
