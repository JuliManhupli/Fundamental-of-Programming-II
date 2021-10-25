#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;
int main(){
	ifstream fin("file.txt");
	if(!fin){
		cout<<"Can't open input file.\n";
		return 1;
	}
	ofstream fout("filecopy.txt");
	if(!fout){
		cout<<"Can't open output file.\n";
		return 1;
	}
	char ch;
	while(!fin.eof()){
		ch = fin.get();
		if(fin.eof()){
			break;
		}
		if(islower(ch)) {
			ch = toupper(ch);
		}
		else {
			ch = tolower(ch);
		}
		fout.put(ch);
		cout << ch;
	}
	cout << endl;
	fin.close();
	fout.close();
	return 0;
}
