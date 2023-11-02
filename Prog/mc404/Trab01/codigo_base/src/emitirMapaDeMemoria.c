#include "montador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <strings.h>



/*
    ---- Voce deve implementar essa função para a Parte 2! ----
    Utilize os tokens da estrutura de tokens para montar seu código!
    Retorna:
        *  1 caso haja erro na montagem; (imprima o erro em stderr)
        *  0 caso não haja erro.
 */


char *strSlice2(char *origem, int i, int f){
   if(i == f){
     return NULL;
   }
   char *dest = malloc(sizeof(char)*(f - i));
   int k = 0;
   for(int j = i; j < f; j++, k++){
     dest[k] = origem[j];
   }
   return dest;
}


int strComp2(char texto1[], char texto2[]) {
   int t1 = strlen(texto1);
   int t2 = strlen(texto2);
   if(t1 != t2){
     return 0;
   }
   for (int i = 0; i < t1; i++) {
     if(texto1[i] != texto2[i]) {
       return 0;
     }
   }
   return 1;
 }

int findRot (char base[1024][64], char rot[], int comp) {
  for(int i = 0; i < comp; i++){
    if(strComp2(base[i], rot) == 1){
      return i;
    }
  }
  return -1;
}


int strFind2 (char texto[], char c) {
  int t = strlen(texto);
  for (int i = 0; i < t; i++) {
    if(texto[i] == c) {
      return i;
    }
  }
  return -1;
}

char *hexify(char base[]){
  int l = strlen(base);
  char *dest = malloc(sizeof(char)*(l - 1));
  int i = 1, j = 0;
  while(base[i] != '\0'){
    if(base[i] == 'x'){
      i++;
    }
    if(base[i] > 97 && base[i] < 122){
      dest[j] = base[i] - 32;
    }
    else{
      dest[j] = base[i];
    }
    i++;j++;
  }
  return dest;
}

char *decToHex(char base[], char dest[]) {
    int num_decimal, quotient;
    num_decimal = atoi(base);
    int a = 0, var;
    char hex[3];
    quotient = num_decimal;
    while(quotient != 0) {
        var = quotient % 16;
        if( var < 10 ){
          var = var + 48;
        }
        else{
          var = var + 55 ;
        }
        hex[a++]= var;
        quotient = quotient / 16;
    }
    hex[a] = '\0';
    printf("Preview %s\t", hex);
    char aux[4];
    strcpy(aux, "000");
    int l = strlen(hex);
    for(int i = l; i > 3 - l; i--){
        aux[3 - l - i] = hex[i];
    }
    aux[4] = '\0';
    printf("Teste %s\n", aux);
    strcpy(dest, aux);
    return dest;
}

int hexToDec(char base[]){
  int l = strlen(base);
  int sum = 0;
  for(int i = 0; i < l; i++){
    if(base[i] >= 65 && base[i] <= 70){
      sum += (base[i] - 55)*pow(16, l - (i + 1));
    }
    else{
      sum += (base[i] - 48)*pow(16, l - (i + 1));
    }
  }
  printf("Hex to Dec: %s %d\n", base, sum);
  return sum;
}

char *hexTreeDig(char base[], char dest[]){
  int l = strlen(base);
  if(l >= 3){
    strcpy(dest, base);
    return base;
  }
  else{
    strcpy(dest, "000");
    for(int i = 0; i <= l; i++){
        dest[i + 3 - l] = base[i];
    }
    //printf("# dig %s\n", dest);
  }
  return dest;
}

char *fillWord(char base[]){
  int l = strlen(base);

  if(l == 10){
    return base;
  }
  char aux[10];
  strcpy(aux, base);
  int k = (10 - l);
  for(int i = 0; i < k; i++){
    base[i] = '0';
  }
  for(int i = 0; i < l; i++){
    base[i + k] = aux[i];
  }
  //printf("Fill word: %s %d %s\n", aux, l, base);
  return base;
}

void printLinha(int num_decimal){
  int a = 0, var;
  char hex[3];
  int quotient = num_decimal;
  while(quotient != 0) {
      var = quotient % 16;
      if( var < 10 ){
        var = var + 48;
      }
      else{
        var = var + 55 ;
      }
      hex[2 - a++]= var;
      quotient = quotient / 16;
  }
  hex[a] = '\0';
  printf("%s ", hex);
}

