#include<iostream>
using namespace std;

#define SIZE 100

class q_type{
	int queue[SIZE];
	int head, tail;
public:
	void init();	
	void q(int num);
	int qret();
};

void q_type::init(){
	head = tail = 0;
}

/* Занесение символа в очередь. */
void q_type::q(int num){
	if(tail+1 == head || (tail+1 == SIZE && !head)){
		cout<<"Черга повна \n";
		return;
	}
	queue[tail] = num;
	tail++;
	if(tail==SIZE) tail=0;
}

/* Получение символа из очереди. */
int q_type::qret(){
	if(head==SIZE) head = 0; /*установить на начало*/
	if(head==tail){
		cout<<"\nЧерга пуста ";
		return 0;
	}
	head++;
	return queue[head-1];
}

int main(){
	q_type iq;
	int i;
	iq.init();
	for(i=1;i<=SIZE;i++){
		iq.q(i);
	}
	cout<<"Черга: ";
	for(i=1;i<=SIZE;i++){
		cout<< iq.qret()<<" ";
	}
	return 0;
}