//LUCCA FERREIRA PAIVA 240229
//PA2


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


//funcao q imprime uma matriz, mas nao e chamada
void imprimeMat(int **A, int n, int m){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
}

//dada uma matriz A, linha i e coluna j
//retorn o minimo da fileira de baixo
//entre j - 1 e j + 1
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


void desloca(int **A, int n, int m){
  for(int i = 0; i < m + 2; i++){
    A[0][i] = A[1][i];
  }
}

int main(int argc, char const *argv[]) {
  int m, n;
  scanf("%d %d", &n, &m);

  //matriz base n por m
  int ** matrizBase = malloc((n)*sizeof(int *));
  for(int i = 0; i < n; i++) matrizBase[i] = malloc((m)*sizeof(int));

  int ** mat = malloc((2)*sizeof(int *));
  for(int i = 0; i < 2; i++) mat[i] = malloc((m + 2)*sizeof(int));


  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      scanf("%d", &matrizBase[i][j]);
    }
  }


  for(int i = 1; i < m + 2; i++){
    mat[1][i] = matrizBase[0][i - 1];
  }
  int max = 2147483647;//maior int possive --> como se fosse infinito
  for(int i = 0; i < 2; i++){
    mat[i][0] = max;
    mat[i][m + 1] = max;
  }




  //acho o custo da matriz matrizModificada
  //e soma com o correspondente da matriz base ja coloco na matriz modificada

  int aux;
  for(int i = 1; i < n + 1; i++){
    for(int j = 1; j < m + 1; j++){
      aux =  findMin(mat, 1, j);
      mat[1][j] = matrizBase[i - 1][j - 1] + aux;
    }
    desloca(mat, 2, m);
  }



  int cost = max;//assumi custo inicial cmo infinito

  for(int j = 1; j < m + 2; j++){
    if(mat[1][j] < cost){
      cost = mat[1][j];
    }
  }

  imprimeSaida(cost);


  //libera a memoria alocada
  for(int i = 0; i < 2; i++) free(mat[i]);
  free(mat);

  for(int i = 0; i < n; i++) free(matrizBase[i]);
  free(matrizBase);


    return 0;
}
