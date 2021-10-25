#include<iostream>
#include<cmath>
using namespace std;
class pwr{
	int base;
	int exp;
public:
	pwr(int b, int e) { base = b; exp = e; }
	operator int() { return pow(base, exp); }
};

int main(){
	pwr obj(2,5);
	cout << "2^5 = " << obj << endl;
	return 0;
}
