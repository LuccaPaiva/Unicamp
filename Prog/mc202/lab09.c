

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "def09.h"
//#include "def09.h"

int main(){
    int num;
    char in[15];
    node *raiz = malloc(sizeof(node));
    scanf("%s", in);
    do{
        if(strcmp(in, "inserir") == 0){
            scanf("%d", &num);
            if(!count){
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
        scanf("%s", in);
    }while(strcmp(in, "terminar") );
    freedom(raiz);
    return 0;
}
