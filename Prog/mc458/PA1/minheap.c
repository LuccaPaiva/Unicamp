#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void minHeapfy(double *A,  int tam, int i){
  int e = 2*i;
  int d = e + 1;
  int menor = i;
  if(e <= tam && A[e] < A[i]){
    menor = e;
  }
  if(d <= tam && A[d] < A[menor]){
    menor = d;
  }
  if(menor != i){
    double aux = A[i];
    A[i] = A[menor];
    A[menor] = aux;
    minHeapfy(A, tam, menor);
  }
}

void buildMinHeap(double *A, int tam){
  for(int i = floor(tam /2); i >= 0; i--){
    minHeapfy(A, tam, i);
  }
}

void heapSort(double *A, double *resp, int tam, int k){
  buildMinHeap(A, tam);
  double aux;
  for(int i = tam; i > tam - k; i--){
    aux = A[0];
    A[0] = A[i];
    A[i] = aux;
    minHeapfy(A, i - 1, 0);
    resp[tam - i] = A[i];
  }
}


int main(){
  int n = 50;
  int k = 4;
  double *v = malloc(n * sizeof(double));
  double *resp = malloc(k*sizeof(double));


  for(int i = 0; i <= n; i++){
    v[i] = - i;
  }

  printf("%d\n", sizeof(v));

  printf("--------------------------\n");
  for(int i = 0; i <= n; i++){
    printf("%lf\n", v[i]);
  }

  heapSort(v, resp, n, k);

  printf("--------------------------\n");
  for(int i = 0; i <= n; i++){
    printf("%lf\n", v[i]);
  }
  printf("--------------------------\n");
  for(int i = 0; i < k; i++){
    printf("%lf\n", resp[i]);
  }

  free(resp);
  free(v);

  return 0;


}
