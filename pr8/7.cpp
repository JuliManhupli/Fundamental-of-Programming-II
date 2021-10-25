//9.5
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
	double x;
	cout.precision(5);
	cout << "     x         lgx         lnx" << endl;
	for (x = 2.0; x < 101.0; x++) {
		cout << setw(10) << x << " ";
		cout << setw(10) << log(x) << " ";
		cout << setw(10) << log10(x) << endl;
	}
	return 0;
}
/*
//9.6
#include <iostream>
#include <cstring>
#include<iomanip>
using namespace std;

void center(const char *str) {
	int len = strlen(str) / 2;
	cout << setw(len+40) << str << endl;
}

int main() {
	center("Hello world");
	center("This is a test.");
	return 0;
}*/