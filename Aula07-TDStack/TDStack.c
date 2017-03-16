//
// Created by Rafael Lima de Carvalho on 16/03/17.
//
#include "TDStack.h"
#include <stdlib.h>

no* no_create_n_fill(int d){
    no* temp = (no*) malloc(sizeof(no));
    if (temp){
        temp->info = d;
        temp->prox = NULL;
    }return (temp);
}

int TDStack_push(TDStack* P, int d){
    no* aux = no_create_n_fill(d);
    if (aux==NULL){
        return (0);
    }
    aux->prox = P->head;
    P->head = aux;
    P->qty++;
    return (1);
}

int TDStack_pop(TDStack* P, int* d){
    if(P->head == NULL)
        return (0);
    no* aux = P->head;
    *d = aux->info;
    P->head = P->head->prox;
    P->qty--;
    free(aux);
    return (1);
}

/*int TDStack_count(TDStack* P){
    return (P) ? P->qty : 0;
}*/

TDStack* TDStack_create(){
    TDStack* nova = (TDStack*) malloc(sizeof(TDStack));
    if(nova){
        nova->head = NULL;
        nova->qty = 0;
    }return (nova);
}
int TDStack_head(TDStack* P){
    return (P) ? (P->head) ? P->head->info : 0 : 0;
}
