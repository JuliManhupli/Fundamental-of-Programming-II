#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 100000
#define NHASH_B 9999
#define NHASH_S 99


typedef struct Nameval Nameval;
struct Nameval {
	char *name;
	int value;
	Nameval *next;
};
enum{MULTIPLIER = 31};
Nameval *symtab_b[NHASH_B];
Nameval *symtab_s[NHASH_S];

unsigned int hash_b(char *str){
	unsigned int h = 0;
	unsigned char *p;
	for(p = (unsigned char *) str; *p != '\0'; p++)
		h = MULTIPLIER*h + *p;
	return h % NHASH_B;
}

unsigned int hash_s(char *str){
	unsigned int h = 0;
	unsigned char *p;
	for(p = (unsigned char *) str; *p != '\0'; p++)
		h = MULTIPLIER*h + *p;
	return h % NHASH_S;
}

Nameval *lookup_b(char *name, int create, int value){
	Nameval *sym;
	int h = hash_b(name);
	for(sym = symtab_b[h];sym!=NULL;sym=sym->next)
		if(strcmp(name, sym->name) == 0)
			return sym;
	if(create){
		sym = (Nameval *) malloc(sizeof(Nameval));
		sym->name = name;
		sym->value = value;
		sym->next = symtab_b[h];
		symtab_b[h] = sym;
	}
	return sym;
}

Nameval *lookup_s(char *name, int create, int value){
	Nameval *sym;
	int h = hash_s(name);
	for(sym = symtab_s[h];sym!=NULL;sym=sym->next)
		if(strcmp(name, sym->name) == 0)
			return sym;
	if(create){
		sym = (Nameval *) malloc(sizeof(Nameval));
		sym->name = name;
		sym->value = value;
		sym->next = symtab_s[h];
		symtab_s[h] = sym;
	}
	return sym;
}

char *newitem(){
	char *a;
	srand(time(NULL));
	int lower = 97, upper = 122; 
	a = (char *) malloc(10);
	for(int i=0;i<10;i++){
		a[i] = (char)(rand()%(upper - lower +1) + lower);
	}	
	free(a);
	return a;
}



int main(void){
	Nameval *big, *small;
	int i;
	char *a[N];
	clock_t begin, end;

	for(i=0;i<N;i++){
		a[i] = newitem();
		big = lookup_b(a[i], 1, 1);
		small = lookup_s(a[i], 1, 1);
	}

	begin = clock();
	for(int i = 100; i<N;i++){
		big = lookup_b(a[i],0,1);
	}
	end = clock();
	printf("Big Hash Table %.8f seconds\n",(double)(end-begin)/CLOCKS_PER_SEC);

	begin = clock();
	for(int i = 100; i<N;i++){
		small = lookup_s(a[i],0,1);
	}
	end = clock();
	printf("Small Hash Table %.8f seconds\n",(double)(end-begin)/CLOCKS_PER_SEC);


	return 0;
}