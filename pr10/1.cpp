#include<iostream>
using namespace std;
ostream &sethex(ostream &stream){
	stream.unsetf(ios::dec);
	stream.setf(ios::scientific | ios::uppercase);
	return stream;	
}

int main(){
	cout << sethex << 1420.124 << endl;
	return 0;
}
