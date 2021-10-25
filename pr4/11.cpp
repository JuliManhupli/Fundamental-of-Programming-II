#include<iostream>
using namespace std;

void neg1(int &p);
void neg2(int *p);

int main(){
	int a = 1;
	int b = 2;

	neg1(a);
	neg2(&b);

	cout<<"Используя параметр указатель: "<<a<<endl;
	cout<<"Используя параметр-ссылку: "<<b<<endl;
	return 0;
}

void neg1(int &p){
	p = -p;
}

void neg2(int *p){
	*p = -*p;
}