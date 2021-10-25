#include<iostream>
using namespace std;

class myclass {
	int x;
public:
	int &ref = x;
	myclass(int n) { x = n; cout << "Construction" << endl; };
	~myclass (){ cout << "Destructing..."<< endl;}
	int get() { return x; }
};

int main() {
	myclass ob(0);
	cout << ob.get() << endl;
	ob.ref = 1;
	cout << ob.get() << endl;
	return 0;
}