#include<iostream>
using namespace std;
template <class X> X abs(X n) {
	return n < 0 ? -n : n;
}

int main() {
	cout << "Absolute value of -10: " << abs(-10) << "\n";
	cout << "Absolute value of -10L: " << abs(-10L) << "\n";
	cout << "Absolute value of -10.01: " << abs(-10.01) << "\n";
	return 0;
}