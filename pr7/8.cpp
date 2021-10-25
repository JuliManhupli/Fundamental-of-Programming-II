#include <iostream>
using namespace std;
class A {
	int i;
public:
	A(int a) { i = a; }
	int get_i() { return i; }
};

class B {
	int j;
public:
	B(int a) { j = a; }
	int get_j() { return j; }
};

class C : public A, public B {
	int k;
public:
	C(int i, int a, int b) : A(a), B(b) {	k = i; }
	int get_k() { return k; }
};

int main(){
	C obj(1,2,3);
	cout<<"i: "<<obj.get_i()<<" j: "<<obj.get_j()<<" k: "<<obj.get_k();
	return 0;
}
