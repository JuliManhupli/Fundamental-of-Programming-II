#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
  char *name;
  int value;
};

struct NVtab{
  int nval;
  int max;
  Nameval *nameval;
}nvtab;

enum {NVINIT = 1, NVGROW = 2};

int addname(Nameval newname);
int delname (char *name);

int main(void) {
  int curnum = addname((struct Nameval) { .name = "Andy", .value = 12 });
  printf("%d\n", curnum);
  curnum = addname((struct Nameval) { .name = "Billy", .value = 18 });
  printf("%d\n", curnum);
  curnum = addname((struct Nameval) { .name = "Rey", .value = 17 });
  printf("%d\n", curnum);
  curnum = addname((struct Nameval) { .name = "Norman", .value = 13 });
  printf("%d\n", curnum);
  curnum = addname((struct Nameval) { .name = "Emma", .value = 11 });
  printf("%d\n", curnum);
  curnum = delname("Norman");
  for (int i=0; i<nvtab.nval; i++){
    printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
  }
  
  return 0;
}

int addname(Nameval newname){
  Nameval *nvp;
  
  if (nvtab.nameval == NULL) {
    nvtab.nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
    if (nvtab.nameval == NULL){
      return -1;
    }
    
    nvtab.max = NVINIT;
    nvtab.nval = 0;
  }else if (nvtab.nval >= nvtab.max) {
    nvp = (Nameval *) realloc(nvtab.nameval, (NVGROW*nvtab.max)*sizeof(Nameval));
    if (nvp == NULL){
      return -1;
    }
    
    nvtab.max *= NVGROW;
    nvtab.nameval = nvp;
  }
  
  nvtab.nameval[nvtab.nval]=newname;
  return nvtab.nval++;
}

int delname (char *name){
  for (int i=0; i<nvtab.nval; i++){
    if (strcmp(nvtab.nameval[i].name, name) == 0){
      nvtab.nameval[i].name = NULL;
      nvtab.nameval[i].value = 0;
      nvtab.nameval[i].name=nvtab.nameval[nvtab.nval-1].name;
      nvtab.nameval[i].value=nvtab.nameval[nvtab.nval-1].value;
      nvtab.nameval[nvtab.nval-1].name = NULL;
      nvtab.nameval[nvtab.nval-1].value = 0;      
      return 1;
    }
  }
  
  return 0;
}