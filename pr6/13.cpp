#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class strtype{
	char *ptr;
	int len;
public:
	strtype(char const *s);
	~strtype(){
		cout<<"Freeing ptr\n";
		delete [] ptr;
	}
	char *get() { return ptr; }
	strtype &operator =(const strtype &obj);
	char &operator [](int tmp);
};

strtype::strtype(char const *s){
	int len = strlen(s) + 1;
	ptr = new char[len];
	if(!ptr){
		cout<<"Allocation error\n";
		exit(1);
	}
	this->len = len;
	strcpy(ptr, s);
}

strtype &strtype::operator =(const strtype &obj){
	if(len<obj.len){
		delete [] ptr;
		ptr = new char[obj.len];
		if(!ptr){
			cout<<"Allocation error\n";
			exit(1);
		}
	}
	len = obj.len;
	strcpy(ptr, obj.ptr);
	return *this;
}

char &strtype::operator[](int i){
	if(i < 0 || i > len-1){
		cout<<"Bounds error!\n";
		cout<<"Index value of " << i <<"  is out of bounds.\n";
		exit(1);
	}
	return ptr[i];
}


int main() {
	strtype a("Hello"), b("Goodbye");
	cout << "a: " << a.get() << '\n';
	cout << "b: " << b.get() << '\n';
	a = b;
	cout << "(a = b)\n";
	cout << "a: " << a.get() << '\n';
	cout << "b: " << b.get() << '\n';
	cout << "a[2]\n";
	cout << a[2] << '\n';
	a[6]='a';
	cout << "a[6]='a'\n";
	cout << "a: " << a.get() << '\n';
	return 0;
}
