#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lab11dec.h"





unsigned long conv(unsigned char *str){//converte uc para int
    unsigned long hash = 7529;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; // hash * 32 + hash + c

    return hash;
}


int func(unsigned char *str, int size){//torna um uc em um int, < size
    unsigned long A = 0.6180339887;
    unsigned long val = conv(str) * A;
    val = val - (int)val;
    val = (int)(size * val);
    return val;
}


tabela *cria(int size){//cria uma tabela a partir do 0, com todos os items NULL
    tabela *p = (tabela*) malloc(sizeof(tabela));
    if(p != NULL){
        int i;
        p->size = size;
        p->itens = (entrada**) malloc(size * sizeof(entrada *));
        if(p->itens == NULL){
            free(p);
            return NULL;
            //se nao foi possivel alocar
        }
        p->count = 0;
        for(i = 0; i < p->size; i++)
            p->itens[i] = NULL;
            //seta tds os itens para NULL
    }
    printf("criado\n");
    return p;
}


void freedom(tabela* p){//libera tds os itens, o itens e a tabela
    if(p != NULL){
        int i;
        for(i = 0; i < p->size; i++){
          if(p->itens[i] != NULL)
              free(p->itens[i]);
        }
        free(p->itens);
        free(p);
    }
}

int dhash(int h1, unsigned char *str, int i, int size){
    //funcao double hash, retorna inteiro < size, para caso haja colisao
    int h2 = func(str, size - 1) + 1;
    return((h1 + (i * h2)) & 0x7FFFFFFF) % size;
}


int busca(tabela *p, unsigned char *str, entrada *q){
    if(p == NULL)//se nao foi possivel alocar mem
        return 0;
    int i, pos, newpos;
    pos = func(str, p->size);
    for(i = 0; i < p->size; i++){
      //laco para procurar pos, vai na pos inicial, se tiver outra coisa la, chama de novo
      newpos = dhash(pos, q->frase,i, p->size);
      if(p->itens[newpos] == NULL)
          return 0;
      if(strcmp((char)*(p->itens[newpos]->frase), (char)str){
          //aponta q para onde esta o que se procura
          *q = *(p->itens[newpos]);
          return 1;
      }
    }
    return 0;
}


int insert(tabela *p, entrada new){//funcao para inserir uma entrada q na tabela p
    if(p == NULL || p->count == p->size)//erro se tabela null ou cheia
        return 0;
      int key = new.key;
      int i, pos, newpos;
      pos = new.key;
      for(i = 0; i < p->size; i++){//acha posicao vazia
          newpos = dhash(pos, new.frase, i, p->size);
          if(p->itens[newpos] == NULL){
              //achou posicao vazia
              entrada *novo;
              novo = malloc(sizeof(entrada));
              if(novo == NULL)//se n achou mem
                   return 0;
              *novo = new;
              p->itens[newpos] = novo;
              p->count++;
              printf("inserido\n");
              return 1;
          }
      }
      return 0;
}
