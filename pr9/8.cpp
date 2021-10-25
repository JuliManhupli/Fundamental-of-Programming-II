#include<iostream>
#include<fstream>
using namespace std;
int main(){
	ofstream fout("phones.txt");
	if(!fout){
		cout<<"Can't open output file\n";
		return 1;
	}
	fout<<"Ivan Tormozenko, +38067 415 5113\n";
	fout<<"Petro Siplusenko, +38068 212 5332\n";
	fout<<"Olena Kompailenko, +38050 202 54517\n";
	fout.close();

	ifstream fin("phones.txt");
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
