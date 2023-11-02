

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "def10.h"
//#include "def09.h"

int main(){
    int num, num1;
    char in[15];
    node *raiz;
    scanf("%s", in);
    do{
        if(strcmp(in, "inserir") == 0){
            scanf("%d", &num);
            if(!count){
                raiz  = malloc(sizeof(node));
                raiz->valor = num;
                raiz->left = raiz->right = NULL;
                raiz->pai = NULL;
                count++;
            }
            else{
                insert(raiz, num);
            }
        }
        else if(strcmp(in, "buscar") == 0){
            scanf("%d", &num);
            busca(raiz, num);
        }
        else if(strcmp(in, "pos-ordem") == 0){
            pos(raiz);
            printf("\n");
        }
        else if(strcmp(in, "em-ordem") == 0){
            ordem(raiz);
            printf("\n");
        }
        else if(strcmp(in, "pre-ordem") == 0){
            pre(raiz);
            printf("\n");
        }
        else if(strcmp(in, "largura") == 0){
            largura(raiz);
            printf("\n");
        }
        else if(strcmp(in, "minimo") == 0)
            min(raiz);
        else if(strcmp(in, "maximo") == 0)
            max(raiz);
        else if(strcmp(in, "sucessor") == 0){
            scanf("%d", &num);
            next(raiz, num);
        }
        else if(strcmp(in, "predecessor") == 0){
            scanf("%d", &num);
            prev(raiz, num);
        }
        else if(strcmp(in, "buscar-intervalo") == 0){
            scanf("%d %d", &num, &num1);
            estado = 0;
            inter(raiz, num, num1);
            if(estado == 0)
                printf("nenhuma");
            printf("\n");
        }
        else if(strcmp(in, "remover") == 0){
            scanf("%d", &num);
            delete(raiz, num);
        }
        scanf("%s", in);
    }while(strcmp(in, "terminar") );
    freedom(raiz);
    return 0;
}
