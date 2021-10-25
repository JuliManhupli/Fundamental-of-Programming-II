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
	return newp;
}

Nameval *addfront(Nameval *listp, Nameval *newp){
	newp ->next = listp;
	count++;
	return newp;
	
}

Nameval *addend(Nameval *listp, Nameval *newp) {
	if(listp == NULL) return newp;
	Nameval *p;
	for(p=listp;p->next!=NULL;p=p->next);
	p->next=newp;
	count++;
 	return listp;

}

void coolfun(Nameval *listp, void (*fn)(Nameval*, void*), void *arg){
	while(listp != NULL){
		(*fn)(listp, arg);
		listp = listp->next;
	}

}

void inccounter (Nameval * p, void * arg) {
	int * ip;
	ip = (int *) arg;
	(*ip) ++;
}

void print(Nameval *listp, int count){
	for(int i=0; i<count;i++){
		printf("%s %d\n", listp->name, listp->value);
		listp=listp->next;
	}
}

int main(void) {
	int n=0;
	Nameval *nvlist = NULL;
	nvlist = addfront(nvlist, newitem("data1", 10));
	Nameval *item = newitem("data2", 45);
	nvlist = addend(nvlist, item);
	print(nvlist, count);
	coolfun(nvlist, inccounter, &n);
	printf("%d elements in nvlist\n", n);
	return 0;
}