#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
#define SIZE 40
class inventory{
	char item[SIZE];
	int onhand;
	double cost;
public:
	inventory(const char *i, int o, double c) {
		strcpy(item, i);
		onhand = o;
		cost = c;
	}
	void store(fstream &stream);
	void retrieve(fstream &stream);
	friend ostream &operator <<(ostream &stream, inventory obj);
	friend istream &operator >>(istream &stream, inventory &obj);
};

void inventory::store(fstream &stream) {
	stream << item << ' ' << onhand << ' ' << cost << "\n";
}
void inventory::retrieve(fstream &stream) {
	stream >> item >> onhand >> cost;
}

ostream &operator <<(ostream &stream, inventory obj) {
	stream << obj.item << ": " << obj.onhand;
	stream << " on hand at $" << obj.cost << '\n';
	return stream;
}

istream &operator >>(istream &stream, inventory &obj) {
	cout << "Enter item name: ";
	stream >> obj.item;
	cout << "\nEnter number on hand: ";
	stream >> obj.onhand;
	cout << "\n Enter cost:  ";
	stream >> obj.cost;
	return stream;
}

int main(){

	fstream in("inventory.txt", ios::out | ios::binary);
	inventory obj1("hammer", 4, 12.55);
	inventory obj2("drill", 5, 5.22);
	obj1.store(in);
	obj2.store(in);
	in.close();
	in.open("inventory.txt", ios::in | ios::binary);
	obj1.retrieve(in);
	cout<<obj1;
	obj2.retrieve(in);
	cout<<obj2;
	in.close();
	return 0;
}
