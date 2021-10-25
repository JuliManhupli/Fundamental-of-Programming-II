#include<iostream>
#include<strstream>
using namespace std;

int main(){
	char ch;
	char buf1[] = "I hate C++";
	char buf2[255];
	istrstream istr(buf1);
	ostrstream ostr (buf2, sizeof buf2);

	while(!istr.eof()){
		istr.get(ch);
		if (!istr.eof()){
			ostr.put(ch);
		} 
	}
	ostr.put('\0');
	cout << "String: " << buf1 << endl;
	cout << "Copy: " << buf2 << endl;
	return 0;
}
