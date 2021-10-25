#include<iostream>
using namespace std;

int main() {
	cout.width(20);
	cout.setf(ios::left);
	cout.precision(6);
	cout.fill('*');
	cout << 1000.5354 << '\n';
	return 0;
}