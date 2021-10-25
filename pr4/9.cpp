#include<iostream>
using namespace std;

int main() {
	double *a;
	a = new double(-123.0987);
	cout << *a;
	delete a;
	return 0;
}