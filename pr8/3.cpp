#include<iostream>
using namespace std;
int main() {
	cout.setf(ios::scientific | ios::uppercase | ios::showpoint);
	cout << 4642.544 << endl;
	return 0;
}

/*scientific -  числа с плавающей запятой 
выводятся с использованием науч­ной нотации

uppercase - символы будут выводиться в верхнем регистре

showpoint - выводу десятичной запятой и нулей справа 
для всех чисел с плавающей запятой*/