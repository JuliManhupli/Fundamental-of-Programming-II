#include<iostream>
#include<cstring>
using namespace std;

void myclreol(char* str, int c = 0) {
	if (c == 0) {
		delete str;
	}
	else {
		for (int i = 0; i < c; i++) {
			cout << '\b' <<' '<< '\b';
		}
	}
}

int main() {
	char *str = new char;
	int pos;
	cout << "Введите строку\n";
	gets(str);
	cout << "Введите, какое количество символов удалить\n(0 - удалить всю строку) \n";
	cin >> pos;
	if (pos == 0) {
		myclreol(str);
	}
	else {
		cout << str;
		myclreol(str, pos);
	}
}


