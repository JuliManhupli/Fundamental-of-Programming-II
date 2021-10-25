#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int main(int argc, char* argv[]) {
	ifstream in("file3.txt");
	if (!in) {
		cout << "Can't open file\n";
		return 1;
	}
	char str[100];
	int i = 0;
	while (!in.eof()) {
		in >> str;
		if (strcmp(str, argv[1]) == 0){
			i++;
		}
	}
	cout << "Слово встречается " << i << " раз(а)" << endl;
	in.close();
	return 0;
}