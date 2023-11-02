/**
 * Este arquivo pode ser usado como base para o seu codigo.
 * Preste especial atencao a funcao ja implementada "imprimeSaida". Esta função
 * deve ser usada para imprimir o resultado da execucao de cada algoritmo.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Imprime o custo do caminho.
 */
void imprimeSaida(int custo) {
    printf("%d\n", custo);
}


void imprimeMat(int **A, int n, int m){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
}

int findMin(int **A,  int i, int j){
  int x, y, z;
  x = A[i - 1][j - 1];
  y = A[i - 1][j];
  z = A[i - 1][j + 1];
  if(x <= y){
    if(x <= z){
      return x;
    }
    else if(y <= z){
      return y;
    }
    return z;
  }
  else{//y < x
    if(y <= z){
      return y;
    }
    else if(z <= x){
      return z;
    }
    return x;
  }

}


int main(int argc, char const *argv[]) {
  int m, n;
  scanf("%d %d", &n, &m);

  int ** B = malloc((n + 1)*sizeof(int *));
  for(int i = 0; i < n + 1; i++) B[i] = malloc((m + 2)*sizeof(int));

  int ** C = malloc((n)*sizeof(int *));
  for(int i = 0; i < n; i++) C[i] = malloc((m)*sizeof(int));


  //printf("%d %d\n", n, m);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%d", &C[i][j]);
      B[i + 1][j + 1] = 0;
    }
  }

  for(int i = 0; i < m + 2; i++){
    B[0][i] = 0;
  }

  for(int i = 0; i < n + 1; i++){
    B[i][0] = 1000000;
    B[i][m + 1] = 1000000;
  }

  /*
  imprimeMat(C, n + 0, m + 0);
  printf("\n");
  imprimeMat(B, n + 1, m + 2);
'*/'

  int aux;
  for(int i = 1; i < n + 1; i++){
    for(int j = 1; j < m + 1; j++){
      aux =  findMin(B, i, j);
      B[i - 0][j - 0] = C[i - 1][j - 1] + aux;
      //printf("min %d\n", aux);
    }
  }

  //printf("\n");
  //imprimeMat(B, n + 1, m + 2);


  int cost = 1000000;

  for(int j = 1; j < m + 2; j++){
    if(B[n][j] < cost){
      cost = B[n][j];
    }
  }

  printf("%d", cost);


  for(int i = 0; i < n + 1; i++) free(B[i]);
  free(B);

  for(int i = 0; i < n; i++) free(C[i]);
  free(C);


    return 0;
}
