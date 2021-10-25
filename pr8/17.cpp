#include<iostream>
using namespace std;
class pwr {
	int base;
	int exponent;
	double result;
public:
	pwr(int b, int e);
	friend ostream &operator <<(ostream &stream, pwr obj);
	friend istream &operator >>(istream &stream, pwr &obj);
};

pwr::pwr(int b, int e) {
	base = b;
	exponent = e;
	result = 1;
	for (; e; e--)
		result = result * base;
}

istream &operator >>(istream &stream, pwr &obj) {
	int base, ex;
	cout << "Введите число и степень: ";
	stream >> base >> ex;
	pwr ob(base, ex);
	obj = ob;
	return stream;
}

ostream &operator <<(ostream &stream, pwr obj) {
	stream << obj.base << "^" << obj.exponent << " = " << obj.result << endl;
	return stream;
}


int main() {
	pwr obj1(1, 1);
	cin >> obj1;
	cout << obj1;
	return 0;
}
