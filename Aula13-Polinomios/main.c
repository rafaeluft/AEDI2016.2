#include <stdio.h>
#include <string.h>
#include "GDList.h"
#include <stdlib.h>

int comp_int(void* s1, void* s2){
  int *p1 = (int*) s1,
      *p2 = (int*) s2;
    return (*p1 < *p2)? -1: (*p1 == *p2)? 0: 1;
}

int comp_int_inv(void* s1, void *s2){
  return -1;
    return -1*comp_int(s1, s2);
}

void print_int (void* t){
  int *p;
  p = (int*) t;
  printf("%d ", *p);
}

void print_float (void* t) {
  float *p;
  p = (float *) t;
  printf("%2.2f \n", *p);
}

int getInt(void* t){
  int *p;
  p = (int*) t;
  return (*p);
}

int main(){
  int v[] = {3, 1, 5, 7, 2};
  //float v[] = {2.4, 4.2, 5.4, 3.2, 1.1};
  //char v[4][128] = {"Rafael Lima", "Yolanda Ribeiro", "Arthur Modesto", "Pedro Alves"};
  int sizeV = 5, i;
  void (*fprint)(void*) = print_int;
  char* str = "12x^3+(-5)x^4";
  char *token, *token2;

  token = strtok(str, "+");
   while (token != NULL)
   {
      printf("%s\n", token);
      token = strtok(NULL, "+");
      //while((token2 = strtok(token, "x")) != NULL)
      //  printf("%s\n", token2);
   }
   exit(0);
  GDList *L1 = GDList_create();
  for(i=0; i < sizeV; i++){
    GDList_insere_o(L1, &v[i], sizeof(v[i]), comp_int_inv);
      GDList_print(L1, fprint);
  }
  //GDList_print(L1, fprint);
  return (0);
}
