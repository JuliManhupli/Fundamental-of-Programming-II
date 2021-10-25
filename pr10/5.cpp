#include<iostream>
using namespace std;
class Num {
public:
	int n;
	Num(int a) { n = a; }
	virtual void shownum() { cout << n << endl; }
};

class outhex : public Num {
public:
	outhex(int b) : Num(b) {};
	void shownum() {
		cout << hex << n << endl;
	}
};

class outoct : public Num {
public:
	outoct(int b) : Num(b) {};
	void shownum() {
		cout << oct << n << endl;
	}
};

int main() {
	Num obj1(10);
	outhex obj2(10);
	outoct obj3(10);
	obj1.shownum();
	obj2.shownum();
	obj3.shownum();
	return 0;
}