char *whatInst(Token *tol){
  char *nome[17];  char *codigo[17];
  nome[0] = "ld";  codigo[0] = "01";
  nome[1] = "ldinv";  codigo[1] = "02";
  nome[2] = "ldabs";  codigo[2] = "03";
  nome[3] = "ldmq";  codigo[3] = "0A";
  nome[4] = "ldmqmx";  codigo[4] = "09";
  nome[5] = "store";  codigo[5] = "21";
  nome[6] = "jump";  codigo[6] = "0D";
  nome[7] = "jge";  codigo[7] = "0F";
  nome[8] = "add";  codigo[8] = "05";
  nome[9] = "addabs";  codigo[9] = "07";
  nome[10] = "sub";  codigo[10] = "06";
  nome[11] = "subabs";  codigo[11] = "08";
  nome[12] = "mult";    codigo[12] = "0B";
  nome[13] = "div";  codigo[13] = "0C";
  nome[14] = "lsh";  codigo[14] = "14";
  nome[15] = "rsh";  codigo[15] = "15";
  nome[16] = "storend";  codigo[16] = "12";
  for(int i = 0; i < 17; i++){
    if(strComp2(tol->palavra, nome[i]) == 1){
      return codigo[i];
    }
  }
  return NULL;
}

int retPos(char texto[], char baseNome[1024][65], int lim){
  for(int i = 0; i <= lim; i++){
    if(strComp2(texto, baseNome[i]) == 1){
      return i;
    }
  }
  return -1;
}


