#include<iostream>
using namespace std;

class pr2;
class pr1 {
	int printing;
public:
	pr1() { printing = 1; }
	void set_print(int status) { printing = status; }
	friend bool inuse(pr1 a, pr2 b);

};

class pr2 {
	int printing;
public:
	pr2() { printing = 0; }
	void set_print(int status) { printing = status; }
	friend bool inuse(pr1 a, pr2 b);
};

bool inuse(pr1 a, pr2 b){
	bool ind;
	if (a.printing==0 && b.printing==0){
		ind = false;
	}
	else ind = true;
	return ind;
}

int main(){
	pr1 a;
	pr2 b;
	bool p;
	p = inuse(a,b);
	if(p){
		cout<<"Принтер занят объектом\n";
	}
	else cout<<"Принтер свободен\n";
	return 0;
}
