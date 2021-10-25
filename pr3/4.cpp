#include<iostream>
using namespace std;

inline long int recursion_test(long int f){
	if (f == 1 || f == 0){
		return 1;
	}
	return f * recursion_test(f - 1);
}

inline int static_test(int a){
	static int i = 2;
	a = a*i;
	return a;
}

inline int cycle_test(int a){
	while(a<100){
		a=a+6;
	}
	return a;
}

inline int switch_test(int a){
	switch(a){
		case 1:{
			return 1;				
		}
		case 2:{
			return 2;
		}
		default:
			return a;			
	}
}

int main(){
	cout <<"Рекурсивная функция: "<< recursion_test(5) << endl;
	cout <<"Функция с статической переменной: "<< static_test(5) << endl;
	cout <<"Функция, которая содержит цикл: "<<cycle_test(5) <<endl;
	cout <<"Функция, которая содержит switch: "<<switch_test(5) <<endl;
	return 0;
}