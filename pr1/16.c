#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 100000
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

Nameval *insert(Nameval *treep, Nameval *newp){
  if(treep == NULL){
    return newp;
  }
   if(newp->value < treep->value)
    treep->left = insert(treep->left, newp);
  else 
    treep->right = insert(treep->right, newp);

  return treep;
}

void helpfunc(const Nameval *treep, int **mas){
  if(treep == NULL)
    return;
  helpfunc(treep->left,mas);
  **mas = treep->value;
  (*mas)++;
  helpfunc(treep->right,mas);
}

void treesort(int mas[], unsigned int n){
  Nameval *treep;
  unsigned int i;
  treep = NULL;
  for(i=0;i<n;i++)
    treep = insert(treep, create(mas[i]));
  helpfunc(treep,&mas);
}

 void swap(int mas[], int i, int j){
  int tmp;
  tmp = mas[i];
  mas[i] = mas[j];
  mas[j] = tmp;
}

void quicksort(int mas[], unsigned int n)
{
  int i, last;

  if (n <= 1) 
    return;
  swap(mas, 0, rand() % n); 
   last = 0;
  for (i = 1; i < n; i++) 
    if (mas[i] < mas[0])
      swap(mas, ++last, i);
  swap(mas, 0, last); 
  quicksort(mas, last); 
  quicksort(mas+last+1, n-last-1);  
}

int helping(const void *a, const void *b){
  if (*((int *) a) < *((int *) b))
    return -1;
  else if (*((int *) a) == *((int *) b))
    return 0;
  else
    return 1;
}


void library_quicksort(int mas[], unsigned int n){
  qsort(mas, n, sizeof(mas[0]), helping);
}

int main(){
  int a[N];
  clock_t begin, end;
  unsigned int i;

  srand(time(0));
  for(i=0; i<N; i++){
    a[i] = rand()%(122 - 97 +1) + 97;
  }

  begin = clock();
  treesort(a, N);
  end = clock();
  printf("Время treesort: %.8f\n", (double) (end-begin)/CLOCKS_PER_SEC);

  srand(time(0));
  for(i=0;i<N;i++){
    a[i] = rand()%(122 - 97 +1) + 97;
  }

  begin = clock();
  quicksort(a, N);
  end = clock();
  printf("Время quicksort: %.8f\n", (double) (end-begin)/CLOCKS_PER_SEC);

  srand(time(0));
  for(i=0;i<N;i++){
    a[i] = rand()%(122 - 97 +1) + 97;
  }

  begin = clock();
  library_quicksort(a, N);
  end = clock();
  printf("Время library_quicksort: %.8f\n", (double) (end-begin)/CLOCKS_PER_SEC);
  return 0;
}