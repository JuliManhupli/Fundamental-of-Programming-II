#include <iostream>
using namespace std;
class ft_to_cms {
	double feet;
	double cms;
public:
	void set(double f){
		feet = f;
		cms = f * 30.48;
	}
	friend ostream &operator <<(ostream &stream, ft_to_cms obj);
	friend istream &operator >>(istream &stream, ft_to_cms &obj);
};

ostream &operator <<(ostream &stream, ft_to_cms obj){
	cout << "Число футов ";
	stream << obj.feet << '\n';
	cout << "Число сантиметров ";
	stream << obj.cms << '\n';
	return stream;
}

istream &operator >>(istream &stream, ft_to_cms &obj){
	double f;
	cout << "Ввведите число футов ";
	stream >> f;
	obj.set(f);
	return stream;
}

int main() {
	ft_to_cms obj;
	cin >> obj;

	cout << obj;
	return 0;
}