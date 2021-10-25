#include<iostream>
using namespace std;

class base {
	int a;
public:
	void load_a(int n) {a=n;}
	int get_a() {return a;}
};

class derived: public base{
	int b;
public:
	void load_b(int n) {b = n;}
	int get_b() { return b; }
};

int main(){
	derived ob1, ob2;
	ob1.load_b(5);
	ob1.load_a(6);
	ob2=ob1;
	cout<<ob1.get_a()<<endl;
	cout<<ob1.get_b()<<endl;
	cout<<ob2.get_a()<<endl;
	cout<<ob2.get_b()<<endl;
}