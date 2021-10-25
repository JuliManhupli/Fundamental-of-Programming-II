#include <iostream>
#include <cstring>
#include <cstdlib>
#include<string>
using namespace std;
class strtype {
	char *p;
	int len;
public:
	strtype(const char* ptr);
	~strtype() { delete[] p; }
	friend ostream &operator <<(ostream &stream, strtype &obj);
	friend istream &operator >>(istream &stream, strtype &obj);
};

strtype::strtype(const char* ptr) {
	len = strlen(ptr) + 1;
	p = new char(len);
	if (!p) {
		cout << "Allocation error\n";
		exit(1);
	}
	strcpy(p, ptr);
}

ostream &operator <<(ostream &stream, strtype &obj){
	stream << obj.p << '\n';
	return stream;
}

istream &operator >>(istream &stream, strtype &obj){
	char *q;
	string str;
	cout << "Введите свою строку:\n";
	getline(stream, str);
	q = new char[str.length()+1];
	strcpy(q,str.c_str()); 
	obj.len = strlen(q) +1;
	obj.p = new char[obj.len];
	strcpy(obj.p, q);
	return stream;
}

int main() {
	strtype s1("This is a test."), s2("I hate C++!"), s3("");
	cout << s1 << s2;
	cin >> s3;
	cout << s3;
	return 0;
}