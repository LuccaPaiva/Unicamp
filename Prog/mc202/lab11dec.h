#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef DEF11DECH
#define DEF11DECH




typedef struct entrada{
    unsigned char frase[251];
    int key;
}entrada;

typedef struct tabela{//struct da tabela total
    int count, size;
    entrada **itens;
}tabela;


tabela *cria(int size);

void freedom(tabela *p);

unsigned long conv(unsigned char* str);

int func(unsigned char *str, int size);

int insert(tabela* p, entrada q);

int busca(tabela* p, unsigned char *str, entrada *q);

int dhash(int h1, unsigned char *str, int i, int size);


#endif
