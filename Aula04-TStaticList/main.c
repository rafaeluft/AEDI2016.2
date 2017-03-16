#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
int info; float x;
} TData;

typedef struct{
    TData* data;
    int count;
    int MAX;
} TStaticList;

TStaticList* TStaticList_create(int qty){
    TStaticList* nova = (TStaticList*) malloc(sizeof(TStaticList));
    int i;
    if (nova){
        nova->count = 0;
        nova->MAX = qty;
        nova->data = (TData*) calloc(qty, sizeof(TData));
        if (nova->data == NULL)
            return NULL;
    }return nova;
}
char TStaticList_insert(TStaticList* A, TData dado){
    if((A->count +1) == A->MAX){

        A->data[A->count++] = c;
        return 1;
    } return 0;
}

void TData_print(TData* d){
    if(d!=NULL){
        printf("%d %f ", d->info, d->x);
    }
}

void TStaticList_print(TStaticList* A, void (*printMyData)(TData*)){
    int i=0;
    for(;i<A->count; i++)
        printMyData(A->data[i]);
    putchar('\n');
}

TData* TData_create(int info, float x){
    TData* novo = (TData*) malloc(sizeof(TData));
    if(novo){
        novo->info = info;
        novo->x = x;
    }return novo;
}

int main(int argc, char* argv[]) {
    int i;
    TData *temp;
    TStaticList *L = TStaticList_create();
    if(L){
        for(i=0; i<5; i++)
            TStaticList_insert(L, TData_create(rand()%100, 0.01));
        TStaticList_print(L, TData_print);
    }
    return 0;
}