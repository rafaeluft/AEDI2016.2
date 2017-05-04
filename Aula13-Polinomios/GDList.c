#include "GDList.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
int GDList_insere_o(GDList* L, void* info, unsigned int size, int (*cmp)(void*, void*)){
  TNo* novo = (TNo*)malloc(sizeof(TNo));
  TNo* aux;
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
    aux = L->inicio;
    while(aux->prox && cmp(aux->info, info) < 0)
      aux =  aux->prox;
    if(cmp(aux->info, info) < 0){
      //inserir após pois minha info é menor que a info que desejo inserir
      novo->prox = aux->prox;
      if(aux->prox != NULL)
        aux->prox->ant = novo;
      aux->prox = novo;
      novo->ant = aux;
    }else{
      //inserir antes
      novo->prox = aux;
      novo->ant = aux->ant;

      if(aux->ant)
        aux->ant->prox = novo;
      aux->ant = novo;
      if(aux == L->inicio)
        L->inicio = novo;
    }
  }
  return (1);
}

void GDList_print(GDList* L, void (*print)(void*)){
  TNo* aux = L->inicio;
  putchar('\n');
  while(aux){
    print(aux->info);
    aux = aux->prox;
  }
  putchar('\n');

}
