#include <stdio.h>

int main() {//    atual | total
  int c, n, i, j, espera, esperat, count, menor;
  float media;
  scanf("%d", &c);
  scanf("%d", &n);
  int cliente[n][2];//id vend | id client | chegada/demanda
  for(i = 0; i < n; i++){
    scanf("%d %d", &cliente[i][0], &cliente[i][1]);
  }
  int v[c];//freedom | estado | freedom (0 = livre, 1 ocupado)
  for(i = 0; i <= c; i ++){
    v[i] = 0;
  }
  espera = esperat = count = menor = 0;
  for(i = 0; i < n; i++){
    for(j = 0; j < c; j++){
      if(v[j] <= cliente[i][0]){
        menor = j;
        break;
        } else{
          if(v[j] < v[menor]){
          menor = j;
          }
        }
      }
      if(v[menor] <= cliente[i][0]){
        v[menor] = cliente[i][0] + cliente[i][1];
        //printf("%2d %2d\n", i, espera);
      }
      else{
        espera = v[menor] - cliente[i][0];
        if(espera > 10){
          count++;
        }
        esperat += espera;
        v[menor] += cliente[i][1];
        //printf("%2d %2d %2d %1d\n", i, espera, v[menor], menor);
      }
    }
  media = (float)esperat / n;
  printf("Espera media para %d clientes: %.1f minutos\n", n, media);
  printf("Numero de clientes que esperaram mais que 10 minutos: %d\n", count);
  return 0;
}
