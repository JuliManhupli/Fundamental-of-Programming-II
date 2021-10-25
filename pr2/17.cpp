#include<iostream>
#include<ctime>
using namespace std;

class time_and_date{
	time_t it;
public:
	time_and_date(time_t time);
	void show();
};

time_and_date::time_and_date(time_t time){
	it = time;
}

void time_and_date::show(){
	cout<<ctime(&it);
}

int main(){
	time_t t;
	time(&t);
	time_and_date ob(t);
	ob.show();
	return 0;
}