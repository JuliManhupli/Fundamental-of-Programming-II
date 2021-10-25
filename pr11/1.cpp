#include<iostream>
using namespace std;
template <class X> X min(X& a, X& b) {
	if (a < b)
		return a;
	else
		return b;
}

int main() {
	cout << min(3, 4) << endl;
	cout << min('c', 'a') << endl;
	return 0;
}
