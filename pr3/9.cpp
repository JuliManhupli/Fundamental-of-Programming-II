#include<iostream>
using namespace std;

class who{
	char x;
public:
	who(char a);
	~who();
};

who::who(char a){
	x=a;
	cout<<"Construction who #"<<x<<endl;
}

who::~who(){
	cout<<"Destroying who #"<<x<<endl;
}

who make_who(char c){
	who h(c);
	return h;
}

int main(){
	who w('q');
	w = make_who('w');
	return 0;
}