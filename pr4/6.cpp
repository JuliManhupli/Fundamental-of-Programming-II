#include<iostream>
#include<cstring>
using namespace std;

class samp {
	char* name;
	char* number;
public:
	samp(char* s, char* num) { name = s; number = num; }
	void show();
};

void samp::show() {
	cout << "Имя: " << name << endl;
	cout << "Номер: " << number << endl;
}

int main() {
	samp* ptr;
	ptr = new samp("Юлия Мангупли", "+380995067428");;
	if (!ptr) {
		cout << "Ошибка распределения";
	}
	ptr->show();
	delete ptr;
	return 0;
}