#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

void sleep(int n);
void sleep(const char *n);

int main(){
	sleep(10);
	cout<<"Sleep for 10 seconds\n";
	sleep("10");
	cout<<"Sleep for 10 seconds\n";
	return 0;
}

void sleep(int n){
	int sek = time(0);
	while(time(0) - sek != n){
		continue;
	}
}

void sleep(const char *n){
	int sek = time(0);
	while(time(0) - sek != atoi(n)){
		continue;
	}
}