#include <iostream>
#include <cstdlib>
using namespace std;

class myclass {
	int a;
public:
	explicit myclass(int x) {a = x;}
	myclass(char *str) {a = atoi(str);}
	int geta() {return a;}
};

int main() {
	myclass obj1(123);
	myclass obj2 ("4");
	//myclass obj2 = "4";
	cout << "obj1: " << obj1.geta() << '\n';
	cout << "obj2: " << obj2.geta() << '\n';
	return 0;
}	

//atoi преобразует строку string в целое значение типа int