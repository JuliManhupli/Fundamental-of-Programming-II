//9
#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ifstream fin("file.txt");
	if(!fin){
		cout << "Cannot open input file.\n";
		return 1;
	}
	char ch;
	int i = 0;
	fin.unsetf(ios::skipws);
	while (!fin.eof()) {
		fin.get(ch);
		cout << ch;
		if(ch == ' ' || ch == '\n'){
			i++;
		}
	}
	cout << endl;
	cout << "Количество слов: " << i - 1 << endl;
	fin.close();
	return 0;
}