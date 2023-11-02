//Lucca Ferreira Paiva 240229

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main(){
  int n, i, j;
  scanf("%i", &n);
  double **base = malloc(sizeof(double[n + 1]));
  for(i = 0; i < n; i++){
      double *a = malloc(sizeof(double[i + 1]));
      for(j = 0; j <= i; j++){
        if(i == 0){
          scanf("%lf", a);
        }
        else{
          scanf("%lf", &a[j]);
      }
        if(i == 0 && j == 0){
          base[0] = a;
        }
      }
      base[i] = a;
  }

  double dp, media = dp = 0;
  int num = (pow(n, 2) + n)/2;
  for(i = 0; i < n; i++){
    for(j = 0; j <= i; j++){
      media += base[i][j];
    }
  }

  media = media/num;
  for(i = 0; i < n; i++){
    for(j = 0; j <= i; j++){
      dp += pow((base[i][j] - media), 2);
    }
  }
  dp = sqrt(dp/ num);


  for(i = 0; i < n; i++){
    for(j = 0; j <= i; j++){
      if(j != i){
        printf("%0.12lf ", (base[i][j] - media)/ dp);
      }
      else{
        printf("%0.12lf ", (base[i][j] - media)/ dp);
      }
    }
    printf("\n");
  }


  for(i = 0; i < n; i++){
    free(base[i]);
  }
  free (base);
  printf("\n%0.12lf %0.12lf \n", media, dp);
  return 0;
}
