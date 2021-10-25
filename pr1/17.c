#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Nameval Nameval;
struct Nameval{
	char *name;
	int value;
	Nameval *left;
	Nameval *right;
};

Nameval *insert(Nameval *treep, Nameval *newp){
	if(treep == NULL)
		return newp;
	int cmp = strcmp(newp->name, treep->name);
	if(cmp == 0)
		printf("insert: duplicate entry %s ignored", newp->name);
	else if (cmp < 0)
		treep->left = insert(treep->left, newp);
	else 
		treep->right = insert(treep->right, newp);
	return treep;
}

Nameval *lookup(Nameval *treep, char *name){
	if(treep == NULL){
		return NULL;
	}
	int cmp = strcmp(name, treep->name);
	if(cmp == 0){
		return treep;
	}else if(cmp<0){
		return lookup(treep->left, name);
	}else{
		return lookup(treep->right, name);
	}
}

Nameval *nrlookup(Nameval *treep, char *name){
	while(treep != NULL){
		int cmp = strcmp(name, treep->name);
		if(cmp == 0){
			return treep;
		}else if(cmp<0){
			treep = treep->left;
		}else{
			treep = treep->right;
		}
	}
	return NULL;
}

void applyinorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg){
	if(treep == NULL)
		return;
	applyinorder(treep->left, fn, arg);
	(*fn)(treep,arg);
	applyinorder(treep->right, fn, arg);

}

void applypostorder(Nameval *treep, void (*fn)(Nameval *, void *), void *arg){
	if(treep == NULL){
		return;
	}
	applypostorder(treep->left, fn, arg);
	applypostorder(treep->right, fn, arg);
	(*fn)(treep, arg);
}

void printnv(Nameval *p, void *arg){
	char *fmt;
	fmt = (char*)arg;
	printf(fmt, p->name, p->value);
}

int checking(int *mas,  int n){
   int i;
  for (i = 1; i < n; i++) {
  	   	printf("MAS:%d\n",mas[i]);
    if (mas[i] < mas[i - 1])
      return 0;
  }
  return 1;
}

int applyinorder_test(Nameval *treep, void(*fn)(Nameval*, void*, int *mas), void *arg, int *mas,int check){
	int i = 0, j=0;
	if(treep == NULL)
		return 0;
	applyinorder_test(treep->left,fn,arg,mas,check);
	(*fn)(treep, arg,mas);
	mas[i]=treep->value;
	applyinorder_test(treep->right, fn, arg,mas,check);
	i++;
	i=checking(mas,j);
	if(i == 0) check = 0;
	else check = 1;
	return check;
}

int applypostorder_test(Nameval *treep, void(*fn)(Nameval*, void*, int *mas), void *arg, int *mas,int check){
	int i = 0, j=0;
	if(treep == NULL)
		return 0;
	applypostorder_test(treep->left,fn,arg,mas,check);
	applypostorder_test(treep->right, fn, arg,mas,check);
	(*fn)(treep, arg,mas);
	mas[i]=treep->value;
	i++;
	i=checking(mas,j);
	if(i == 0) check = 0;
	else check = 1;
	return check;
}

int main(void) {
	Nameval *tree = NULL;
	struct Nameval newv = {.name = "Andy", .value = 12};
	int mas[20], t = 0, t1, t2;
	tree = insert(tree, &newv);
	tree = insert(tree, &(struct Nameval){.name = "Billy", .value = 18 });
	tree = insert(tree, &(struct Nameval){.name = "Emma", .value = 11});

	tree = insert(tree, &(struct Nameval){.name = "Norman", .value = 13});
	tree = insert(tree, &(struct Nameval){.name = "Rey", .value = 17});	
	t1 = applyinorder_test(tree,printnv,"%s %d\n", mas,t);
	if(t1 == 0) printf("Applyinorder работает некорректно\n\n");
		else printf("Applyinorder работает корректно\n\n");
	t2 = applypostorder_test(tree,printnv,"%s %d\n", mas,t);
	if(t2 == 0) printf("Applypostorder работает некорректно");
		else printf("Applypostorder работает корректно");

	return 0;
}