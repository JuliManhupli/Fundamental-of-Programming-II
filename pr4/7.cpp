#include<iostream>
using namespace std;

class samp {
	int i, j;
public:
	void set_ij(int a, int b) { i = a; j = b; }
	int get_product() { return i * j; }
	~samp();
};

samp::~samp(){
	cout << "Destructing...\n";
}

int main() {
	samp* ptr;
	ptr = new samp[10];
	for (int i = 0; i < 10; i++)
		ptr[i].set_ij(i, i);
	for (int i = 0; i < 10; i++) {
		cout << "Product[" << i << "] is: ";
		cout << ptr[i].get_product() << "\n";
	}
	delete[] ptr;
	return 0;
}