#include <stdio.h>
#include <string.h>



int main(){

  int k, e, i, j, l, count, max, posrep, n = 0;
  while(scanf("%d %d", &k, &e) != EOF){
      n++;
      char key[k][21], frase[e][101], rep[e][101], pog[101];
      for(i = 0; i < k; i++){
           fflush(stdin);
        scanf("%s", key[i]);
      }
    // para debugar entrada do teclado
      fflush(stdin);
      getchar();

      for(i = 0; i < e; i++){
        fflush(stdin);
        fgets(frase[i], 100, stdin);
      }

      //criar copia da string para ser comparada



      max = posrep = 0;

      for(i = 0; i < e; i++){//para as frases
        count = 0;
        char pog[100] = {'a'};
        for(l=0; frase[i][l]!='\0'; l++) {
                 if(frase[i][l] >= 'A' && frase[i][l] <= 'Z'){
                     pog[l] = frase[i][l] + 32;
                }else{
                    pog[l] = frase[i][l];
                }
            }
        //printf("%s%s\n", pog, frase[i]);
        for(j = 0; j < k; j++){//para as palavras
            for(l = 0; l < strlen(frase[i]) - strlen(key[j]); l++){//para as letras
            int ret;
            ret = strncmp(&pog[l], key[j], strlen(key[j]));
            //if(ret == 0){
                //printf("%d %s %s\n", ret, key[j], frase[i]);
           // }
            if(! ret){//se nao forem iguais
             //printf("okay %s %d %s\n", frase[i], i, key[j]);
             count++;
             if(count > max){
                 posrep = 1;
                 max = count;
                strcpy (rep[0],frase[i]);
             }else if(count == max){
                 strcpy (rep[posrep],frase[i]);
                 posrep++;
             }
            }
            }
        }
      }


    printf("Conjunto de desculpas #%d\n", n);
      for(i = 0; i < posrep; i++){
          printf("%s", rep[i]);

      }
	printf("\n");
  }
  return 0;
}
