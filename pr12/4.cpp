#include<iostream>
using namespace std;
void f(const double* i) {
	double* v;
	v = const_cast <double*> (i);
	*v = 100.0;
}

int main() {
	double x = 98.6;
	cout << x << endl;
	f(&x);
	cout << x << endl;
}