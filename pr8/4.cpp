#include<iostream>
using namespace std;
int main() {
	ios::fmtflags prev = cout.flags();
	cout.unsetf(ios::dec);
	cout.setf(ios::showbase | ios::hex);
	cout << 100 << endl;
	cout.flags(prev);
	cout << 100 << endl;
	return 0;
}

/*showbase - при выводе указывать числовую базу

hex - значения выводятся в шестнадцатеричной форме*/