//#include <stdlib.h>

#include "lab06_func.h"



int mtf (int value, node* head, int i){
  if(head->valor == value){
    return i;
  }
  node* p = head;
  while(p->next->valor != value){
    i++;
    p = p->next;
  }
  if(!p->next->next){//ve se nao 'e o ultimo'
    p->next = p->next->next;//no anterior aponta pro proximo
  }
  p->next = head;
  head = p;
  return i;
}


int transp (int value, node* head, int i){
  if(head->valor == value){
    return i;
  }
  node* p = head;
  if(head->next->valor == value){
    head->next = head->next->next;
    head = p->next;
    head->next = p;
    i++;
  }

  while(p->next->next->valor != value){
    i++;
    p = p->next;
  }
  node *pre = p->next;//aponta pro elemento anterior ao chosen one
  node *final = pre->next->next;
  p->next = pre->next;
  p->next->next = pre;
  pre->next = final;
  return i;
}


int count(int value, node* head, int i){
  node* p = head;
  node* max = head;
  node* one;
  while(p->next != value){
    if(p->next->count < max->next->count + 1){
      max = p;
    }
    i++;
    p = p->next;
  }
  one = p->next;
  p->next = p->next->next;
  one->next = max->next;
  max->next = one;
}
