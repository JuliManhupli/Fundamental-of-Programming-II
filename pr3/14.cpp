#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class strtype{
	char *p;
	int len;
public:
	strtype(char const *ptr);
	~strtype();
	void show();
	friend char *get_string(strtype *ptr);
};

strtype::strtype(char const *ptr){
	len = strlen(ptr);
	p = (char *)malloc(len+1);
	if(!p){
		cout<<"Allocation error.\n";
		exit(1);
	}
	strcpy(p,ptr);
}

strtype::~strtype(){
	cout<<"Freeing string\n";
	free(p);
}

void strtype::show(){
	cout<<p<<" - length: "<<len<<"\n";
}

char *get_string(strtype *ptr){
	return ptr->p;
}

int main(){
	char *p1, *p2;
	strtype s1("This is a test."),
		s2("I hate any programming!");
	s1.show();
	s2.show();
	p1 = get_string(&s1);
	cout<<p1<<endl;
	p2 = get_string(&s2);
	cout<<p2<<endl;
	return 0;
}

