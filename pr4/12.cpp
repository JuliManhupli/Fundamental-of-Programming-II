#include<iostream>
#include<cstdlib>
using namespace std;

class array {
	int rows, coloumn;
	int* p;
public:
	array(int num1, int num2);
	~array() { delete[] p; }
	int& put(int i, int j);
	int get(int i, int j);
};

array::array(int num1, int num2) {
	p = new int[num1 * num2];
	if (!p) {
		cout << "Allocation error \n";
		exit(1);
	}
	rows = num1;
	coloumn = num2;
}

int& array::put(int i, int j) {
	if (i < 0 || i >= rows || j < 0 || j >= coloumn) {
		cout << "Bounds error!\n";
		exit(1);
	}
	return p[i * coloumn + j];
}

int array::get(int i, int j) {
	if (i < 0 || i >= rows || j < 0 || j >= coloumn) {
		cout << "Bounds error!\n";
		exit(1);
	}
	return p[i * coloumn + j];
}

int main() {
	array ob(2, 3);
	int c = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			ob.put(i, j) = c;
			c++;
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << ob.get(i, j) << ' ';
		}
		cout << "\n";
	}
	ob.put(10, 10) = 1;
	return 0;
}