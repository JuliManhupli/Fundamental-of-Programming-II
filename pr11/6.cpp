#include<iostream>
using namespace std;
#define SIZE 5
template <class X> X max(X *list, int size) {
	int k, l, max;
	max = 0;
	for (int i = 0; i < size - 1; i++) {
		k = 1;
		for (int j = i + 1; j < size; j++) {
			if (list[i] == list[j]) {
				k++;
			}
			if (k > max) { 
				max = k; 
				l = i; 
			}
		}
	}
	return list[l];
}

template <class X> void print(X *list, int size) {
	for (int i = 0; i < size; i++) {
		cout << list[i] << ' ';
	}
	cout << "\n";
}

int main() {
	int list1[SIZE] = { 5,4,3,4,1 };
	double list2[SIZE] = { 5.1, 4.2, 2.4, 2.4, 1.5 };
	char list3[SIZE]={'a', 'b', 'c', 'a', 'e'};
	print(list1, SIZE);
	cout << "Чаще всего встречается: " << max(list1, SIZE) << endl;
	print(list2, SIZE);
	cout << "Чаще всего встречается: " << max(list2, SIZE) << endl;
	print(list3, SIZE);
	cout << "Чаще всего встречается: " << max(list3, SIZE) << endl;
	return 0;
}
