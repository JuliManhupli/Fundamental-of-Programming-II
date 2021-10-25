#include<stdio.h>
#include<stdlib.h>
#include <string.h>

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
	return newp;
	
}

Nameval *addend(Nameval *listp, Nameval *newp) {
	if(listp == NULL) return newp;
	Nameval *p;
	for(p=listp;p->next!=NULL;p=p->next);
	p->next=newp;
 	return listp;

}

void freeall(Nameval *listp) {
	Nameval *next;
	for( ; listp != NULL; listp = next){
		next = listp->next;
		listp->name=NULL;
		free(listp->name);
		free(listp);
			
	}
}

void print(Nameval *listp){
	printf("\n");
	while(listp != NULL){
		printf("%s %d\n", listp->name, listp->value);
		listp=listp->next;
	}
}

Nameval *delitem(Nameval *listp, char *name){
	Nameval *p, *prev;
	prev = NULL;
	for(p = listp; p!=NULL;p = p->next){
		if(strcmp(name, p->name) == 0){
			if(prev == NULL)
				listp = p->next;
			else 
				prev->next = p->next;
			p->name = NULL;
			free(p->name);
			free(p);
			return listp;
		}
		prev = p;
	}
	printf("delitem: %s not in list", name);
	return NULL;
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
	print(nvlist);
	nvlist = delitem(nvlist, "data2");
	print(nvlist);
	freeall(nvlist);
	return 0;
}
