#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 1000
#define M 10000000

typedef struct Nameval Nameval;
struct Nameval{
	int value;
	Nameval *left;
	Nameval *right;
};

Nameval *create(int n){
  Nameval *newp =(Nameval*)malloc(sizeof(Nameval));
  newp->value = n;
  newp->left = NULL;
  newp->right = NULL;
  return newp;
}

Nameval *insert(Nameval *treep, int num){
  if(treep == NULL){
    treep = create(num);
  }
  else if(treep->value >= num)
    treep->left = insert(treep->left, num);
  else 
    treep->right = insert(treep->right, num);
  return treep;
}

/*lookup*/
Nameval *lookup(Nameval *treep, int n){
	if(treep == NULL)
		return NULL;
	int cmp = treep->value - n;
	if(cmp== 0){
		return treep;
	}
	else if(cmp<0){
		return lookup(treep->left, n);
	}
	else {
		return lookup(treep->right, n);
	}
}

/*nrlookup*/
Nameval *nrlookup(Nameval *treep, int n){
	while(treep!=NULL){
		int cmp = treep->value - n;
		if(cmp == 0)
			return treep;
		else if(cmp<0)
			treep = treep->left;
		else 
			treep = treep->right;
	}
	return NULL;
}

int main(){
	int arr[N];
	clock_t begin,end;
	Nameval *treep=NULL;
	for(int i=0;i<N;i++){
		arr[i] = i;
	}
	for(int i=0;i<N;i++){
		treep = insert(treep,i);
	}
	begin = clock();
	for(int j=0;j<M;j++){
		for(int i=0; i<N; i++){
			lookup(treep, arr[i]);
		}
	}
	end = clock();
	printf("Lookup: %.8f seconds\n",(double)(end-begin)/CLOCKS_PER_SEC);
	begin = clock();

	for(int j=0;j<M;j++){
		for(int i=0;i<N;i++){
			nrlookup(treep,arr[i]);
		}
	}
	end = clock();
	printf("Nrlookup: %.8f seconds\n",(double)(end-begin)/CLOCKS_PER_SEC);
	return 0;
}