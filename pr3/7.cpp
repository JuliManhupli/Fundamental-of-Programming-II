#include<iostream>
using namespace std;

class Dice{
	int t;
public:
	void roll();
};

void Dice::roll(){
	for (int i; i<4; i++){
		t=rand()%6+1;
		cout<<t<<" ";	
	}
	cout<<endl;
}

int main(){
	Dice a;
	for(int i=1; i<6; i++){
		cout<<"Бросок "<<i<<endl;
		a.roll();

	}
}
