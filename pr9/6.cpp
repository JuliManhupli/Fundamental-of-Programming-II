#include<iostream>
using namespace std;
#define N 100
istream &skipchar(istream &stream){
	char ch;
	for(int i=0; i<5; i++){
		stream >> ch;
	}
	return stream;
}

int main(){
	char str[N];
	cin >> skipchar >> str;
	cout << str << endl;
	return 0;
}

