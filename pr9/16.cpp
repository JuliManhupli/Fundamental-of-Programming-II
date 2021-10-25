#include<iostream>
#include<fstream>
using namespace std;
int main() {
	fstream io("file2.txt", ios::in | ios::out | ios::binary);
	char ch1, ch2;
	for (int i = 0; !io.eof(); i = i + 2) {
		io.seekg(i, ios::beg);
		io.get(ch1);
		io.get(ch2);
		if (io.eof()) {
			break;
		}
		io.seekg(i, ios::beg);
		io.put(ch2);
		io.put(ch1);
	}
	io.close();
	return 0;
}
