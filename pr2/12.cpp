#include<iostream>
using namespace std;

int degree(int a, int b);

int main(){
	int a, b;
	cout<<"Введіть перше число\n";
	cin>>a;
	cout<<"Введіть друге число\n";
	cin>>b;
	cout<<"Результат: "<<degree(a,b);
	return 0;
}

int degree(int a, int b){
	int c;
	c=a;
	for (int i=b; i>1; i--){
		a*=c;
	}
	return a;
}