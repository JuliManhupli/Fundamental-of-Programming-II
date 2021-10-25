#include <iostream>
#include <cstring>
using namespace std;

void center(const char *str) {
	int len = strlen(str) / 2;
	cout.width(len + 40);
	cout << str << endl;
}

int main() {
	center("Hello world");
	center("This is a test.");
	return 0;
}



