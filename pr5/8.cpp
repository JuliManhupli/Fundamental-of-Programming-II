#include<iostream>
using namespace std;

int dif(int a, int b){
	return a - b;
}

float dif(float a, float b){
	return a - b;
}

int main(){
	int (*fp1) (int, int);
	float (*fp2) (float, float);

	cout<<"Адресс первой функции: "<<&fp1<<endl;
	fp1 = dif;
	cout<<"Использывание адресса первой функции: "<<fp1(5, 1)<<endl;

	cout<<"Адресс второй функции: "<<&fp2<<endl;
	fp2 = dif;
	cout<<"Использывание адресса второй функции: "<<fp2(5.99, 1.99)<<endl;
	return 0;
}
