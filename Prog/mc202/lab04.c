#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
  char nome[51];
  char ad[101];
  char tel[13];
  char data[9];
  struct node *next;
} node;

//passar td pra str
void insercao(node *no,char *nome, char *ad, char* tel,char *data){
  node *p;
  p = no;
  while(p->next != NULL){
    p = p->next;
  }
  node *aux = malloc(sizeof(node));
  strcpy(aux->nome, nome);
  strcpy(aux->ad, ad);
  strcpy(aux->tel, tel);
  strcpy(aux->data, data);
  aux->next = p->next;
  p->next = aux;
}



void remocao(node *p,char *nome){
  while(p->next != NULL){
    if(p->nome == nome){
      node *del = p-> next;
      p->next = del->next;
      free (del);
    }
    p = p->next;
  }
}

void busca(node *p, char *nome){
  while(p->next != NULL){
    if(p->nome == nome){
      printf("%s%s\t%s\t%s", p->nome, p->ad, p->tel, p->data);
    }
    p = p->next;
  }
}


void impressao(node *p){
  while(p != NULL){
    printf("%*.*s", 0, (p->nome) - strchr(p->nome, "\n"), p->nome);
    printf("\t");
    printf("%*.*s", 0, (int)sizeof(p->ad) - 1, p->ad);
    printf("\t");
    printf("%*.*s", 0, (int)sizeof(p->tel) - 1, p->tel);
    printf("\t");
    printf("%*.*s", 0, (int)sizeof(p->data) - 1, p->data);
    printf("\n");
    p = p->next;
  }
}


int main(){
  node *p = malloc(sizeof(node));
  p->next = NULL;
  char auxn[51], auxad[101], auxtel[13], auxd[9];
  char in[2] ;
  while(scanf("%s", in) != EOF)  {
    if(in[0] == 'f'){
           break;
       }
    switch(in[0]){
      case 'i':
        printf("pre-scan nome\n");
        fflush(stdin);
        getchar();
        fflush(stdin);
        //fgets(auxn, 51, stdin);
        scanf("%[^\n]", auxn);
        fgets(auxad, 101, stdin);
        fgets(auxtel, 13, stdin);
        fgets(auxd, 9, stdin);
        //printf("input: %s\nnome: %sad: %stel: %sdata: %s\n", in, auxn, auxad, auxtel, auxd);
        insercao(p, auxn, auxad, auxtel, auxd);
        break;
      case 'r':
        fflush(stdin);
        getchar();
        fflush(stdin);
        fgets(auxn, 51, stdin);
        remocao(p, auxn);
        break;
      case 'b':
        fflush(stdin);
        getchar();
        fflush(stdin);
        fgets(auxn, 51, stdin);
        busca(p, auxn);
        break;
      case 'p':
        impressao(p);
        break;

    }
  }
  printf("FIM\n");
  return 0;
}




/*
#include <stdio.h>


int main(){
    char k[2], e[2];
    int i, j, l, count, max, posrep;
    while(scanf("%s", k) != EOF){
        char frase[101], rep[101], pog[101];
        fflush(stdin);
        // para debugar entrada do teclado
        fflush(stdin);
        getchar();

        fflush(stdin);
        fgets(frase, 100, stdin);
        printf("nome: %sinput: %s\n", frase, k);
    }
    return 0;
}
*/
