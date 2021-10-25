#include<iostream>
using namespace std;
class three_d {
	int x, y, z;
public:
	three_d(int i, int j, int k) { x = i; y = j; z = k; }
	three_d() { x = 0; y = 0; z = 0; }
	void get(int& i, int& j, int& k) { i = x; j = y; k = z; }
	three_d operator +(const three_d &obj);
	three_d operator -(const three_d &obj);
	friend three_d operator ++(three_d &obj);
	friend three_d operator --(three_d &obj);
	int operator ==(const three_d &obj);
	int operator !=(const three_d &obj);
	int operator ||(const three_d &obj);
	friend three_d operator +(const three_d &obj, int i);
	friend three_d operator +(int i, const three_d &obj);
};

three_d three_d::operator +(const three_d &obj) {
	three_d temp;
	temp.x = x + obj.x;
	temp.y = y + obj.y;
	temp.z = z + obj.z;
	return temp;
}

three_d three_d::operator -(const three_d &obj) {
	three_d temp;
	temp.x = x - obj.x;
	temp.y = y - obj.y;
	temp.z = z - obj.z;
	return temp;
}

three_d operator ++(three_d &obj) {
	obj.x++;
	obj.y++;
	obj.z++;
	return obj;
}

three_d operator --(three_d &obj) {
	obj.x--;
	obj.y--;
	obj.z--;
	return obj;
}

int three_d::operator ==(const three_d &obj) {
	return x == obj.x && y == obj.y && z == obj.z;
}

int three_d::operator !=(const three_d &obj) {
	return x != obj.x && y != obj.y && z != obj.z;
}

int three_d::operator ||(const three_d &obj) {
	return (x || obj.x) && (y || obj.y) && (z || obj.z);
}

three_d operator +(const three_d &obj, int i) {
	three_d temp;
	temp.x = obj.x + i;
	temp.y = obj.y + i;
	temp.z = obj.z + i;
	return temp;
}

three_d operator +(int i, const three_d &obj) {
	three_d temp;
	temp.x = obj.x + i;
	temp.y = obj.y + i;
	temp.z = obj.z + i;
	return temp;
}

int main() {
	three_d obj1(10, 10, 10), obj2(5, 3, 2), obj3(11, 11, 11), obj4;
	int x, y, z;
	obj4 = obj1 + obj2;
	obj4.get(x, y, z);
	cout << "(obj1+obj2) X: " << x << ", Y: " << y << ", Z: " << z << "\n";
	obj4 = obj1 - obj2;
	obj4.get(x, y, z);
	cout << "(obj1-obj2) X: " << x << ", Y: " << y << ", Z: " << z << "\n";
	++obj1;
	obj1.get(x, y, z);
	cout << "(++obj1) X: " << x << ", Y: " << y << ", Z: " << z << "\n";
	--obj2;
	obj2.get(x, y, z);
	cout << "(--obj2) X: " << x << ", Y: " << y << ", Z: " << z << "\n";
	if (obj1 == obj2)
		cout << "obj1 same as obj2\n";
	else
		cout << "obj1 and obj2 differs\n";
	if (obj1 != obj3)
		cout << "obj1 and obj3 differs\n";
	else
		cout << "obj1 same as obj3\n";
	if (obj1 || obj2)
		cout << "obj1 || obj2 is true\n";
	else
		cout << "obj1 || obj2 is false\n";
	obj1 = obj1 + 10;
	obj1.get(x, y, z);
	cout << "(obj1+10) X: " << x << ", Y: " << y << ", Z: " << z << "\n";
	obj1 = 10 + obj1;
	obj1.get(x, y, z);
	cout << "(10+obj1) X: " << x << ", Y: " << y << ", Z: " << z << "\n";
	return 0;
}