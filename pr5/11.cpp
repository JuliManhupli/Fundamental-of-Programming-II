#include<iostream>
using namespace std;

void order(int &x, int &y) {
	if (y < x) {
		int t;
		t = x;
		x = y;
		y = t;
	}
}


int main() {
	int x = 1, y = 0;
	cout << "x: " << x << " y: " << y << endl;
	order(x, y);
	cout << "After order: ";
	cout << "x: " << x << " y: " << y << endl;
	return 0;
}
