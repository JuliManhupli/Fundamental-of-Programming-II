#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char *p;
	p = new char[50];
	strcpy(p, "This is a test");
	cout << p;
	delete[] p;
	return 0;
}