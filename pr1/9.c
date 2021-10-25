#include<stdio.h>
#include<stdlib.h>
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

int main(void) {
	Nameval *nvlist = NULL;
	Nameval *nvlist2 = NULL;
	Nameval *nvlist3 = NULL;
	Nameval *nvlist4 = NULL;
	Nameval *nvlist5 = NULL;
	nvlist = addfront(nvlist, newitem("data1", 10));
	Nameval *item = newitem("data2", 45);
	nvlist = addend(nvlist, item);
	Nameval *item1 = newitem("data0", 2);
	nvlist = addfront(nvlist, item1);
	Nameval *item2 = newitem("data3", 50);
	nvlist = addend(nvlist, item2);
	print(nvlist);
	printf("Копирование\n");
	nvlist2 = copy(nvlist);
	print(nvlist2);
	printf("Слияние\n");
	nvlist3 = merger(nvlist, nvlist2);
	print(nvlist3);
	printf("Разбиение\n");
	splitting(nvlist3, nvlist, nvlist2, 4);
	print(nvlist);
	print(nvlist2);
	printf("Вставка перед 4 елементом\n");
	nvlist4=insert_before(nvlist3,newitem("*data5", 0),4);
	print(nvlist4);
	printf("Вставка после 4 елемента\n");
	nvlist5=insert_before(nvlist3,newitem("**data6", 21),4);
	print(nvlist5);
	return 0;
}

