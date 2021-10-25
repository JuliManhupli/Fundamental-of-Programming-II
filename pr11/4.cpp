#include<iostream>
using namespace std;
template <class X> class Input {
public:
	X n;
	Input(const char *str, X min, X max) {
		do {
			cout << str;
			cin >> n;
		} while (n<min || n>max);
	};
};

int main() {
	Input<int> obj1("Введите переменную типа int от 1 до 5: ", 1, 5);
	Input<double> obj2("Введите переменную типа double от 1 до 4.5: ", 1, 4.5);
	Input<char> obj3("Введите переменную типа char от 'b' до 'v': ", 'b', 'v');
	return 0;
}


