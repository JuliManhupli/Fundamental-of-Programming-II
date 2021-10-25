#include<iostream>
#include<strstream>
using namespace std;

int main(){
	double c;
	char buf[] = "123.23";
	istrstream istr(buf);
	istr >> c;
	cout << c << endl;
	return 0;
}

