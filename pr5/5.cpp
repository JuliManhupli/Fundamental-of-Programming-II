#include<iostream>
#include<cstdlib>
using namespace std;

long mystrol(const char *start, char **end, int base = 10) {
	return strtol(start, end, base);
}

int main() {
	const char *str = "2543684287";
	long c = mystrol(str, NULL);
	cout << c << endl;
	return 0;
}
