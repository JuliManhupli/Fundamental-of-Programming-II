#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;
int main() {
	ifstream fin("file.txt");
	if (!fin) {
		cout << "Can't open input file.\n";
		return 1;
	}
	ofstream fout("file2.txt");
	if (!fout) {
		cout << "Can't open output file.\n";
		return 1;
	}
	char ch;
	while (!fin.eof()) {
		fin.get(ch);
		if (fin.eof()) {
			break;
		}
		if (ch == '\t') {
			for (int i = 0; i < 8; i++) {
				fout.put(' ');
			}
		}
		else {
			fout.put(ch);
		}
	}
	fin.close();
	fout.close();
	return 0;
}
