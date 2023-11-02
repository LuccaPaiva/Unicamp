#ifndef lab06_func
#define lab06_func


typedef struct node{
    int valor;
    int count;
    struct node* next;
}node;


int mtf(int value, node* head, int i);

int transp(int value, node* head, int i);

int count(int value, node* head, int i);
