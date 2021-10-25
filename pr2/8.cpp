#include<iostream>
#include<cmath>
using namespace std;


int myroot(int n);
long myroot(long n);
double myroot(double n);

int main(){
	cout<<"Квадратний корінь з 16: "<< myroot(16) << "\n";
	cout<<"Квадратний корінь з 16L: "<< myroot(16L) << "\n";
	cout<<"Квадратний корінь з 16.01: "<< myroot(16.01) << "\n";
	return 0;
}

int myroot(int n){
	cout<<"integer sqrt()\n";
	return (int) sqrt((double)n);
}

long myroot(long n){
	cout<<"long sqrt()\n";
	return (long) sqrt((double)n);
}

double myroot(double n){
	cout<<"double sqrt()\n";
	return sqrt(n);
}
