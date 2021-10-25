#include<iostream>
#include<cmath>
using namespace std;
int main() {
	double x;
	cout.precision(5);
	cout << "     x         lgx         lnx" << endl;
	for (x = 2.0; x < 101.0; x++) {
		cout.width(10);
		cout << x << " ";
		cout.width(10);
		cout << log(x) << " ";
		cout.width(10);
		cout << log10(x) << endl;
	}
	return 0;
}