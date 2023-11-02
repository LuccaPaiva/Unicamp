#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
    ---- Voce deve implementar essa função para a Parte 2! ----
    Utilize os tokens da estrutura de tokens para montar seu código!
    Retorna:
        *  1 caso haja erro na montagem; (imprima o erro em stderr)
        *  0 caso não haja erro.
 */


 int strComp (char texto1[], char texto2[]) {
   int t1 = strlen(texto1);
   int t2 = strlen(texto2);
   if(t1 != t2){
     return 0;
   }
   for (int i = 0; i < t1; i++) {
     if(texto1[i] != texto2[i]) {
       return 0;
     }
   }
   return 1;
 }

int emitirMapaDeMemoria(){
    /* printf("Voce deve implementar essa função para a Parte 2!");*/
    //Parte 1
    /*
    Mapa de memoria vetor de du
    Criar dois vetores para tabela de pares
    Um com string outro com os enderecos(esse de duas dim, contar esq ou dir)
    */
    int vetLinha[1024][2];
    char *vetStr[64];




    return 0;
}
