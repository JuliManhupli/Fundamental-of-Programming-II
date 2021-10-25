#include<iostream>
using namespace std;
class coord {
	int x, y;
public:
	coord() { x = 0; y = 0; }
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int& i, int& j) { i = x; j = y; }
	friend coord operator *(const coord obj1, int i);
	friend coord operator *(int i, const coord obj2);
};

coord operator *(coord obj1, int i) {
	coord temp;
	temp.x = obj1.x * i;
	temp.y = obj1.y * i;
	return temp;
}

coord operator *(int i, const coord obj2) {
	coord temp;
	temp.x = obj2.x * i;
	temp.y = obj2.y * i;
	return temp;
}

int main() {
	coord obj1(10, 10), obj2;
	int x, y;
	obj2 = obj1 * 2;
	obj2.get_xy(x, y);
	cout << "(obj*2) X: " << x << ", Y: " << y << "\n";
	obj2 = 3 * obj1;
	obj2.get_xy(x, y);
	cout << "(3*obj) X: " << x << ", Y: " << y << "\n";
	return 0;
}
