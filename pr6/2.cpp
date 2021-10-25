#include<iostream>
using namespace std;
class coord {
	int x, y;
public:
	coord() { x = 0; y = 0; };
	coord(int i, int j) { x = i; y = j; };
	void get_xy(int &i, int &j) { i = x, j = y; }
	coord operator %(const coord obj);
};

coord coord::operator %(const coord obj) {
	double i;
	cout << "Enter a number: ";
	cin >> i;
	cout << "root of " << i << " is ";
	cout << sqrt(i);
}

int main() {
	coord obj1(10, 10), obj2(5, 3), obj3;
	int x, y;
	obj3 = obj1 % obj2;
	obj3.get_xy(x, y);
	cout << "X: " << x << ", Y: " << y << "\n";
	return 0;
}
