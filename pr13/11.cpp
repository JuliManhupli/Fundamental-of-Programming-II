#include<iostream>
using namespace std;

class cls{
	int num;
public:
	cls(int n) {num = n;}
	/*cls &operator =(const cls &obj){
		num = obj.num;
		return *this;
	}*/
	int get() { return num; }
};

int main(){
	cls obj1(0), obj2(5);
	obj1 = obj2;
	cout << obj1.get() << endl;
}
