#include <iostream>
#include <ctime>
using namespace std;
ostream &tdm(ostream &stream){
	time_t t = time(NULL);
	tm* timeinfo = localtime(&t);
	cout << asctime(timeinfo);
	return stream;
}

int main(){
	cout  << tdm;
	return 0;
}
