//
// Created by Rafael Lima de Carvalho on 16/03/17.
//

#ifndef AULA07_TDSTACK_TDSTACK_H_H
#define AULA07_TDSTACK_TDSTACK_H_H
typedef struct _no{
   int info;
    struct _no *prox;
}no;

typedef struct{
    int qty;
    no* head;
}TDStack;
/**
 * Insere itens na pilha.
 * @return 0 em caso de falha e
 * 1 em caso de sucesso.
 */
int TDStack_push(TDStack*, int);
/**
 * Retira itens da pilha.
 * @return 0 em caso de falha e
 * 1 em caso de sucesso.
 */
int TDStack_pop(TDStack*, int*);

int TDStack_count(TDStack*);
TDStack* TDStack_create();
int TDStack_head(TDStack*);

no* no_create_n_fill(int);




#endif //AULA07_TDSTACK_TDSTACK_H_H
