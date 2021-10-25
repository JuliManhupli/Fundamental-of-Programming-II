#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class account{
	int custnum;
	char name[80];
	double balance;
public:
	account(int c,const char *n, double b){
		custnum = c;
		strcpy(name, n);
		balance = b;
	}
	friend ostream &operator <<(ostream &stream, account obj);
};

ostream &operator <<(ostream &stream, account obj){
	stream << "Custnum: " << obj.custnum << endl;
	stream << "Name: " << obj.name << endl;
	stream << "Balance: " << obj.balance << endl;
	return stream;
}

int main(){
	account obj1(1, "Petro Siplusenko", 2);
	ofstream fout("account.txt");
	if(!fout){
		cout << "Cannot open file\n";
		return 1;
	}
	fout << obj1;
	fout.close();

	ifstream fin("account.txt");
	if(!fin){
		cout << "Cannot open input file.\n";
		return 1;
	}
	char ch;
	fin.unsetf(ios::skipws);
	while (!fin.eof()) {
		fin >> ch;
		cout << ch;
	}
	fin.close();
	return 0;
}
