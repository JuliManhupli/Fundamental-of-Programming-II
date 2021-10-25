#include<stdio.h>
#include<stdlib.h>
int count;
typedef struct Nameval Nameval;

struct Nameval {
	char *name;
	int value;
	Nameval *next;
};

Nameval *newitem(char *name, int value){
	Nameval *newp;
	newp=(Nameval *) malloc(sizeof(Nameval));
	newp ->name = name;
	newp ->value = value;
	newp ->next = NULL;
	count++;
	return newp;
}

Nameval *addfront(Nameval *listp, Nameval *newp){
	newp ->next = listp;
	return newp;
	
}

Nameval *addend(Nameval *listp, Nameval *newp) {
	if(listp == NULL) return newp;
	Nameval *p;
	for(p=listp;p->next!=NULL;p=p->next);
	p->next=newp;
 	return listp;

}

Nameval *reverse_list_recursive(Nameval* list){
	Nameval *q = NULL;
	if(list->next != NULL){
		q = reverse_list_recursive(list->next);
	}
	list->next = NULL;
	q = addend(q, list);
	return q;

}

Nameval *reverse_list_iterative(Nameval* list){
	Nameval *q= NULL, *p = NULL;
	while(list != NULL){
		p = list->next;
		list->next = NULL;
		q = addfront(q, list);
		list = p;
	}
	return q;

}

void print(Nameval *listp, int count){
	printf("\n");
	for(int i=0; i<count;i++){
		printf("%s %d\n", listp->name, listp->value);
		listp=listp->next;
	}
}

int main(void) {
	Nameval *nvlist = NULL;
	nvlist = addfront(nvlist, newitem("data1", 10));
	Nameval *item = newitem("data2", 45);
	nvlist = addend(nvlist, item);
	Nameval *item1 = newitem("data0", 2);
	nvlist = addfront(nvlist, item1);
	Nameval *item2 = newitem("data3", 50);
	nvlist = addend(nvlist, item2);
	print(nvlist, count);
	nvlist = reverse_list_recursive(nvlist);
	print(nvlist, count);
	nvlist = reverse_list_iterative(nvlist);
	print(nvlist, count);
	return 0;
}