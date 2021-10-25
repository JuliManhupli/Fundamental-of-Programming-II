#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

void print(Nameval *listp){
	while(listp != NULL){
		printf("%s %d\n", listp->name, listp->value);
		listp=listp->next;
	}
	printf("\n");
}

void coolfun(Nameval *listp, 
			void(*fn)(Nameval*, void*), void *arg)
{
	for( ; listp != NULL; listp = listp ->next)
		(*fn)(listp, arg);
}

void inccounter(Nameval *p, void *arg)
{
	int *ip;

	ip = (int *) arg;
	(*ip)++;
}

//копирование 
Nameval *copy(Nameval *listp_copy){
	Nameval *listp2=NULL;
	while(listp_copy!=NULL){
		listp2 = addend(listp2,newitem(listp_copy->name, listp_copy->value));
		listp_copy=listp_copy->next;
	}
	return listp2;
}

//слияние
Nameval *merger(Nameval *listp_m1, Nameval *listp_m2){
	Nameval *listp3=NULL;
	while(listp_m1!=NULL){
		listp3 = addend(listp3,newitem(listp_m1->name, listp_m1->value));
		listp_m1=listp_m1->next;
	}
	while(listp_m2!=NULL){
		listp3 = addend(listp3,newitem(listp_m2->name, listp_m2->value));
		listp_m2=listp_m2->next;
	}
	return listp3;
}

//разбиение
void splitting(Nameval *listp, Nameval *list1, Nameval *list2, int n){
	Nameval *newlist = listp;
	for (int i = 1; i<n; i++){
		newlist = newlist->next;
	}
	*list2 = *(newlist->next);
	newlist->next = NULL;
	*list1 = *listp;
}

//вставка перед
Nameval *insert_before(Nameval *listp, Nameval *item, int n){
	Nameval *newlist = listp;
	Nameval *p;
	for(int i = 1; i<n-1; i++){
		newlist = newlist->next; 
	}
	p = addfront(newlist->next, item);
	newlist->next = p;
	return listp;
}

//вставка после
Nameval *insert_after(Nameval *listp, Nameval *item, int n){
	Nameval *newlist = listp;
	Nameval *p;
	for(int i = 1; i<n-1; i++){
		newlist = newlist->next; 
	}
	p = addfront(newlist->next, item);
	newlist->next = p;
	return listp;
}

void test_copy(){
	Nameval *listp = NULL,*c = NULL;
	int true=1;
	listp = addfront(listp, newitem("data1", 10));
	Nameval *item = newitem("data2", 45);
	listp = addend(listp, item);
	Nameval *item1 = newitem("data0", 2);
	listp = addfront(listp, item1);
	Nameval *item2 = newitem("data3", 50);
	listp = addend(listp, item2);
	c = copy(listp);
	while(listp!= NULL && c!= NULL){
		if(strcmp(listp->name,c->name)!=0 || listp->value != c->value)
			true = 0;
		listp = listp->next;
		c = c->next;
	}
	if(true == 0) printf("Функция copy работает некорректно\n"); 
		else printf("Функция copy работает корректно\n"); 
}

void merger_test(){
	Nameval *s1 = NULL,*s2 = NULL,*test;
	int t1=0,t2=0,t3=0,true=1;
	s1 = addfront(s1, newitem("data1", 10));
	s1 = addfront(s1, newitem("data2", 45));
	coolfun(s1, inccounter, &t1);
	s2 = addfront(s2, newitem("data3", 50));
	test = merger(s1,s2);
	coolfun(s2, inccounter, &t2);
	coolfun(test, inccounter, &t3);
	if(t3!=t1+t2) true =0;
	if(true == 0) 
		printf("Функция merger работает некорректно\n"); 
		else printf("Функция merger работает корректно\n"); 
}

int main(void) {
	test_copy();
	merger_test();
	return 0;
}