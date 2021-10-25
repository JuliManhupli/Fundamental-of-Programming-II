#include<iostream>
using namespace std;

char min(char a, char b);
int min(int a, int b);
double min(double a, double b);

int main(){
	cout<<"Найменше з 'f' і 'e': "<< min('f','e')<<"\n";
	cout<<"Найменше з 3 і 8: "<< min(3,8)<<"\n";
	cout<<"Найменше з 5.124 і 1.535: "<< min(5.124, 1.535)<<"\n";
	return 0;
}

char min(char a, char b){
	if (a>b) return b;
		else return a;
}

int min(int a, int b){
	if (a>b) return b;
		else return a;
}

double min(double a, double b){
	if (a>b) return b;
		else return a;
}
