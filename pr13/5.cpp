#include<iostream>
#include<cmath>
using namespace std;
class Cls{
	static int i;
public:
	Cls(){ i++; cout << i << endl; }
	~Cls(){ i--; cout << i << endl;}
};

int Cls::i = 0;

int main(){
	Cls obj1, obj2, obj3;
	return 0;
}
