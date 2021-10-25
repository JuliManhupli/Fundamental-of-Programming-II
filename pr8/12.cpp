#include<iostream>
using namespace std;
class number {
	int num;
	int divider;
public:
	void set(int n);
	friend ostream &operator <<(ostream &stream, number obj);
	friend istream &operator >>(istream &stream, number &obj); 
};

void number::set (int n){
	int d=2;
	num = n;
	while (num % d!= 0){ 
		d++;
	}
	divider = d;
}

ostream &operator <<(ostream &stream, number obj) {
	cout << "Число: ";
	stream << obj.num << "\n";
	cout << "Наименьший делитель: ";
	stream << obj.divider << "\n";	
	return stream; 
}

istream &operator >>(istream &stream, number &obj) {
	int n;
	cout << "Введите число ";
	stream >> n;
	obj.set(n);
	return stream;
}

int main(){
	number obj;
	cin >> obj;
	cout << obj;
	return 0;
}