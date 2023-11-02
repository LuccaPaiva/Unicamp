#include <stdio.h>


int main() {
  int m, n, mp, np, i, j, soma, max, a, b, pc, uc;
  m = n = 3;//scanf("%d", &m);
  //scanf("%d", &n);
  mp = np = 2;//scanf("%d", &mp);
  //scanf("%d", &np);
  //printf("m %d n %d mp %d np %d\n", m, n, np, np);
  int lista[3][3];
  //printf("okay\n");
  for(i = 0; i < 3; i++){
    for(j = 0; j < 3; j++){
      lista[i][j] = i * j;
      printf("%d ", lista[i][j]);
    }
    printf("\n");
  }
  for(i = 0; i < (m + 1 - mp); i++){
    soma = pc = uc = 0;
    for(j = 0; j < (n + 1 - np); j++){
      //verifica se é a primeira   coluna, se for, calcula a primeira vez soma e a pc
      if(j == 0){
        for(a = 0; a < mp; a ++){
          for(b = 0; b < np; b++){
            soma += lista[i + a][j + b];
            pc += lista[i + a][j];
          }
        }
      //verifica se a soma é maior q o maximo
      if(max < soma){
        max = soma;
      }//caso nao seja a primeira coluna:
      }else{
        for(a = 0; a < m; b++){
          pc += lista[i + a][j];
          uc += lista[i + a][j + np];
        }
        soma += (uc - pc);
        if(soma > max){
          max = soma;
        }
      }
    }
  }
  printf("%d\n", soma);
  return 0;
}
