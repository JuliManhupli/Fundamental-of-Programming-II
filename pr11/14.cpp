#include<iostream>
using namespace std;
#define SIZE 10
template <class T> class arraytype {
	T array[SIZE];
public:
	arraytype(){ }
	T &operator [](int i);
};

template <class T> T &arraytype<T>::operator [](int i){
	if(i<0 || i>SIZE-1){
		cout<<"Bounds error!\n";
		cout<<"Index value of "<< i <<" is out of bounds.\n";
		exit(1);
	}
	return array[i];
}

int main(){
	arraytype <int> obj1;
	arraytype <double> obj2;
	arraytype <char> obj3;
	char a = 'a';
	for (int i = 0; i < SIZE; i++){
		obj1[i] = i;
	}
	for (int i = 0; i < SIZE; i++){
		cout << obj1[i] <<' ';
	}	
	cout << endl;

	for (int i = 0; i < SIZE; i++){
		obj2[i] = i *1.1;
	}
	for (int i = 0; i < SIZE; i++){
		cout << obj2[i] <<' ';
	}	
	cout << endl;

	for (int i = 0; i < SIZE; i++){
		obj3[i] = a;
		a++;
	}
	for (int i = 0; i < SIZE; i++){
		cout << obj3[i] <<' ';
	}	
	cout << endl;

	obj1[SIZE+100] = 99;
	cout << obj1[SIZE+100];
	return 0;
}
