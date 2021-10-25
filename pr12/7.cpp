#include<iostream>
#include<cstdlib>
using namespace std;
class  DataStruct{
public:
	 DataStruct *head;
	 DataStruct *tail;
	 DataStruct *next;
	int num;
	 DataStruct(){head = tail = next = NULL;}
	virtual void store(int i) = 0;
	virtual int retrieve() = 0;
	virtual ~ DataStruct(){
		DataStruct *tmp;
		for(;head;head = tmp){
			tmp = head->next;
			delete head;
		}
	}
};

class queue : public  DataStruct{
public:
	void store(int i);
	int retrieve();
};

void queue::store(int i){
	 DataStruct *item;
	item = new queue;
	if(!item){
		cout<<"Allocation error.\n";
		exit(1);
	}
	item->num = i;
	if(tail) tail->next = item;
	tail = item;
	item->next =NULL;
	if(!head) head = tail;
}

int queue::retrieve(){
	int i;
	 DataStruct *p;
	if(!head){
		cout<<" DataStruct empty.\n";
		return 0;
	}
	i = head->num;
	p = head;
	head = head->next;
	delete p;
	return i;
}

class stack : public  DataStruct{
public:
	void store(int i);
	int retrieve();
};

void stack::store(int i){
	 DataStruct *item;
	item = new stack;
	if(!item){
		cout<<"Allocation error.\n";
		exit(1);
	}
	item->num = i;
	if(head) item->next = head;
	head = item;
	if(!tail) tail = head;
}

int stack::retrieve(){
	int i;
	 DataStruct *p;
	if(!head){
		cout<<" DataStruct empty.\n";
		return 0;
	}
	i = head->num;
	p = head;
	head = head->next;
	delete p;
	return i;
}

DataStruct *DataStructFactory(char what) {
	DataStruct *p;
	if(what == 's') p = new(nothrow) stack;
	else if (what == 'q') p = new(nothrow) queue;
	if (!p) {
		cout << "Allocation error!";
		return NULL;
	}
	return p;
}

int main(){
	DataStruct *p;
	p = DataStructFactory('q');
	p->store(1);
	p->store(2);
	p->store(3);
	cout<<"Queue: ";
	cout<<p->retrieve();
	cout<<p->retrieve();
	cout<<p->retrieve();
	cout<<'\n';

	p = DataStructFactory('s');
	p->store(1);
	p->store(2);
	p->store(3);
	cout<<"Stack: ";
	cout<<p->retrieve();
	cout<<p->retrieve();
	cout<<p->retrieve();
	cout<<'\n';
	return 0;
}
