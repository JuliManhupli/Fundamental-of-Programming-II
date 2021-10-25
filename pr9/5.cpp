#include<iostream>
using namespace std;
ostream &sethex(ostream &stream){
	stream.unsetf(ios::dec);
	stream.setf(ios::hex | ios::uppercase | ios::showbase);
	return stream;	
}

ostream &reset(ostream &stream){
	stream.unsetf(ios::hex | ios::uppercase | ios::showbase);
	stream.setf(ios::dec);
	return stream;
}

int main(){
	cout << sethex << 10 << endl;
	cout << reset << 10 << endl;
	return 0;
}

// uppercase - все заглавные буквы
// showbase - индикатор основания системы счисления