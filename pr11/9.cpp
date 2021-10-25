#include<iostream>
using namespace std;
#define SIZE 5
template <class StackType1, class StackType2> class Stack {
	StackType1 stck1[SIZE];
	StackType2 stck2[SIZE];
	int tos;
public:
	void init() { tos = 0; };
	void push(StackType1 obj1, StackType2 obj2);
	void pop();
};

template<class StackType1, class StackType2>
void Stack<StackType1, StackType2> ::push(StackType1 obj1, StackType2 obj2) {
	if (tos == SIZE) {
		cout << "Stack if full\n";
		return;
	}
	stck1[tos] = obj1;
	stck2[tos] = obj2;
	tos++;
}

template<class StackType1, class StackType2>
void Stack<StackType1, StackType2> ::pop() {
	if (tos == 0) {
		cout << "Stack is empty.\n";
	}
	tos--;
	cout << stck1[tos] << ' ' << stck2[tos] << endl;
}

int main() {
	char ch = 'a';
	Stack<char, int> s1;
	s1.init();
	for (int i = 0; i < 5; i++) {
		s1.push(ch, i);
		ch++;
	}
	for (int i = 0; i < 5; i++) {
		s1.pop();
	}
	cout << endl;

	Stack<int, double> s2;
	s2.init();
	for (int i = 0; i < 5; i++) {
		s2.push(i, i * 0.2);
	}
	for (int i = 0; i < 5; i++) {
		s2.pop();
	}
	cout << endl;
	return 0;
}

