#include<iostream>
using namespace std;
#define SIZE 100

class stack{
	char stck[SIZE];
	int tos;

public:
	void init();
	void push(char ch);
	char pop();
	friend void showstack(stack s);
};


void showstack(stack s){
	for(int i=0; i<s.tos; i++){
		cout<<s.stck[i]<<" ";
	}
	cout<<endl;
}

void stack::init(){
	tos = 0;
}

void stack::push(char ch){
	if(tos==SIZE){
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

stack loadstack();
stack loadstack(int upper);

int main(){
	stack s1,s2;
	s1.init();
	s1 = loadstack(1);
	showstack(s1);
	s2.init();
	s2 = loadstack();
	showstack(s2);
	return 0;
}

stack loadstack(){
	stack s;
	s.init();
	for(char ch='a'; ch<='z'; ch++){ 
		s.push(ch);
	}
	return s;
}

stack loadstack(int upper){
	stack s;
	s.init();
	if (upper == 1){
		for(char ch='A'; ch<='Z'; ch++){ 
			s.push(ch);
		}
	}
	else {
		for(char ch='a'; ch<='z'; ch++){ 
			s.push(ch);
		}
	}
	return s;
}

