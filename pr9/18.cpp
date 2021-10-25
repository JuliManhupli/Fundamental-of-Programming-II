#include <iostream>
#include <cctype>
using namespace std;
istream &findalpha(istream &stream){
	char ch;
	while(!isalpha(ch)){
		stream.get(ch);
	}
	stream.putback(ch);
	return stream;
}

int main(){
	char str[100];
	cin >> findalpha >> str;
	cout << str <<endl;
	return 0;
}
