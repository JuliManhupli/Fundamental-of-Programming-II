#include<iostream>
#include<cstdlib>
using namespace std;

class myclass {
	int *ptr;
public:
	myclass(int i);
	myclass(const myclass& obj);
	~myclass() { delete ptr; }
	friend int getval(myclass obj);
};

myclass::myclass(int i) {
	ptr = new int;
	if (!ptr) { exit(1); }
	*ptr = i;
}

//конструктор копирования 
myclass::myclass(const myclass& obj) {
	ptr = new int;
	if (!ptr) { exit(1); }
	*ptr = *obj.ptr;
}

int getval(myclass obj) {
	return *obj.ptr;
}
int main() {
	myclass a(1), b(2);
	cout << getval(a) << " " << getval(b) << "\n";
	cout << getval(a) << " " << getval(b);
	return 0;
}


