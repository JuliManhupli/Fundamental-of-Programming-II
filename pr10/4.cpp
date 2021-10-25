#include<iostream>
#include<fstream>
using namespace std;
int main() {
	fstream out("file3.txt", ios::in | ios::out | ios::binary);
	if (!out) {
		cout << "Can't open file\n";
		return 1;
	}
	out.seekp(81, ios::beg);
	out.put('*');
	out.close();
	return 0;
}