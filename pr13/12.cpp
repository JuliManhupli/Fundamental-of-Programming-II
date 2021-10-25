#include<iostream>
using namespace std;

class cls{
	int num;
public:
	cls(const int &n) { num = n; }
	void const_change(int p) const {
		cls *obj;
		obj = const_cast<cls *>(this);
		obj->num = p;
	}
	int get(){
		return num;
	}
};


int main(){
	cls obj1(10);
	cout << obj1.get() << endl;
	obj1.const_change(20);
	cout << obj1.get() << endl;
	return 0;
}
