#include<iostream>
using namespace std;

int main() {
	float* f = new float;
	long* l = new long;
	char* c = new char;

	*f = 20.21;
	*l = 10L;
	*c = 'r';

	cout << "Float: " << *f << endl;
	cout << "Long: " << *l << endl;
	cout << "Char: " << *c << endl;

	delete f;
	delete l;
	delete c;
	return 0;
}