#include<stdio.h>
#include<stdlib.h>

typedef struct Tree Tree;
struct Tree{
	int value;
	Tree *left;
	Tree *right;
};

Tree *newitem(int n){
  Tree *newp =(Tree*)malloc(sizeof(Tree));
  newp->value = n;
  newp->left = NULL;
  newp->right = NULL;
  return newp;
}

Tree *insert(Tree *treep, int num){
  if(treep == NULL){
    treep = newitem(num);
  }
  else if(treep->value >= num)
    treep->left = insert(treep->left, num);
  else 
    treep->right = insert(treep->right, num);
  return treep;
}

int max(int a, int b){
	if(a>=b) return a;
	else return b;
}

int min(int a, int b){
	if(a<=b) return a;
	else return b;
}

int visota(Tree *treep){
	int i=0;
	if(treep == NULL)
		return 0;
	else 
		i = max(visota(treep->left),visota(treep->right))+1;
	return i;
}

int min_visota(Tree *treep){
	int i=0;
	if(treep == NULL)
		return 0;
	else {
		i = min(visota(treep->left),visota(treep->right))+1;
	}
	return i;
}

int func(Tree *treep){
	int otvet;
		if(treep!= NULL){
			if(visota(treep) - min_visota(treep)>1)
				otvet = 0;
			else
				otvet=1;
		}
	return otvet;
}

int main(void){
	int version1[15] = {6,1,11,2,7,4,13,9,15,10,3,5,8,12,14};
	int version2[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	Tree* treep1 = NULL;
	Tree* treep2 = NULL;
	for(int i=0;i<15;i++)
		treep1 = insert(treep1,version1[i]);
	if(func(treep1) == 0)
		printf("В первом варианте дерево не является сбалансированным\n");
	else 
		printf("В первом варианте дерево сбалансированное\n");
	for(int i=0;i<15;i++)
		treep2 = insert(treep2,version2[i]);
	if(func(treep2) == 0)
		printf("Во втором варианте дерево не является сбалансированным\n");
	else 
		printf("Во втором варианте дерево сбалансированное\n");
	return 0;
}