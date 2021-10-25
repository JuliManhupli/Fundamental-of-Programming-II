#include<iostream>
using namespace std;
class box {
	int a;
public:
	box(int i) { a = i; }
	friend ostream &operator <<(ostream &stream, box obj);
};

ostream &operator <<(ostream &stream, box obj) {
	for (int i = 0; i < obj.a; i++) {
		stream << "* ";
	}
	stream << '\n';
	for (int i = 0; i < obj.a - 2; i++) {
		stream << "* ";
		for (int i = 0; i < obj.a - 2; i++) {
			stream << "  ";
		}
		stream << '*';
		stream << '\n';
	}
	for (int i = 0; i < obj.a; i++) {
		stream << "* ";
	}
	return stream;
}

int main() {
	box obj1(5), obj2(7);
	cout << obj1 << endl;
	cout << obj2 << endl;
	return 0;
}
