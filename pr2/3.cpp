#include<iostream>

using namespace std;

int main() {
	int a, b, d, min;
	cout << "Enter two numbers:";
	cin >> a >> b;
	if (a > b)
		min = b;
	else min = a;
	for (d = 2; d < min; d++)
		if (((a % d) == 0) && ((b % d) == 0))
			break;
	if (d == min) {
		cout << "No common denomininators\n";
		return 0;
	}
	cout << "The lowest common denominator is " << d;
	return 0;
}