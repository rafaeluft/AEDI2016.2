#include <stdio.h>
#include <stdlib.h>
#include "GDList.h"

void print_int (void* t){
  int *p;
  p = (int*) t;
  printf("%d \n", *p);
}

void print_float (void* t){
  float *p;
  p = (float*) t;
  printf("%2.2f \n", *p);
}

int main(){
  //int v[] = {1, 2, 3, 4, 5};
  float v[] = {2.4, 4.2, 5.4, 3.2, 1.1};
  int sizeV = 5, i;
  void (*fprint)(void*) = print_float;

  GDList *L1 = GDList_create();
  for(i=0; i < sizeV; i++){
    GDList_insere(L1, &v[i], sizeof(v[i]));
  }
  GDList_print(L1, fprint);
  return (0);
}
