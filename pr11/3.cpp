#include<iostream>
using namespace std;
#define SIZE 5
template <class StackType> class Stack {
	StackType stck[SIZE];
	int tos;
public:
	void init() { tos = 0; };
	void push(StackType obj);
	StackType pop();
};

template<class StackType>
void Stack<StackType> ::push(StackType obj) {
	if (tos == SIZE) {
		cout << "Stack if full\n";
		return;
	}
	stck[tos] = obj;
	tos++;
}

template<class StackType>
StackType Stack<StackType> ::pop() {
	if (tos == 0) {
		cout << "Stack is empty.\n";
		return 0;
	}
	tos--;
	return stck[tos];
}

int main() {
	Stack<char> s1;
	s1.init();
	s1.push('a');
	s1.push('b');
	s1.push('c');
	cout << s1.pop();
	cout << s1.pop();
	cout << s1.pop();
	cout << endl;

	Stack<int> s2;
	s2.init();
	s2.push(1);
	s2.push(2);
	s2.push(3);
	cout << s2.pop();
	cout << s2.pop();
	cout << s2.pop();
	cout << endl;
	return 0;
}