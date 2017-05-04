#ifndef GDLIST_H
#define GDLIST_H

typedef struct _no{
  void* info;
  struct _no *prox, *ant;
} TNo;

typedef struct{
  TNo *inicio;
}GDList;
GDList* GDList_create();
int GDList_insere_o(GDList*, void*, unsigned int, int (*cmp)(void*, void*));
int GDList_insere(GDList*, void*, unsigned int);
void GDList_print(GDList*, void (*print)(void*));

#endif
