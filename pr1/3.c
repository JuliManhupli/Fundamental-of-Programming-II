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
};

enum {NVINIT = 1, NVGROW = 2};

int addname(Nameval newname, struct NVtab* nvtab);
int delname (char *name, struct NVtab* nvtab);

int main(void) {
  struct NVtab nvtab; 
  int curnum = addname((struct Nameval){.name="Andy", .value=12}, &nvtab);
  printf("%d\n", curnum);
  for (int i=0; i<nvtab.nval; i++){
    printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
  }
  return 0;
}

int addname(Nameval newname, struct NVtab* nvtab){
  Nameval *nvp;
  if (nvtab->nameval == NULL) {
    nvtab->nameval = (Nameval *) malloc(NVINIT * sizeof(Nameval));
    if (nvtab->nameval == NULL){
      return -1;
    }
    nvtab->max = NVINIT;
    nvtab->nval = 0;   
  }else if (nvtab->nval >= nvtab->max) {
    nvp = (Nameval *) realloc(nvtab->nameval, (NVGROW*nvtab->max)*sizeof(Nameval));
    if (nvp == NULL){
      return -1;
    }
    nvtab->max *= NVGROW;
    nvtab->nameval = nvp;
  }
  nvtab->nameval[nvtab->nval]=newname;  
  return nvtab->nval++;
}

int delname (char *name, struct NVtab* nvtab){
  for (int i=0; i<nvtab->nval; i++)
    if (strcmp(nvtab->nameval[i].name, name) == 0){
      memmove(nvtab->nameval+i, nvtab->nameval+i+1,
      (nvtab->nval-(i+1))*sizeof(Nameval));
      nvtab->nval--;   
      return 1;
    }
  return 0;
}