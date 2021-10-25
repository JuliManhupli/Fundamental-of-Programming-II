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
	strtype &operator =(const strtype &obj);
	char &operator [](int tmp);
	int str() { return len; }
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
	cout << "a: ";
	for (int i = 0; i < a.str(); i++){
		cout << a[i];
	}
	cout << "\nb: ";
	for (int i = 0; i < b.str(); i++){
		cout << b[i];
	}	
	a = b;
	cout << "\n(a = b)\n";
	cout << "a: ";
	for (int i = 0; i < a.str(); i++){
		cout << a[i];
	}
	cout << "\nb: ";
	for (int i = 0; i < b.str(); i++){
		cout << b[i];
	}	
	cout << "\na[2]\n";
	cout << a[2] << '\n';
	a[6]='a';
	cout << "a[6]='a'\n";
	cout << "a: ";
	for (int i = 0; i < a.str(); i++){
		cout << a[i];
	}
	cout << endl;
	return 0;
}
