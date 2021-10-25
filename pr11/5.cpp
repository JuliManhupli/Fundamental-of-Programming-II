#include<iostream>
using namespace std;
double divide(double a, double b){
	try{
		if(b == 0)
			throw(b);
	}
	catch(double b){
		cout<< "Ошибка! Деление на ноль" <<endl;
		exit(1);
	}
	return a/b;
}

int main(){
	cout << "6/2 = " << divide(6, 2) << endl;
	cout << "3/0 = " << divide(3, 0) << endl;
	return 0;
}
