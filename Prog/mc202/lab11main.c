#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab11dec.h"


int main(){
    int num, num1;
    char in[15];
    //tabela *table = malloc(sizeof(tabela));
    tabela *table = cria(7529);
    table->size = 7529;
    scanf("%s ", in);
    unsigned char f[251];
    entrada *entry = malloc(sizeof(entrada));
    entrada *aux = malloc(sizeof(entrada));
    do{
        if(strcmp(in, "i") == 0){
            scanf("%hhu", entry->frase);
            entry->key = func(entry->frase, table->size);
            insert(table, *entry);
        }
        else if(strcmp(in, "b") == 0){
            scanf("%hhu", aux->frase);
            aux->key = func(aux->frase, table->size);
            busca(table, aux->frase, entry);
        }
        else if(strcmp(in, "r") == 0){
            scanf("%hhu", f);
            printf("r\n");
        }
        else if(strcmp(in, "f") == 0){
            break;
        }
        scanf("%s ", in);
    }while(strcmp(in, "f"));
    freedom(table);
    return 0;
}
