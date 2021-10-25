#include<iostream>
using namespace std;
class cls1 {
public:
	int num;
	cls1(int i) { num = i; }
	virtual void fun() {
		cout << "Число увеличеное на 1 " << num+1 << endl;
	}
};

class cls2 : public cls1 {
public:
	cls2(int i): cls1(i) {}
	void fun() {
		cout << "Число уменьшеное на 1 " << num-1 << endl;
	}
};

int main() {
	cls1 obj1(10);
	cls2 obj2(10);
	cls1 *ptr;
	ptr = &obj1;
	ptr->fun();
	ptr = &obj2;
	ptr->fun();
	return 0;
}
