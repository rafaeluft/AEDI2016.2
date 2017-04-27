#include "GDList.h"
#include <stdlib.h>
#include <string.h>

GDList* GDList_create(){
  GDList *tmp = (GDList*) malloc(sizeof(GDList));
  if(tmp){
    tmp->inicio = NULL;
  }
  return (tmp);
}

int GDList_insere(GDList* L, void* info, unsigned int size){
  TNo* novo = (TNo*)malloc(sizeof(TNo));
  if(!novo)
    return (0);
  novo->info = malloc(size);
  if(!(novo->info))
    return (0);
  memcpy(novo->info, info, size);
  novo->prox = NULL; novo->ant = NULL;
  if(L->inicio==NULL)
    L->inicio = novo;
  else{
    novo->prox = L->inicio;
    L->inicio->ant = novo;
    L->inicio = novo;
  }
  return (1);
}

void GDList_print(GDList* L, void (*print)(void*)){
  TNo* aux = L->inicio;
  while(aux){
    print(aux->info);
    aux = aux->prox;
  }
}
