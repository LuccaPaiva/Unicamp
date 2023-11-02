#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{//comeca com a pra frente, b pra tras
  double valor;
  struct node* a, *b;
}node;



node **findV(node *head, int val){
  printf("in\n");
  node *p = head, *q = head;
  int i = 0;
  //static node *vet[2];
  printf("in2");
  if(head->valor == val){
    printf("NULL");
    return NULL;//dps faco
  }
  else{
    if(!head->a)
      p = head->a;
    else
      p = head->b;
  }
  while(p->valor != val){
    printf("->%d\n", i++);
    if(p->a != q){
      if(q->a == p)
        q = q->a;
      else
        q = q->b;
      p = p->a;
    }
    else{
      if(q->a == p)
        q = q->a;
      else
        q = q->b;
      p = p->b;
    }
  }
  //vet[0] = p;
  //vet[1] = q;
  printf("%lf\t%lf\n", q->valor, p->valor);
  return &p;
  //return vet;
}


node *insert(node *closer, int pos, int valor, int len){
  node *p = malloc(sizeof(node));
  p->valor = valor;
  if(len == pos){
    closer->a = p;
    p->a = NULL;
    p->b = closer;
    printf("->%lf\n", p->b->valor);
    return p;
  }
  //NAO INSERCAO NO FINAL
  else{
    node *h, *q = closer;
    if(!closer->a)
      h = closer->a;
    else
      h = closer->b;
    for(int i = 0; i < pos; i++){
      if(h->a != q){
        if(q->a == h)
          h = q->a;
        else
          q = q->b;
        h = h->a;
      }
      else{
        if(q->a == h)
          q = q->a;
        else
          q = q->b;
        h = h->b;
      }
    }
  }
  return p;
}

/*

void swap(node *head, int val1, int val2){
  node **p1, **p2;
  p1 = findV(head, val1);
  p2 = findV(head, val2);
  int auxp1, auxp2;
  if(p1[1]->a == p1[0])
    auxp1 = 0;
  else
    auxp1 = 1;
  if(p2[1]->a == p2[0])
    auxp2 = 0;
  else
    auxp2 = 1;

  //assumir p1 antes p2

  return;
}

void freedom(node *head){
  node *aux;
  return;
}


*/

int main(){;
    char in0[2];
    int num, pos, count = 0;
    node *head, *tail;
    scanf("%s", in0);
    do{
        if(strcmp(in0, "i") == 0){
            scanf("%d %d", &pos, &num);
            if(count == 0){
              head = malloc(sizeof(node));
              head->valor = num;
              head->a = head->b = NULL;
              count++;
            }
            else if(count == 1){
              tail = malloc(sizeof(node));
              tail->valor = num;
              tail->a = NULL;
              tail->b = head;
              head->a = tail;
              count++;
            }
            else{
              node *closer;
              if(pos <= count%2)
                closer = head;
                head = insert(closer, pos, num, count);
              else
                closer = tail;
                tail = insert(closer, pos, num, count);
              count++;
            }
        }
        else if(strcmp(in0, "p") == 0){
            scanf("%d", &num);
            findV(head, num);
            printf("print\n");
        }
        else if(strcmp(in0, "v") == 0){
            printf("v\n");
        }
        scanf("%s", in0);
    }while(strcmp(in0, "t"));
    //free();
    return 0;
}
