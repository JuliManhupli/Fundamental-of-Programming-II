#include<iostream>
using namespace std;
class coord {
	int x, y;
public:
	coord() { x = 0; y = 0; }
	coord(int i, int j) { x = i; y = j; }
	void get_xy(int& i, int& j) { i = x; j = y; }
	friend coord operator ++(coord &obj1);
	friend coord operator ++(coord &obj1, int notused);
};

coord operator ++(coord &obj1) {
	coord temp;
	temp.x = obj1.x++;
	temp.y = obj1.y++;
	return temp;
}

coord operator ++(coord &obj1, int notused) {
	coord temp;
	temp.x = ++obj1.x;
	temp.y = ++obj1.y;
	return temp;
}

int main() {
	coord obj1(10, 10);
	int x, y;
	++obj1;
	obj1.get_xy(x, y);
	cout << "(++obj1) X: " << x << ", Y: " << y << "\n";
	obj1++;
	obj1.get_xy(x, y);
	cout << "(obj1++) X: " << x << ", Y: " << y << "\n";
	return 0;
}

