#include<iostream>
#include<cstdlib>
using namespace std;

class stack{
	char *stck;
	int tos=0, size;
public:
	stack(int n);
	~stack();
	void push(char ch);
	char pop();
};

stack::stack(int n){
	cout<<"Constructing a stack\n";
	stck = (char *) malloc(n);
	if(!stck){
		cout<<"Error with memory allocation\n";
		return;
	}
	size = n;
}

stack::~stack(){
	free(stck);
}

void stack::push(char ch){
	if(tos==size){
		cout<<"Stack is full";
		return;
	}
	stck[tos] = ch;
	tos++;
}

char stack::pop(){
	if(tos == 0){
		cout<<"Stack is empty";
		return 0;
	}
	tos--;
	return stck[tos];
}


int main(){
	stack s1(10),s2(10);
	int i;
	s1.push('a');
	s2.push('x');
	s1.push('b');
	s2.push('y');
	s1.push('c');
	s2.push('z');
	for(i=0;i<3;i++) 
		cout<<"Pop s1:"<<s1.pop()<<"\n";
	for(i=0;i<3;i++) 
		cout<<"Pop s2:"<<s2.pop()<<"\n";
	return 0;
}