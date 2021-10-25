#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Type_List Type_List;
struct Type_List{
  void *data;
  Type_List *next;
};

void print(Type_List *list){
  while(list != NULL){
    printf("%s\n", list->data);
    list = list->next;
  }
};

int main(void) {
  Type_List *list = malloc(sizeof(Type_List));
  Type_List *p = list->next;
  list->data = "Hello World";
  p->data = "Hello World";
  print(list);
  return 0;
}