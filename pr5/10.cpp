#include<iostream>
#include<cstring>
using namespace std;

void reverse(char* str, int count = 0);

int main() {
	char s1[] = "This is a test.",
		s2[] = "I hate any programming!";
	cout << s1 << endl;
	cout << "Reverse без параметра\n";
	reverse(s1);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << "Reverse с count = 5\n";
	reverse(s2, 5);
	cout << s2 << endl;
	return 0;
}

void reverse(char* str, int count) {
	char t;
	int i, j;
	if (count == 0) { 
		count = strlen(str) - 1; 
	}
	for (i = 0, j = count - 1; i < j; i++, j--) {
		t = str[i];
		str[i] = str[j];
		str[j] = t;
	}
}