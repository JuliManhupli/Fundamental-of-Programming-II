#include<iostream>
using namespace std;

class coord {
	float x, y;
public:
	coord() { x = 0; y = 0; };
	coord(float i, float j) { x = i; y = j; };
	void get_xy(float& i, float& j) { i = x, j = y; }
	coord operator +(const coord obj);
	coord operator -(const coord obj);
	coord operator =(const coord obj);
	coord operator *(const coord obj);
	coord operator /(const coord obj);
};

coord coord::operator +(const coord obj) {
	coord temp;
	temp.x = x + obj.x;
	temp.y = y + obj.y;
	return temp;
}

coord coord::operator -(const coord obj) {
	coord temp;
	temp.x = x - obj.x;
	temp.y = y - obj.y;
	return temp;
}

coord coord::operator =(const coord obj) {
	x = obj.x;
	y = obj.y;
	return *this;
}

coord coord::operator *(const coord obj) {
	coord temp;
	temp.x = x * obj.x;
	temp.y = y * obj.y;
	return temp;
}

coord coord::operator /(const coord obj) {
	coord temp;
	temp.x = x / obj.x;
	temp.y = y / obj.y;
	return temp;
}

int main() {
	coord obj1(10, 10), obj2(5, 3), obj3;
	float x, y;
	obj3 = obj1 + obj2;
	obj3.get_xy(x, y);
	cout << "(obj1+obj2) X: " << x << ", Y: " << y << "\n";
	obj3 = obj1 - obj2;
	obj3.get_xy(x, y);
	cout << "(obj1-obj2) X: " << x << ", Y: " << y << "\n";
	obj3 = obj1;
	obj3.get_xy(x, y);
	cout << "(obj3=obj1) X: " << x << ", Y: " << y << "\n";
	obj3 = obj1 * obj2;
	obj3.get_xy(x, y);
	cout << "(obj1*obj2) X: " << x << ", Y: " << y << "\n";
	obj3 = obj1 / obj2;
	obj3.get_xy(x, y);
	cout << "(obj1/obj2) X: " << x << ", Y: " << y << "\n";
	return 0;
}
