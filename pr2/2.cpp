#include<iostream>

using namespace std;

int main(){
	float ft = 3.28084, in = 12, m;
	cout<<"Введіть кількість метрів (поки не дорівнює 0)\n";
	do{
		cin>>m;
		cout<<"Фути = "<<m*ft<<" "<<"Дюйми = "<<m*ft*in<<"\n";
	} while(m != 0);
	return 0;

}