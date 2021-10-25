#include<iostream>
#include<cstdlib>
using namespace std;

int atoi(char *s);
double atoi(char *s);
float atoi(char *s);

int main(){
	char arr[256];
	cout<<"Введіть рядок\n";
	cin>>arr;
	int a = atoi(arr);
	double b = atoi(arr);
	float c = atoi(arr);
	cout<<a<<"  "<<b<<" "<<c;
	return 0;
}