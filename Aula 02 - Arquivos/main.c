#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define filename "agenda.txt"
typedef struct {
    char nome[128];
    char telefone[64];
} Contato;

typedef struct{
    Contato* contatos[100];
    int count;
    int MAX;
} Agenda;

Agenda* Agenda_create(){
    Agenda* nova = (Agenda*) malloc(sizeof(Agenda));
    if (nova){
    //nova->contatos = NULL;
        nova->count = 0;
        nova->MAX = 100;
    }return nova;
}
char Agenda_add(Agenda* A, Contato* c){
    if((A->count +1) < A->MAX){
        A->contatos[A->count++] = c;
        return 1;
    } return 0;
}

void Agenda_print(Agenda* A, FILE* out){
    int i=0;
    for(;i<A->count; i++){
        fprintf(out, "%s, %s\n", (*A->contatos[i]).nome, A->contatos[i]->telefone);
        //printf("%s, %s\n", A->contatos[i]->nome, A->contatos[i]->telefone);
    }
}

Contato* Contato_create(char* nome, char* telefone){
    Contato* novo = (Contato*) malloc(sizeof(Contato));
    if(novo){
        strcpy(novo->nome, nome);
        novo->nome[strcspn(novo->nome, "\n")] = 0;
        strcpy(novo->telefone, telefone);
        novo->telefone[strcspn(novo->telefone, "\n")] = 0;
    }return novo;
}

void UIContato_fill(Contato* c){
    puts("Entre com o nome: ");
    //scanf("%s", c->nome);
    fgetc(stdin);
    fgets(c->nome, 128, stdin);
    puts("Entre com o telefone: ");
    //scanf("%s", c->telefone);
    fgets(c->telefone, 64, stdin);
    //c->telefone[strcspn(c->telefone, "\n")] = 0;
}

int UIMenu(){
    int op;
    fflush(stdin);
    puts("1-> Inserir \n 2-> Mostrar \n3-> Ler do arquivo \n4 Salvar no Arquivo \n 0-> Sair\n");
    puts("Digite sua opção:");
    scanf("%d", &op);
    return op;
}

int Agenda_save_to_file(Agenda* A, char file[128]){
    FILE* fd;
    fd = fopen(file, "w");
    if(fd){
        Agenda_print(A, fd);
        fclose(fd);
        return 1;
    }
    return 0;
}

int Agenda_read_from_file(Agenda* A, char file[128]){
    FILE* fd;
    char *token;
    char line[196];
    char data[2][196];
    Contato *temp;
    int count;
    fd = fopen(file, "r");
    if(fd){
        while(fgets(line, 196, fd)) {
            count=0;
            //puts(line);
            token = strtok(line, ",");
            while (token != NULL) {
                //puts(token);
                strcpy(data[count++], token);
                if (count == 2) break;
                token = strtok(NULL, ",");
            }
            temp = Contato_create(data[0], data[1]);
            Agenda_add(A, temp);
        }
        fclose(fd);
        return 1;
    }
    return 0;

}

int main(int argc, char* argv[]) {
    int op;
    Contato* temp;
    Agenda *A = Agenda_create();
    do{
        op = UIMenu();
        switch(op){
            case 1:
                temp = Contato_create("", "");
                UIContato_fill(temp);
                Agenda_add(A,temp);
                break;
            case 2: Agenda_print(A, stdout); break;
            case 3: Agenda_read_from_file(A, filename); break;
            case 4: puts((Agenda_save_to_file(A, filename))? "Salvo com sucesso": "Erro ao salvar no arquivo.");
                break;
        }
    }while(op!=0);
    return 0;
}