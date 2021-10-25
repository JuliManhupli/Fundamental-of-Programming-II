#include<iostream>
using namespace std;
template <class T> class coord {
	T x, y;
public:
	coord() { x = 0; y = 0; cout << "Constructing A" << endl; };
	coord(T i, T j) { x = i; y = j; cout << "Constructing B" << endl; }
	void get_xy(T& i, T& j) { i = x; j = y; }
	~coord() { cout << "Destructing" << endl; };
};

int main() {
	coord<int> obj1(10, 10);
	coord<double> obj2(10.5, 9.25);
	int x1, y1;
	obj1.get_xy(x1, y1);
	cout << "(obj1) X: " << x1 << ", Y: " << y1 << "\n";
	double x2, y2;
	obj2.get_xy(x2, y2);
	cout << "(obj2) X: " << x2 << ", Y: " << y2 << "\n";
	return 0;
}