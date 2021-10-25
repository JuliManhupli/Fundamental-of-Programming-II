#include<iostream>
using namespace std;
#define SIZE 5
template <class X> X sum(X* data, int size) {
	int i;
	X s = 0;
	for (i = 0; i < size; i++)
		s = s + data[i];
	return s;
}

template <class X>void print(X* list, int size) {
	for (int i = 0; i < size; i++) {
		cout << list[i] << ' ';
	}
	cout << "\n";
}

int main() {
	int list1[SIZE] = { 5,4,3,2,1 };
	double list2[SIZE] = { 5.1, 4.2, 3.3,  2.4, 1.5 };
	print(list1, SIZE);
	cout << "Sum: " << sum(list1, SIZE) << endl;
	print(list2, SIZE);
	cout << "Sum: " << sum(list2, SIZE) << endl;
	return 0;
}