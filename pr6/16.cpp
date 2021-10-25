#include<iostream>
using namespace std;
class three_d {
	int x, y, z;
public:
	three_d(int i, int j, int k) { x = i; y = j; z = k; }
	three_d() { x = 0; y = 0; z = 0; }
	void get(int& i, int& j, int& k) { i = x; j = y; k = z; }
	three_d operator +(const three_d obj);
	three_d operator -(const three_d obj);
	three_d operator ++();
	three_d operator --();

};

three_d three_d::operator +(const three_d obj) {
	three_d tmp;
	tmp.x = x + obj.x;
	tmp.y = y + obj.y;
	tmp.z = z + obj.z;
	return tmp;
}

three_d three_d::operator -(const three_d obj) {
	three_d tmp;
	tmp.x = x - obj.x;
	tmp.y = y - obj.y;
	tmp.z = z - obj.z;
	return tmp;
}

three_d three_d::operator ++() {
	x++;
	y++;
	z++;
	return *this;
}

three_d three_d::operator --() {
	x--;
	y--;
	z--;
	return *this;
}

int main() {
	three_d obj1(10, 10, 10), obj2(5, 3, 2), obj3;
	int x, y, z;
	obj3 = obj1 + obj2;
	obj3.get(x, y, z);
	cout << "(obj1+obj2) X: " << x << ", Y: " << y << ", Z: " << z << "\n";
	obj3 = obj1 - obj2;
	obj3.get(x, y, z);
	cout << "(obj1-obj2) X: " << x << ", Y: " << y << ", Z: " << z << "\n";
	++obj1;
	obj1.get(x, y, z);
	cout << "(++obj1) X: " << x << ", Y: " << y << ", Z: " << z << "\n";
	--obj2;
	obj2.get(x, y, z);
	cout << "(--obj2) X: " << x << ", Y: " << y << ", Z: " << z << "\n";
	return 0;
}
