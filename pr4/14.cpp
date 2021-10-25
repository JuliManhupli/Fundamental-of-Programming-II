#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

#define SIZE 255

class strtype {
	char* p;
	int len;
public:
	strtype(char const* str);
	~strtype();
	void show();
};

strtype::strtype(char const* str) {
	p = new char[SIZE];
	if (!p) {
		cout << "Allocation error.\n";
		exit(1);
	}
	strcpy(p, str);
	len = strlen(p);
}

strtype::~strtype() {
	cout << "Delete p\n";
	delete[] p;
}

void strtype::show() {
	cout << p << "- length: " << len;
	cout << "\n";
}

int main() {
	strtype s1("This is a test."), s2("I like C++. ");
	s1.show();
	s2.show();
	return 0;
}