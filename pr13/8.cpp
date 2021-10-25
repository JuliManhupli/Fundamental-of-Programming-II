#include <iostream>
#include <cstdlib>
using namespace std;

class myclass {
	bool a;
public:
	explicit myclass(bool x) {a = x;}
	bool get() {return a;}
};

int main() {
	myclass obj1(true);
	cout << "obj1: " << obj1.get() << '\n';
	return 0;
}	
