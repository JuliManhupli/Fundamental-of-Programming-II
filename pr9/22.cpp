#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
#define SIZE 10;
class stack{
	fstream io;
	int tos;
public:
	stack(const char *str) : io(str, ios::in | ios::out | ios::binary){
		io.unsetf(ios::skipws);
		io.seekp(0, ios::end);
		tos = (int) io.tellp();
	}
	~stack(){ io.close(); }
	char pop();
	void push(const char &ch);
};

char stack::pop(){
	if(tos == 0){
		cout<<"Stack is empty";
		return 0;
	}
	tos--;
	io.seekg(tos,ios::beg);
	return io.get();
}

void stack::push(const char &ch){
	if(tos == 10) {
		cout<<"Stack if full";
		return;
	}
	io.seekp(tos,ios::beg);
	io.put(ch);
	tos++;
}

int main(){
	stack s("stack.txt");
	s.push('a');
	s.push('b');
	s.push('c');
	s.push('d');
	s.push('e');
	for (int i = 0; i < 5; i++) {
		cout << s.pop() << " ";
	}
	return 0;
}
