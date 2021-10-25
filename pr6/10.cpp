#include<iostream>
using namespace std;
class dynarray {
	int *ptr;
	int size;
public:
	dynarray(int s);
	int &put(int i);
	int get(int i);
	dynarray &operator =(dynarray &obj1);
};

dynarray::dynarray(int s) {
	ptr = new int[s];
	if (!ptr) {
		cout << "Allocation error\n";
		exit(1);
	}
	size = s;
}

int &dynarray::put(int i) {
	if (i < 0 || i > size) {
		cout << "Bounds error!\n";
		exit(1);
	}
	return ptr[i];
}

int dynarray::get(int i) {
	if (i < 0 || i > size) {
		cout << "Bounds error!\n";
		exit(1);
	}
	return ptr[i];
}

dynarray &dynarray::operator =(dynarray &obj1) {
	if (size != obj1.size) {
		cout << "Different sizes of arrays\n";
		exit(1);
	}
	for (int i = 0; i < size; i++)
		ptr[i] = obj1.ptr[i];
	return *this;
}

int main() {
	dynarray obj1(3), obj2(3);
	for (int i=0; i<3; i++){
		obj1.put(i)=i;
	}
	cout << "obj1: ";
	for (int i=0; i<3; i++){
		cout << obj1.get(i) << ' ';
	}	
	obj2 = obj1;
	cout<< "\n(obj2 = obj1)\nobj2: ";
	for (int i=0; i<3; i++){
		cout << obj2.get(i) << ' ';
	}		
	return 0;
}
