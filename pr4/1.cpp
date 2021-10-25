#include <iostream>
using namespace std;

class letters {
	char ch;
public:
	letters(char c) {ch = c;}
	char get_ch() {return ch;}
};

int main(){
	letters mass[10]= {'A', 'B', 'C', 'D', 'E','F', 'G', 'H','I', 'J'};
	for(int i; i<10; i++){
		cout<<mass[i].get_ch()<<' ';
	}
	return 0;
}