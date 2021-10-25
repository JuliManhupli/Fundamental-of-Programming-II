#include<iostream>
using namespace std;
#define SIZE 10
class arraytype {
	int array[SIZE];
public:
	arraytype(){ }
	int &operator [](int i);
};

int &arraytype::operator [](int i){
	if(i<0 || i>SIZE-1){
		cout<<"Bounds error!\n";
		cout<<"Index value of "<< i <<" is out of bounds.\n";
		exit(1);
	}
	return array[i];
}

int main(){
	arraytype obj;
	for (int i = 0; i < SIZE; i++){
		obj[i] = i;
	}
	for (int i = 0; i < SIZE; i++){
		cout << obj[i] <<' ';
	}	
	cout << endl;
	obj[SIZE+100] = 99;
	cout << obj[SIZE+100];
	return 0;
}
