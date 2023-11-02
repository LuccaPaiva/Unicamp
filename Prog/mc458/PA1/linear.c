#include <stdio.h>
#include <stdlib.h>


double findMin(double *A, int tam){
  int min = 0;
  for(int i = 1; i <= tam; i++){
    if(A[i] < A[min]){
      min = i;
    }
  }
  double aux = A[min];
  A[min] = A[tam];
  A[tam] = aux;

  return aux;
}


void linear(double *A, double *resp, int tam, int k){
  for(int i = 0; i < k; i++){
    resp[i] = findMin(A, tam - i);
  }
}




int main(){
  int n = 5;
  int k = 4;
  double *v = malloc(n * sizeof(double));
  double *resp = malloc(k*sizeof(double));


  for(int i = 0; i <= n; i++){
    v[i] = i;
  }

  printf("%d\n", sizeof(v));

  printf("--------------------------\n");
  for(int i = 0; i <= n; i++){
    printf("%lf\n", v[i]);
  }

  linear(v, resp, n, k);

  printf("--------------------------\n");
  for(int i = 0; i < n; i++){
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