int emitirMapaDeMemoria(){
    /* printf("Voce deve implementar essa função para a Parte 2!");*/
    //Parte 1
    /*
    Mapa de memoria vetor de du
    Criar dois vetores para tabela de pares
    Um com string outro com os enderecos(esse de duas dim, contar esq ou dir)
    */
    unsigned int tamanho = getNumberOfTokens();
    //Ponteiro da Posicao
    int contaLinha[2];
    int atualiza = 0;
    contaLinha[0] = 0;
    contaLinha[1] = 0;//0 = esquerda | 1 = direita
    int maxLinha = 0;
    //Base Mapa de Memoria
    char strInst[1024][2][3]; //AA
    char strEnde[1024][2][4];//DDD
    //Tabela de pares
    char tabelaNome[1024][65];
    int tabelaPos[1024][2];
    int tab = 0;
    //Tabela dos sets
    char setNome[1024][65];
    char setValor[1024][2][10];
    int set = 0;

    Token *tol;

    for(int i = 0; i < tamanho; i++){
      tol  = recuperaToken(i);
      //---------------Def Rot
      if(tol->tipo == DefRotulo){//Termina em ':' é declaracao
      int l = strlen(tol->palavra);
        strcpy(tabelaNome[tab], strSlice2(tol->palavra, 0, l - 1));
        tabelaPos[tab][0] = contaLinha[0];
        tabelaPos[tab][1] = contaLinha[1];
        tab++;
        printf("DefRotulo %d\n%s\n\n", i, tol->palavra);
      }
      //------------Instrucao
      else if(tol->tipo == Instrucao){
        strcpy(strInst[contaLinha[0]][contaLinha[1]], whatInst(tol));
        printf("Instrucao %d\n%s\n\n", i, tol->palavra);
        Token *nextTol = recuperaToken(i + 1);
        if(nextTol->tipo == Hexadecimal){
          strcpy(strEnde[contaLinha[0]][contaLinha[1]], nextTol->palavra);
          i++;
        }
        else if(nextTol->tipo == Decimal){
          //Convertex para HEX antes
          strcpy(strEnde[contaLinha[0]][contaLinha[1]], nextTol->palavra);
          i++;
        }
        else if(nextTol->tipo == Nome){//nome, entao agr so ignora
          strcpy(strEnde[contaLinha[0]][contaLinha[1]], "000");
          i++;
        }
        //termina vazio, preenche com "000"
        else{
          strcpy(strEnde[contaLinha[0]][contaLinha[1]], "000");
        }
        atualiza = 1;
      }
      //------------Diretiva
      else  if(tol->tipo == Diretiva){
        printf("Diretiva %d\n%s\n\n", i, tol->palavra);
        if(strComp2(tol->palavra, ".org") == 1){
          Token *nextTol = recuperaToken(++i);
          char aux[10];
          if(nextTol->tipo == Hexadecimal){
            strcpy(aux, hexify(nextTol->palavra));
            int k = hexToDec(aux);
            printf(".Org %s %d\n", aux, k);
            //passar k para dec63,
            contaLinha[0] = k;
            contaLinha[1] = 0;
          }
          else if(nextTol->tipo == Decimal){
            strcpy(aux, decToHex(nextTol->palavra, aux));
            int k = hexToDec(aux);
            printf(".Org %s %d\n", aux, k);
            contaLinha[0] += k;
          }
          if(maxLinha < contaLinha[0]){
            maxLinha = contaLinha[0];
          }
        }
        else if(strComp2(tol->palavra, ".align") == 1){
          Token *nextTol = recuperaToken(++i);
          if(strlen(nextTol->palavra) == 1 && *nextTol->palavra == '1'){
            contaLinha[0]++;
            contaLinha[1] = 0;
          }
          else{
            int k = atoi(nextTol->palavra);
            while((contaLinha[0] % k) != 0){
              contaLinha[0]++;
            }
            contaLinha[1] = 0;
          }
        }
        else if(strComp2(tol->palavra, ".word") == 1){
          if(contaLinha[1] == 1){
            contaLinha[0]++;
            contaLinha[1] = 0;
          }
          Token *nextTol = recuperaToken(++i);
          if(nextTol->tipo != Nome){
            char word[10];
            //ver se é HEX ou Dec
            if(nextTol->tipo == Decimal){
              strcpy(word, decToHex(nextTol->palavra, word));
              printf(". word Dec to Hex %s %s\n", nextTol->palavra, word);
              strcpy(word, fillWord(word));
            }
            else if(nextTol->tipo == Hexadecimal){
              //printf(". word Hexify %s %s\n", nextTol->palavra, hexify(nextTol->palavra));
              strcpy(word, fillWord(hexify(nextTol->palavra)));
            }

            printf(".Word: %s %s\n", nextTol->palavra, word);
            strcpy(strInst[contaLinha[0]][contaLinha[1]], strSlice2(word, 0, 2));
            strcpy(strEnde[contaLinha[0]][contaLinha[1]],  strSlice2(word, 2, 5));
            printf("%s %s | ", strInst[contaLinha[0]][0],strEnde[contaLinha[0]][0]);
            contaLinha[1] = 1;
            strcpy(strInst[contaLinha[0]][contaLinha[1]], strSlice2(word, 5, 7));
            strcpy(strEnde[contaLinha[0]][contaLinha[1]],  strSlice2(word, 7, 10));
            printf("%s %s\n\n", strInst[contaLinha[0]][1], strEnde[contaLinha[0]][1]);
          }
          else{
            strcpy(strInst[contaLinha[0]][contaLinha[1]], "00");
            strcpy(strEnde[contaLinha[0]][contaLinha[1]],  "000");
            contaLinha[1] = 1;
            strcpy(strInst[contaLinha[0]][contaLinha[1]], "00");
            strcpy(strEnde[contaLinha[0]][contaLinha[1]], "000");
            printf(".word nome %s %s / %s %s\n", strInst[contaLinha[0]][0],strEnde[contaLinha[0]][0], strInst[contaLinha[0]][1],strEnde[contaLinha[0]][1]);
          }
          atualiza = 1;
        }
        else if(strComp2(tol->palavra, ".wfill") == 1){
          if(contaLinha[1] == 1){
            contaLinha[0]++;
            contaLinha[1] = 0;
          }
          //verificar se nao é nome
          Token *nextTol = recuperaToken(++i);
          if(nextTol->tipo != Nome){
            int num;
            //ver se é HEX ou Dec
            if(nextTol->tipo == Decimal){
              num = atoi(nextTol->palavra);
            }
            else if(nextTol->tipo == Hexadecimal){
              char aux[10];
              strcpy(aux, hexify(nextTol->palavra));
              num = hexToDec(aux);
            }
            Token *nextTol = recuperaToken(++i);
            if(nextTol->tipo != Nome){
              char word[10];
              //ver se é HEX ou Dec
              if(nextTol->tipo == Decimal){
                strcpy(word, decToHex(nextTol->palavra, word));
                strcpy(word, fillWord(word));
              }
              else if(nextTol->tipo == Hexadecimal){
                strcpy(word, fillWord(hexify(nextTol->palavra)));
              }
              for(int j = 0; j < num; j++){
                strcpy(strInst[contaLinha[0]][contaLinha[1]], strSlice2(word, 0, 2));
                strcpy(strEnde[contaLinha[0]][contaLinha[1]],  strSlice2(word, 2, 5));
                contaLinha[1] = 1;
                strcpy(strInst[contaLinha[0]][contaLinha[1]], strSlice2(word, 5, 7));
                strcpy(strEnde[contaLinha[0]][contaLinha[1]],  strSlice2(word, 7, 10));
                contaLinha[0]++;
                contaLinha[1] = 0;
              }
            }
            else{
              for(int j = 0; j < num; j++){
                strcpy(strInst[contaLinha[0]][contaLinha[1]], "00");
                strcpy(strEnde[contaLinha[0]][contaLinha[1]],  "000");
                contaLinha[1] = 1;
                strcpy(strInst[contaLinha[0]][contaLinha[1]], "00");
                strcpy(strEnde[contaLinha[0]][contaLinha[1]], "000");
                contaLinha[0]++;
                contaLinha[1] = 0;
              }
            }
            atualiza = 1;
          }
        }
        else if(strComp2(tol->palavra, ".skip") == 1){
          if(contaLinha[1] == 1){
            contaLinha[0]++;
            contaLinha[1] = 0;
          }
          Token *nextTol = recuperaToken(++i);
          if(nextTol->tipo != Nome){
            int num;
            //ver se é HEX ou Dec
            if(nextTol->tipo == Decimal){
              num = atoi(nextTol->palavra);
            }
            else if(nextTol->tipo == Hexadecimal){
              char aux[10];
              strcpy(aux, hexify(nextTol->palavra));
              num = hexToDec(aux);
            }
            contaLinha[0] += num;
          }
          //verificar se nao é nome

        }
        else if(strComp2(tol->palavra, ".set") == 1){
          Token *nextTol = recuperaToken(++i);
          strcpy(setNome[set], nextTol->palavra);
          nextTol = recuperaToken(++i);
          strcpy(setValor[set][0], nextTol->palavra);
          if(nextTol->tipo == Hexadecimal){
            strcpy(setValor[set][1], "h");
          }
          else{
            strcpy(setValor[set][1], "d");
          }
          printf(".Set: %s %s\n", setNome[set], setValor[set][0]);
          set++;
          contaLinha[0]++;
        }
      }

      //Atualiza ponteiro contador
      if(atualiza == 1){
        if(contaLinha[1] == 0){
          contaLinha[1] = 1;
        }
        else{
          contaLinha[0]++;
          contaLinha[1] = 0;
        }
        atualiza = 0;
      }
      if(contaLinha[0] > maxLinha){
        maxLinha = contaLinha[0];
      }
    }

    printf("\n-------------------------------------------------------------------------------\n");
    if(maxLinha < contaLinha[0]){
      maxLinha = contaLinha[0];
    }
    for(int i = 0; i <= maxLinha; i++){
      if(strInst[i][0] != NULL && strlen(strInst[i][0]) > 0){
        printLinha(i);
        printf("%d %s %s %s %s\n", i, strInst[i][0], strEnde[i][0], strInst[i][1], strEnde[i][1]);
      }
    }

    printf("\n-------------------------------------------------------------------------------\nTABELA DE PARES\n");
    for(int i = 0; i < tab; i++){
      printf("%d %s %d %d\n", i, tabelaNome[i], tabelaPos[i][0], tabelaPos[i][1]);
    }
    printf("\n-------------------------------------------------------------------------------\nTABELA DOS SET\n");
    for(int i = 0; i < set; i++){
      printf("%d %s %s\n", i, setNome[i], setValor[i][0]);
    }
    printf("\n-------------------------------------------------------------------------------\n");


    //---------------------PARTE 2-------------------------
    int atualiza2 = 0;
    int contaLinha2[2];
    contaLinha2[0] = 0;
    contaLinha2[1] = 0;//0 = esquerda | 1 = direita
    int maxLinha2 = 0;
    //Base Mapa de Memoria
    char strInst2[1024][2][3]; //AA
    char strEnde2[1024][2][4];//DDD
    /*DADOS QUE EU JA TENHO
    //Tabela de pares
    char tabelaNome[1024][65];
    int tabelaPos[1024][2];
    int tab = 0;
    //Tabela dos sets
    char setNome[1024][65];
    char setValor[1024][10];
    int set = 0;
    */
    tol = recuperaToken(0);
    for(int i = 0; i < tamanho; i++){
      tol  = recuperaToken(i);
      //------------Instrucao
      if(tol->tipo == Instrucao){
        char inst[3];
        strcpy(inst, whatInst(tol));
        strcpy(strInst2[contaLinha2[0]][contaLinha2[1]], inst);
        //printf("Instrucao %s %s\n", inst,tol->palavra);
        Token *nextTol = recuperaToken(++i);
        if(nextTol->tipo == Hexadecimal){
          strcpy(strEnde2[contaLinha2[0]][contaLinha2[1]], hexify(nextTol->palavra));
        }
        else if(nextTol->tipo == Decimal){
          //Convertex para HEX antes
          decToHex(nextTol->palavra, strEnde2[contaLinha2[0]][contaLinha2[1]]);
        }
        else if(nextTol->tipo == Nome){//Procurar nome
          //Verificar qual instrucao
          int pos = retPos(nextTol->palavra, tabelaNome, tab);
          //printf("Int pos dos pares %d\n", pos);
          if(pos > -1){//quer dizer que é rotulo
            printf("Tabela pos %d %d\n", tabelaPos[pos][0], tabelaPos[pos][1]);
            int linhaEnde = tabelaPos[pos][0];
            int posEnde = tabelaPos[pos][1];
            printf("linha endereco %d %d\n", linhaEnde, posEnde);
            //vou ter que mudar instrucao
            if(posEnde == 1){
              if(strComp2(inst, "0D") == 1){
                strcpy(strInst2[contaLinha2[0]][contaLinha2[1]], "0E");
              }
              if(strComp2(inst, "0F") == 1){
                strcpy(strInst2[contaLinha2[0]][contaLinha2[1]], "10");
              }
              if(strComp2(inst, "12") == 1){
                strcpy(strInst2[contaLinha2[0]][contaLinha2[1]], "13");
              }
            }
          char aux[4];
          sprintf(aux, "%d", tabelaPos[pos][0]);
          char value[4];
          strcpy(value, decToHex(aux, value));
          printf("---Valor %s\n", value);
          //strcpy(aux, hexTreeDig(value, aux));
          strcpy(strEnde2[contaLinha2[0]][contaLinha2[1]], value);
          }
          else{
            pos = retPos(nextTol->palavra, setNome, set);
            //printf("Int pos dos sets %d %d %s\n", pos, setValor[pos][1][0], setValor[pos][0]);
            char value[10];
            if(setValor[pos][1][0] == 'h'){
              strcpy(value, hexify(setValor[pos][0]));
              char aux[4];
              strcpy(aux, hexTreeDig(value, aux));
              strcpy(value, aux);
            }
            else{
              strcpy(value, decToHex(setValor[pos][0], value));
            }
            //printf("Valor %s\n", value);
            strcpy(strEnde2[contaLinha2[0]][contaLinha2[1]], value);
          }
          atualiza = 1;
        }
        //termina vazio, preenche com "000"
        else{
          strcpy(strEnde2[contaLinha2[0]][contaLinha2[1]], "000");
        }
        atualiza2 = 1;
      }
      //------------Diretiva
      else  if(tol->tipo == Diretiva){
        if(strComp2(tol->palavra, ".org") == 1){
          if(contaLinha2[1] == 1){
            contaLinha2[0]++;
            contaLinha2[1] = 0;
          }
          Token *nextTol = recuperaToken(++i);
          char aux[10];
          if(nextTol->tipo == Hexadecimal){
            strcpy(aux, hexify(nextTol->palavra));
            int k = hexToDec(aux);
            printf(".Org %s %d\n", aux, k);
            //passar k para dec63,
            contaLinha2[0] = k;
            contaLinha2[1] = 0;
          }
          else if(nextTol->tipo == Decimal){
            strcpy(aux, decToHex(nextTol->palavra, aux));
            int k = hexToDec(aux);
            printf(".Org %s %d\n", aux, k);
            contaLinha2[0] += k;
          }
          else{
            int pos = retPos(nextTol->palavra, setNome, tab);
            if(pos >= 0){//quer dizer que é Set
              printf(".Org %s %d\n", nextTol->palavra, pos);
              if(setValor[pos][1][0] == 'h'){
                strcpy(aux, hexify(setValor[pos][0]));
                contaLinha2[0] += hexToDec(aux);
              }
              else{
                strcpy(aux, decToHex(setValor[pos][0], aux));
                contaLinha2[0] += hexToDec(aux);
              }
            }
            else{//quer dizer que é rot
              pos = retPos(nextTol->palavra, tabelaNome, tab);
              contaLinha2[0] += tabelaNome[pos][0];
            }
          }
          if(contaLinha2[0] > maxLinha2){
            maxLinha2 = contaLinha2[0];
          }
        }
        else if(strComp2(tol->palavra, ".align") == 1){
          Token *nextTol = recuperaToken(++i);
          if(strlen(nextTol->palavra) == 1 && *nextTol->palavra == '1'){
            contaLinha2[0]++;
            contaLinha2[1] = 0;
          }
          else if(nextTol->tipo == Decimal){
            int k = atoi(nextTol->palavra);
            while((contaLinha2[0] % k) != 0){
              contaLinha2[0]++;
            }
            contaLinha2[1] = 0;
          }
          else if(nextTol->tipo == Hexadecimal){
            char aux[10];
            strcpy(aux, hexify(nextTol->palavra));
            int k = hexToDec(aux);
            while((contaLinha2[0] % k) != 0){
              contaLinha2[0]++;
            }
            contaLinha2[1] = 0;
          }
          else{
            int pos = retPos(nextTol->palavra, setNome, tab);
            char aux[10];
            int k;
            if(pos >= 0){//quer dizer que é Set
              if(setValor[pos][1][0] == 'h'){
                strcpy(aux, hexify(setValor[pos][0]));
                k = hexToDec(aux);
              }
              else{
                strcpy(aux, decToHex(setValor[pos][0], aux));
                k = hexToDec(aux);
              }
            while((contaLinha2[0] % k) != 0){
              contaLinha2[0]++;
            }
            contaLinha2[1] = 0;
          }
        }
        printf(",Align %d\n", contaLinha2[0]);
      }
        else if(strComp2(tol->palavra, ".word") == 1){
          if(contaLinha2[1] == 1){
            contaLinha2[0]++;
            contaLinha2[1] = 0;
          }
          Token *nextTol = recuperaToken(++i);
          if(nextTol->tipo != Nome){
            char word[10];
            //ver se é HEX ou Dec
            if(nextTol->tipo == Decimal){
              strcpy(word, decToHex(nextTol->palavra, word));
              strcpy(word, fillWord(word));
            }
            else if(nextTol->tipo == Hexadecimal){
              //printf(". word Hexify %s %s\n", nextTol->palavra, hexify(nextTol->palavra));
              strcpy(word, fillWord(hexify(nextTol->palavra)));
            }

            strcpy(strInst2[contaLinha2[0]][contaLinha2[1]], strSlice2(word, 0, 2));
            strcpy(strEnde2[contaLinha2[0]][contaLinha2[1]],  strSlice2(word, 2, 5));
            contaLinha2[1] = 1;
            strcpy(strInst2[contaLinha2[0]][contaLinha2[1]], strSlice2(word, 5, 7));
            strcpy(strEnde2[contaLinha2[0]][contaLinha2[1]],  strSlice2(word, 7, 10));
          }
          else{
            if(contaLinha[1] == 1){
              contaLinha[0]++;
              contaLinha[1] = 0;
            }
            int pos = retPos(nextTol->palavra, setNome, set);
            if(pos >= 0){
              char word[10];
              if(setValor[pos][1][0] == 'h'){
                strcpy(word, hexify(setValor[pos][0]));
              }
              else{
                strcpy(word, decToHex(setValor[pos][0], word));
              }
              strcpy(word, fillWord(word));
              strcpy(strInst2[contaLinha2[0]][contaLinha2[1]], strSlice2(word, 0, 2));
              strcpy(strEnde2[contaLinha2[0]][contaLinha2[1]],  strSlice2(word, 2, 5));
              contaLinha2[1] = 1;
              strcpy(strInst2[contaLinha2[0]][contaLinha2[1]], strSlice2(word, 5, 7));
              strcpy(strEnde2[contaLinha2[0]][contaLinha2[1]],  strSlice2(word, 7, 10));
            }/*
            else{
              pos = retPos(nextTol->palavra, tabelaNome, tab);
              char aux[10];
              strcpy(aux, tabelaPos[pos])

            strcpy(strInst2[contaLinha2[0]][contaLinha2[1]], "00");
            strcpy(strEnde2[contaLinha2[0]][contaLinha2[1]],  "000");
            contaLinha2[1] = 1;
            strcpy(strInst2[contaLinha2[0]][contaLinha2[1]], "00");
            strcpy(strEnde2[contaLinha2[0]][contaLinha2[1]], "000");
            printf(".word nome %s %s / %s %s\n", strInst2[contaLinha2[0]][0],strEnde2[contaLinha2[0]][0], strInst2[contaLinha2[0]][1],strEnde2[contaLinha2[0]][1]);
          }*/
          }
          atualiza2 = 1;
        }
        else if(strComp2(tol->palavra, ".wfill") == 1){
          printf(".Wfill\n");
          if(contaLinha2[1] == 1){
            contaLinha2[0]++;
            contaLinha2[1] = 0;
          }
          //verificar se nao é nome
          Token *nextTol = recuperaToken(++i);
          if(nextTol->tipo != Nome){
            int num;
            //ver se é HEX ou Dec
            if(nextTol->tipo == Decimal){
              num = atoi(nextTol->palavra);
            }
            else if(nextTol->tipo == Hexadecimal){
              char aux[10];
              strcpy(aux, hexify(nextTol->palavra));
              num = hexToDec(aux);
            }
            Token *nextTol = recuperaToken(++i);
            char word[10];
            if(nextTol->tipo != Nome){
              //ver se é HEX ou Dec
              if(nextTol->tipo == Decimal){
                strcpy(word, decToHex(nextTol->palavra, word));
                strcpy(word, fillWord(word));
              }
              else if(nextTol->tipo == Hexadecimal){
                strcpy(word, fillWord(hexify(nextTol->palavra)));
              }
            }
            else{
              int pos = retPos(nextTol->palavra, setNome, tab);
              if(pos >= 0){//quer dizer que é Set
                if(setValor[pos][1][0] == 'h'){
                  strcpy(word, hexify(setValor[pos][0]));
                }
                else{
                  strcpy(word, decToHex(setValor[pos][0], word));
                }
                strcpy(word, fillWord(word));
              }
            }
            for(int j = 0; j < num; j++){
              strcpy(strInst2[contaLinha2[0]][contaLinha2[1]], strSlice2(word, 0, 2));
              strcpy(strEnde2[contaLinha2[0]][contaLinha2[1]],  strSlice2(word, 2, 5));
              contaLinha2[1] = 1;
              strcpy(strInst2[contaLinha2[0]][contaLinha2[1]], strSlice2(word, 5, 7));
              strcpy(strEnde2[contaLinha2[0]][contaLinha2[1]],  strSlice2(word, 7, 10));
              contaLinha2[0]++;
              contaLinha2[1] = 0;
            }
            atualiza2 = 1;
          }
          else{//primeiro numero é Nome
            printf("Aqui %d\n", set);
            int pos = retPos(nextTol->palavra, setNome, set);
            printf("Aqui\n");
            if(pos >= 0){
              printf("Entrei\n");
              char word[10];
              int num;
              if(setValor[pos][1][0] == 'h'){
                strcpy(word, hexify(setValor[pos][0]));
              }
              else{
                strcpy(word, decToHex(setValor[pos][0], word));
              }
              num = hexToDec(word);
              Token *nextTol = recuperaToken(++i);
              if(nextTol->tipo != Nome){
                char word[10];
                //ver se é HEX ou Dec
                if(nextTol->tipo == Decimal){
                  strcpy(word, decToHex(nextTol->palavra, word));
                  strcpy(word, fillWord(word));
                }
                else if(nextTol->tipo == Hexadecimal){
                  strcpy(word, fillWord(hexify(nextTol->palavra)));
                }
                else{
                  int pos = retPos(nextTol->palavra, setNome, tab);
                  if(pos >= 0){//quer dizer que é Set
                    if(setValor[pos][1][0] == 'h'){
                      strcpy(word, hexify(setValor[pos][0]));
                    }
                    else{
                      strcpy(word, decToHex(setValor[pos][0], word));
                    }
                    strcpy(word, fillWord(word));
                }
                for(int j = 0; j < num; j++){
                  strcpy(strInst2[contaLinha2[0]][contaLinha2[1]], strSlice2(word, 0, 2));
                  strcpy(strEnde2[contaLinha2[0]][contaLinha2[1]],  strSlice2(word, 2, 5));
                  contaLinha2[1] = 1;
                  strcpy(strInst2[contaLinha2[0]][contaLinha2[1]], strSlice2(word, 5, 7));
                  strcpy(strEnde2[contaLinha2[0]][contaLinha2[1]],  strSlice2(word, 7, 10));
                  contaLinha2[0]++;
                  contaLinha2[1] = 0;
                }
              }
              atualiza2 = 1;
              }
            }
          }
        }
        else if(strComp2(tol->palavra, ".skip") == 1){
          if(contaLinha2[1] == 1){
            contaLinha2[0]++;
            contaLinha2[1] = 0;
          }
          Token *nextTol = recuperaToken(++i);
          if(nextTol->tipo != Nome){
            int num;
            //ver se é HEX ou Dec
            if(nextTol->tipo == Decimal){
              num = atoi(nextTol->palavra);
            }
            else if(nextTol->tipo == Hexadecimal){
              char aux[10];
              strcpy(aux, hexify(nextTol->palavra));
              num = hexToDec(aux);
            }
            contaLinha2[0] += num;
          }
          else{
            int pos = retPos(nextTol->palavra, setNome, set);
            if(pos >= 0){
              char aux[10];
              int k;
              if(setValor[pos][1][0] == 'h'){
                strcpy(aux, hexify(setValor[pos][0]));
              }
              else{
                strcpy(aux, decToHex(setValor[pos][0], aux));
              }
              k = hexToDec(aux);
              contaLinha2[0] += k;

            }
          }
          //verificar se nao é nome

        }
      }

      //atualiza2 ponteiro contador
      if(atualiza2 == 1){
        if(contaLinha2[1] == 0){
          contaLinha2[1] = 1;
        }
        else{
          contaLinha2[0]++;
          contaLinha2[1] = 0;
        }
        atualiza2 = 0;
      }
      if(contaLinha2[0] > maxLinha2){
        maxLinha2 = contaLinha2[0];
      }
    }

    printf("\n-------------------------------------------------------------------------------\n");
    if(maxLinha2 < contaLinha2[0]){
      maxLinha2 = contaLinha2[0];
    }
    for(int i = 0; i <= maxLinha2; i++){
      if(strInst2[i][0] != NULL && strlen(strInst2[i][0]) > 0){
        printLinha(i);
        printf("%s %s %s %s\n", strInst2[i][0], strEnde2[i][0], strInst2[i][1], strEnde2[i][1]);
      }
    }
    printf("\n\n");

    return 0;
}
