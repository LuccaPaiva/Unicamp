#include <stdio.h>
#include <stdlib.h>


//#include "lab06_aux.h"


typedef struct node{
    int valor;
    int count;
    struct node* next;
}node;




int mtf (int value, node* dummy, int i){
  node* p = dummy;
  node* a;
  while(p->next->valor != value){
    i++;
    p = p->next;
  }
  i++;
  a = p->next;
  p->next = p->next->next;
  a->next = dummy->next;
  dummy->next = a;
  return i;
}


int transp (int value, node* dummy, int i){
  node* p = dummy;
  if(dummy->next->valor == value){
    return ++i;
  }
  while(p->next->next->valor != value){
    i++;
    p = p->next;
  }
  i+= 2;
  node *pre = p->next;//aponta pro elemento anterior ao chosen one
  node *final = pre->next->next;
  p->next = pre->next;
  p->next->next = pre;
  pre->next = final;
  return i;
}


int count(int value, node* dummy, int i){
  node* p = dummy, *pm, *aux;
  int max = 0;
  if(dummy->next->valor == value){
    return 1;
  }
  while(p->next->valor != value){
    p = p->next;
    i++;
  }
  i++;
  aux = dummy->next;
  p->next->count++;
  max = p->next->count++;
  aux = dummy;
  while(aux->next->count > max){
    aux = aux->next;
  }
  pm = aux;


  aux = p->next;
  p->next = p->next->next;
  aux->next = pm->next;
  pm->next = aux;
  p = dummy;
  while(p != NULL){
    p = p->next;
  }
  return i;
}



int main(){
  int n, req, i, cmtf = 0, ct = 0, cc = 0;
  scanf("%d %d", &n, &req);
  int acess[req];
  for(i = 0; i < req; i++){
    scanf("%d", &acess[i]);
  }

  node *dummy, *p, *new, *aux;
  dummy = malloc(sizeof(node));
  dummy->valor = 0;
  dummy->count = 0;
  p = dummy;
  for(i = 1; i <= n; i++){
    new = malloc(sizeof(node));
    p->next = new;
    new->valor = i;
    new->count = 0;
    p = new;
  }

  p = dummy->next;
  for(i = 0; i < req; i++){
    cmtf += mtf(acess[i], dummy, 0);
  }

  //--------------------------------------
  dummy->valor = 0;
  dummy->count = 0;
  p = dummy;
  for(i = 1; i <= n; i++){
    new = malloc(sizeof(node));
    p->next = new;
    new->valor = i;
    new->count = 0;
    p = new;
  }
  for(i = 0; i < req; i++){
    ct += transp(acess[i], dummy, 0);
  }
  //----------------------------------------
  dummy->valor = 0;
  dummy->count = 0;
  p = dummy;
  for(i = 1; i <= n; i++){
    new = malloc(sizeof(node));
    p->next = new;
    new->valor = i;
    new->count = 0;
    p = new;
  }
  p = dummy->next;
  for(i = 0; i < req; i++){
    cc += count(acess[i], dummy, 0);
  }
  p = dummy;
  while(p!=NULL){
    aux = p;
    p = p->next;
    free(aux);
  }
  printf("%d %d %d\n", cmtf, ct, cc);
  return 0;
}
