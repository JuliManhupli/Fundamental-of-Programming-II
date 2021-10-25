#include<iostream>
using namespace std;
class date {
	char d[9]; // store date as string : mm/dd/yy
public:
	friend ostream &operator <<(ostream &stream, date obj);
	friend istream &operator >>(istream &stream, date &obj);
};

ostream &operator <<(ostream &stream, date obj){
	stream << "Дата: " << obj.d << endl;	
	return stream; 
}

istream &operator >>(istream &stream, date &obj){
	cout << "Введите дату: ";
	stream >> obj.d;
	return stream; 
}

int main() {
	date obj;
	cin >> obj;
	cout << obj;
	return 0;
}