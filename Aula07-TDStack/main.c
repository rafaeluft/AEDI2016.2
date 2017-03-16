#include <stdio.h>
#include "TDStack.h"

int main(int argc, char* argv[]) {
    TDStack* P1 = TDStack_create();
    int i;
    if(P1){
        for(i=0; i< 5; i++)
            TDStack_push(P1, i+1);
        printf("Qtd de itens inseridos na pilha: %d\n", TDStack_count(P1));
        while(TDStack_pop(P1, &i))
            printf("%d\n", i);
    }
    return 0;
}