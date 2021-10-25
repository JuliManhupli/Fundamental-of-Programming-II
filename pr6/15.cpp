#include<iostream>
using namespace std;
void print(int num);
class coord{
	int x,y;
public:
	coord() { x = 0; y = 0; };
	coord(int i, int j) { x=i;y=j; }
	void get_xy(int &i, int &j)  {i=x; j=y; }
	coord operator <<(int i);
	coord operator >>(int i);
};

coord coord::operator <<(int i){
	coord temp;
	temp.x = x << i;
	temp.y = y << i;
	return temp;
}

coord coord::operator >>(int i){
	coord temp;
	temp.x = x >> i;
	temp.y = y >> i;
	return temp;
}


int main() {
	coord obj1(10, 10), obj2, obj3;
	int x, y;
	obj1.get_xy(x, y);
	cout << "(obj1) X: " << x << ", Y: " << y << "\n";
	obj2 = obj1 << 3;
	obj2.get_xy(x, y);
	cout << "(obj1<<3) X: " << x << ", Y: " << y << "\n";
	obj3 = obj1 >> 3;
	obj3.get_xy(x, y);
	cout << "(obj1>>3) X: " << x << ", Y: " << y << "\n";
	cout << "В двоичном виде:\n";
	obj1.get_xy(x, y);	
	cout << "(obj1) ";
	print(x);
	obj2.get_xy(x, y);	
	cout << "\n(obj1<<3) ";
	print(x);
	obj3.get_xy(x, y);	
	cout << "\n(obj1>>3) ";
	print(x);
	return 0;
}

void print(int num) {
	for(int i = 15; i>=0 ; --i)
		cout<<((num>>i) & 1);

}

