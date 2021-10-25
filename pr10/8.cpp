#include<iostream>
#include<cstdlib>
using namespace std;
class list{
public:
	list *head;
	list *tail;
	list *next;
	int num;
	list(){head = tail = next = NULL;}
	virtual void store(int i) = 0;
	virtual int retrieve() = 0;
	virtual ~list(){
		list *tmp_list;
		for(;head;head = tmp_list){
			tmp_list = head->next;
			delete head;
		}
	}
};

class queue : public list{
public:
	void store(int i);
	int retrieve();
};

void queue::store(int i){
	list *item;
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
	list *p;
	if(!head){
		cout<<"List empty.\n";
		return 0;
	}
	i = head->num;
	p = head;
	head = head->next;
	delete p;
	return i;
}

class stack : public list{
public:
	void store(int i);
	int retrieve();
};

void stack::store(int i){
	list *item;
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
	list *p;
	if(!head){
		cout<<"List empty.\n";
		return 0;
	}
	i = head->num;
	p = head;
	head = head->next;
	delete p;
	return i;
}

class sorted : public list{
public:
	void store(int i);
	int retrieve();
};

void sorted::store(int i){
	list *item;
	list *ptr1, *ptr2;
	item = new sorted;
	if(!item){
		cout<<"Allocation error.\n";
		exit(1);
	}
	item->num = i;
	ptr1 = head;
	ptr2 = NULL;
	while(ptr1){
		if(ptr1->num>i) {
			item->next = ptr1;
			if(ptr2) { 
				ptr2->next = item;
			}
			if(ptr1==head) { 
				head = item; 
			}
			break;
		}
		ptr2 = ptr1;
		ptr1 = ptr1->next;
	}
	if(!ptr1) {
		if(tail) { 
			tail->next = item;
		}
		tail = item;
		item->next = NULL;
	}
	if(!head) {
		head = item;
	}
}

int sorted::retrieve(){
	int i;
	list *p;
	if(!head){
		cout<<"Is empty\n";
		return 0;
	}
	i=head->num;
	p=head;
	head = head->next;
	delete p;
	return i;
}



int main(){
	list *p;
	queue q_ob;
	p = &q_ob;
	p->store(1);
	p->store(2);
	p->store(3);
	cout<<"Queue: ";
	cout<<p->retrieve();
	cout<<p->retrieve();
	cout<<p->retrieve();
	cout<<'\n';

	stack s_ob;
	p = &s_ob;
	p->store(1);
	p->store(2);
	p->store(3);
	cout<<"Stack: ";
	cout<<p->retrieve();
	cout<<p->retrieve();
	cout<<p->retrieve();
	cout<<'\n';

	sorted sort_ob;
	p = &sort_ob;
	p->store(2);
	p->store(3);
	p->store(1);
	cout<<"Sorted: ";
	cout<<p->retrieve();
	cout<<p->retrieve();
	cout<<p->retrieve();
	cout<<'\n';
/*
    list* p;
    queue q_ob;
    stack s_ob;
    sorted srt_ob;
    char ch;
    for (int i = 0; i < 10; i++) {
        cout << "Stack or Queue? (S/Q/SO):";
        cin >> ch;
        ch = tolower(ch);
        if (ch == 'q')
            p = &q_ob;
        else 
        	if (ch == 's')
            p = &s_ob;
        else
            p = &srt_ob;
        p->store(i);
    }
    cout << "Enter T to terminate\n";
    for (;;) {
        cout << "Remove from Stack or Queue? (S/Q):";
        cin >> ch;
        ch = tolower(ch);
        if (ch == 't')
            break;
        if (ch == 'q')
            p = &q_ob;
        else 
        	if (ch == 's')
            p = &s_ob;
        else
            p = &srt_ob;
        cout << p->retrieve() << '\n';
    }
    cout << '\n';*/
	return 0;
}

