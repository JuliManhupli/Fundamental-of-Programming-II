#include<iostream>
#include <cstring>
using namespace std;

#define SIZE 255

class strtype{
	char *p;
public:
	strtype(char const *str);
	~strtype();
	void show();
	friend strtype test(char const *str);
};

strtype::strtype(char const *str){
	p=(char *) malloc(strlen(str));
	if(!p) {
		cout<<"Allocation error.\n";
		exit(1);
	}
	strcpy(p,str);
}

strtype::~strtype(){
	cout<<"Freeing p\n";
	free(p);
}

void strtype::show(){
	cout<<p<<"\n";
}

strtype test(strtype ob){
  return ob;
}

int main(){
	strtype s1("This is a test."), s2("I like C++. ");
	s1.show();
	s2.show();
	s2 = test(s1);
	s1.show();
	s2.show();
	return 0;
}

