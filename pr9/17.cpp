#include<iostream>
using namespace std;
ostream &manipulator(ostream &stream){
	stream << "\t\t\t";
	stream.width(20);
	return stream;
}

int main(){
	cout << manipulator << "Hello world" <<endl;
	return 0;
}
