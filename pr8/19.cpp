#include<iostream>
using namespace std;
#define SIZE 10

class stack {
	char stck[SIZE];
	int tos;
public:
	stack();
	void push(char ch);
	char pop();
	friend ostream &operator <<(ostream &stream, stack obj);
};

stack::stack() {
	tos = 0;
}

void stack::push(char ch) {
	if (tos == SIZE) {
		cout << "Stack is full\n";
		return;
	}
	stck[tos] = ch;
	tos++;
}

char stack::pop() {
	if (tos == 0) {
		cout << "Stack is empty\n";
		return 0;
	}
	tos--;
	return stck[tos];
}

ostream &operator <<(ostream &stream, stack obj) {
	char t;
	while((t = obj.pop())!=0){
		stream << t << endl;
	}
	return stream;
}

int main() {
	stack s1;
	s1.push('a');
	s1.push('b');
	s1.push('c');
	cout << s1;
	return 0;
}

