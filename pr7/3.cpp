#include <iostream>
using namespace std;
class array {
	int nums[10];
public:
	array();
	void set(int n[10]);
	void show();
	array operator +(array obj2);
	array operator -(array obj2);
	bool operator ==(array obj2);
	array operator ++();
	friend array operator --(array &obj1);
};

array::array() {
	for (int i = 0; i < 10; i++) nums[i] = 0;
}

void array::set(int* n) {
	for (int i = 0; i < 10; i++) nums[i] = n[i];
}

void array::show() {
	for (int i = 0; i < 10; i++)
		cout << nums[i] << ' ';
	cout << "\n";
}

array array::operator +(array obj2){
	array temp;
	for(int i=0; i<10; i++)
		temp.nums[i] = nums[i] + obj2.nums[i];
	return temp;
}

array array::operator -(array obj2){
	array temp;
	for(int i=0; i<10; i++)
		temp.nums[i] = nums[i] - obj2.nums[i];
	return temp;
}

bool array::operator ==(array obj2){
	bool ind = true;
	for(int i=0; i<10; i++){
		if (nums[i] != obj2.nums[i]){
			ind = false;
		}
	}
	return ind;
}

array array::operator ++(){
	array temp;
	for(int i=0; i<10; i++)
		temp.nums[i] = ++nums[i];
	return temp;
}

array operator --(array &obj1){
	for(int i=0; i<10; i++)
		obj1.nums[i]--;
	return obj1;
}
int main() {
	array obj1, obj2, obj3, obj4;
	int i[10] = { 1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10 };
	obj1.set(i);
	obj2.set(i);
	obj3 = obj1 + obj2;
	obj3.show();
	obj3 = obj1 - obj3;
	obj3.show();
	if (obj1 == obj2)
		cout << "obj1 equals obj2\n";
	else
		cout << "obj1 does not equal obj2\n";
	if (obj1 == obj3)
		cout << "obj1 equals obj3\n";
	else
		cout << "obj1 does not equal obj3\n";
	cout<< "(obj1) ";
	obj1.show();
	obj4 = ++obj1;
	cout << "(++obj1) "; 
	obj4.show();
	cout<< "(obj2) ";
	obj2.show();	
	obj4 = --obj2;
	cout << "(--obj2) "; 
	obj4.show();
	return 0;
}
