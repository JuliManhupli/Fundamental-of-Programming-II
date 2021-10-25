#include<stdio.h>
#include<stdlib.h>

struct list {
  int field;
  struct list *ptr;
};

struct queue {
  struct list *head;
  struct list *tail;
};

void init(struct queue *q) {
  q->head = 0;
  q->tail = 0;
}

struct list *init1(int a){ 
  struct list *lst;
  lst = (struct list*) malloc(sizeof(struct list));
  lst->field = a;
  lst->ptr = NULL;
  return(lst);
}

struct list *addelem(struct list *lst, int number){
  struct list *temp, *p;
  temp = (struct list*) malloc(sizeof(struct list));
  p = lst->ptr; 
  lst->ptr = temp; 
  temp->field = number; 
  temp->ptr = p; 
  return(temp);
}

void insert(struct queue *q, int x) {
  if((q->tail==0) && (q->head==0)) {
    q->tail = init1(x);
    q->head = q->tail;
  } else
    q->tail = addelem(q->tail, x);
}

void print(struct queue *q) {
  struct list *h;
  for(h = q->head; h!= NULL; h=h->ptr)
    printf("%d  " ,h->field);
  return;
}

int main(){
  struct queue *q;
  q = (struct queue*)malloc(sizeof(struct queue*));
  init(q);
  for(int i = 0;i<8;i++){
    insert(q,i);
  }
  print(q); 
  return 0;
}