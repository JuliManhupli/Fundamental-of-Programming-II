#include<iostream>
#include<fstream>
using namespace std;
int main() {
	ifstream fin("file3.txt");
	if (!fin) {
		cout << "Can't open input file.\n";
		return 1;
	}
	char str[200];
	fin.unsetf(ios::skipws);
	while (!fin.eof()) {
		fin.getline(str, 254);
		cout << str << endl;
	}
	fin.close();
	return 0;
}