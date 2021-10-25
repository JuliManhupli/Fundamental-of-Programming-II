#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	cout << resetiosflags(ios::dec);
	cout << setiosflags(ios::showbase | ios::hex) << 100 << endl;
	return 0;
}