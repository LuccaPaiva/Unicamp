//Lucca Ferreira Paiva      240229
//Trabalho 1 de MC404, Parte 1



#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    ---- Você Deve implementar esta função para a parte 1.  ----
    Essa função é chamada pela main em main.c
    Entrada da função: arquivo de texto lido e seu tamanho
*/

/*
strSlice recebe uma string uma posicao inicial i e uma final f
retorna um NULL se o inicio for igual ao final
caso contrario, retorna a string que comeca em i e termina em f-1
*/
char *strSlice(char *origem, int i, int f){
  if(i == f){
    return NULL;
  }
  char *dest = malloc(sizeof(char)*(f - i));
  int k = 0;
  for(int j = i; j < f; j++, k++){
    dest[k] = origem[j];
  }
  dest[k] = '\0';
  return dest;
}

/*
strFind recebe uma string e uma caracter
retorna -1 se nao achar o caractere
caso contrario retorna a posicao i dele
*/

int strFind (char texto[], char c) {
  int t = strlen(texto);
  for (int i = 0; i < t; i++) {
    if(texto[i] == c) {
      return i;
    }
  }
  return -1;
}

/*
strLower recebe uma string
retorna a mesma string mas com os casacteres todos minusculos
*/

char *strLower (char texto[]) {
  int t = strlen(texto);
  char *texto2 = malloc (sizeof(char)*t);
  char *p = &texto[0];
  for (int i = 0; i < t; i++, p++) {
    if(*p >= 65 && *p <= 90) {
      texto2[i]= texto[i]+32;
    } else {
      texto2[i]=texto[i];
    }
  }
  return texto2;
}

