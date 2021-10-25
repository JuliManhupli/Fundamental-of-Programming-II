#include<iostream>
using namespace std;
class samp {
	int a;
public:
	samp() { a = 0; }
	samp(int n) { a = n; }
	int get_a() { return a; }
};

int main() {
	samp obj(88);
	samp objarray[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "obj: " << obj.get_a() << "\n";
	cout << "objarray: ";
	for (int i = 0; i < 10; i++) {
		cout << objarray[i].get_a() << " ";
	}
	return 0;
}