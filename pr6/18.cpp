#include<iostream>
#include<cstring>
#define SIZE 100
using namespace std;
class strtype{
	char str[SIZE];
public:
	strtype() { *str = '\0'; }
	strtype(const char *ptr) {strcpy(str, ptr);}
	char *get(){ return str; }
	strtype operator +(strtype tmp);
	strtype operator =(strtype temp);
	bool operator <(strtype temp);
	bool operator >(strtype temp);
	bool operator ==(strtype temp);
};

strtype strtype::operator +(strtype tmp){
	strtype temp;
	strcpy(temp.str, str);
	strcat(temp.str, tmp.str);
	return temp;
}

strtype strtype::operator =(strtype temp){
	strcpy(str, temp.str);
	return *this;
}

bool strtype::operator <(strtype temp){
	if(strcmp(str, temp.str) < 0)
		return true;
	else
		return false;
}

bool strtype::operator >(strtype temp){
	if(strcmp(str, temp.str) > 0)
		return true;
	else
		return false;
}

bool strtype::operator ==(strtype temp){
	if(strcmp(str, temp.str) == 0)
		return true;
	else
		return false;
}

int main(){
	strtype obj1("Hello"), obj2(" Goodbye"), obj3;
	obj3 = obj1 + obj2;
	cout << "(obj1+obj2) "<< obj3.get() << "\n";
	obj3 = obj1;
	cout<<"(obj3=obj1) "<< obj3.get() << "\n";
	if (obj1 == obj2)
		cout << "obj1 same as obj2\n";
	else
		cout << "obj1 and obj2 differs\n";
	if (obj1 > obj2)
		cout << "obj1 > obj2 is true\n";
	else
		cout << "obj1 > obj2 is false\n";
	if (obj1 < obj2)
		cout << "obj1 < obj2 is true\n";
	else
		cout << "obj1 < obj2 is false\n";
	return 0;
}
