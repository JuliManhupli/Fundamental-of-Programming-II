#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class strtype {
	char *p;
	int len;
public:
	strtype();
	strtype(const char* str, unsigned int memory);
	char* getstring() { return p; }
	int getlength() { return len; }
};

strtype::strtype() {
	p = new char[255];
	*p = '\0';
	len = 255;
}

strtype::strtype(const char* str, unsigned int memory) {
	if (strlen(str) >= memory) {
		cout << "Bounds error!\n";
		exit(1);
	}
	p = new char[memory];
	strcpy(p, str);
	len = memory;
}

int main() {
	strtype s1;
	strtype s2("This is a test.", 50);
	cout<<"Первая строка: "<<s1.getstring()<<endl;
	cout<<"Длина первой строки: "<<s1.getlength()<<endl;
	cout<<"Вторая строка: "<<s2.getstring()<<endl;
	cout<<"Длина второй строки: "<<s2.getlength()<<endl;	
	return 0;
}