/*
strComp recebe duas strings
retorna 0 se elas forem diferentes
caso contrario retorna 1
*/
int strComp (char texto1[], char texto2[]) {
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


/*
isMnemon recebe uma string
e dada a lista abaixo, ve se a string esta ou nao nela
retorna 1 se esta
0 caso contrario
*/

int isMnemon(char palavra[]){
  char *nome[17];
  nome[0] = "ld";
  nome[1] = "ldinv";
  nome[2] = "ldabs";
  nome[3] = "ldmq";
  nome[4] = "ldmqmx";
  nome[5] = "store";
  nome[6] = "jump";
  nome[7] = "jge";
  nome[8] = "add";
  nome[9] = "addabs";
  nome[10] = "sub";
  nome[11] = "subabs";
  nome[12] = "mult";
  nome[13] = "div";
  nome[14] = "lsh";
  nome[15] = "rsh";
  nome[16] = "storend";
  for(int i = 0; i < 17; i++){
    if(strComp(palavra, nome[i]) == 1){
      return 1;
    }
  }
  return 0;
}


/*
Funcao de processar entrada propriamente dita
recebi uma string e seu tamanho
retorna 0
*/

int processarEntrada(char* entrada, int tamanho){
    //Parte 1
    /*Funcao tem basicamente 2 partes
    */

    //Declaracao das variaveis a serem utilizadas
    int linha = 1;
    int comecoDaString = 0;
    int atualizaStr = 0;
    int atualizaLinha = 1;
    char* p = &entrada[0];
    char* inicio;
    char* pedaco = entrada;

    for(int i = 0; i < tamanho; i++, p++){
      //----------------------PARTE 1---------------------------------------
      /*
      utiliza-se um ponteiro para ir percorendo a string
      se o ponteiro achar um '\0', ' ', '\n' ou '#'
      ele identifica que a palavra anterior terminou,
      assim ele marca o comeco da proxima
      Se for o caso, ja seta a varivel para indicar isso
      Tambem cuida da verificacao das linhas
      */

      //Verifica se é final da string
      if (p[0] == '\0') {
        pedaco = strSlice(entrada, comecoDaString, i);
        atualizaStr = 1;
      }
      //Verifica se espaco
      else if (p[0] == ' ') {
        pedaco = strSlice(entrada, comecoDaString, i);
        if(pedaco != NULL){

          //loop para evitar ' ' e/ou '\n' seguidos
          while(p[1] == '\n' || p[1] == ' '){
            if(p[1] == '\n'){
              atualizaLinha++;
            }
            p++;
            i++;
          }
        }
        atualizaStr = i + 1;
      }
      //Verifica se é Enter
      else if (p[0] == '\n') {
        pedaco = strSlice(entrada, comecoDaString, i);
        if(pedaco != NULL){
          //loop para evitar ' ' e/ou '\n' seguidos
          while(p[1] == '\n' || p[1] == ' '){
            if(p[1] == '\n'){
              atualizaLinha++;
            }
            p++;
            i++;
          }
        }
        atualizaLinha++;
        atualizaStr = i + 1;
      }
      //Verifica se é Comentario
      else if(p[0] == '#'){
        //procuro pelo proximo '\n', que marca o final do Comentario
        int dif = strFind(&entrada[i], '\n');
        if(dif >= 0){
          pedaco = strSlice(entrada, i, i + dif);
          if(strlen(pedaco) > 0){
            atualizaStr = 1;
            i += dif - 1;
            p += dif - 1;
            //loop para evitar ' ' e/ou '\n' seguidos
            while(p[1] == '\n' || p[1] == ' '){
              if(p[1] == '\n'){
                atualizaLinha++;
              }
              p++;
              i++;
            }
            atualizaStr = i + 1;
          }
        }
        //se nao achou '\n' -> e o comentario no final do programa -> pode ser descartado
        else if(dif == -1){
          i = tamanho;
          break;
        }
      }

      //-------------------------PARTE 2------------------------------------------

      /*
      Se anteriormente tiver marcado que achei um dos caracteres,
      entao tenho uma palavra
      Note aqui que ja tenho qual e a string dessa palavra
      preciso identificar o seu tipo
      dps criar o token correspondente
      */
      if(atualizaStr > 0 && pedaco != NULL && strlen(pedaco) > 0){
        //Inicializacao das variaveis
        pedaco = strLower(pedaco);
        inicio = &pedaco[0];
        int comp = strlen(pedaco) - 1;
        //quer dizer que achou um mnemonico
        if(inicio[0] != '\n' && inicio[0] != ' ' && inicio[0] != '\0'){
          //verifica se e uma Diretiva
          if(inicio[0] == '.'){
            adicionarToken(Diretiva, pedaco, linha);
          }
          //verifica se e rotulo
          else if(inicio[comp] == ':'){
            adicionarToken(DefRotulo, pedaco, linha);
          }
          //verifica se e Hexadecimal
          else if(inicio[1] == 'x'){
            adicionarToken(Hexadecimal, pedaco, linha);
          }
          //verifica se e decimal
          else if(*inicio >= '0' && *inicio <= '9'){
            //quer dizer q achei decimal
            //printf("Decimal %d\n%s\n", linha, pedaco);
            adicionarToken(Decimal, pedaco, linha);
          }
          //Verifica se nao e comentario
          else if(inicio[0] != '#'){
            //quer dizer que achei intrucao ou Nome
            //verifica se e Instrucao
            if(isMnemon(&pedaco[0]) == 1){
                adicionarToken(Instrucao, pedaco, linha);
            }
            //se nao e nenhum dos anteriores so pode ser Nome
            else{
              adicionarToken(Nome, pedaco, linha);
            }
          }
        }

        //Aqui atualiza as variaveis
        comecoDaString = atualizaStr;
        atualizaStr = 0;
        linha = atualizaLinha;
      }
      //Aqui é pra tratar excessoes (no caso se pedaco == NULL)
      else if(atualizaStr > 0){
          comecoDaString = atualizaStr;
          atualizaStr = 0;
          linha = atualizaLinha;
      }
    }
    return 0;
  }
