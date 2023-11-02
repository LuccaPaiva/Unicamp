
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    ---- Você Deve implementar esta função para a parte 1.  ----
    Essa função é chamada pela main em main.c
    Entrada da função: arquivo de texto lido e seu tamanho
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
  //printf("i: %d f: %d: Retorno da Slice: %s\n", i, f, dest);
  return dest;
}

int strFind (char texto[], char c) {
  int t = strlen(texto);
  for (int i=0; i<t; i++) {
    if(texto[i]==c) {
      return i;
    }
  }
  return -1;
}

char *strLower (char texto[]) {
  int t = strlen(texto);
  char *texto2 = malloc (sizeof(char)*t);
  //printf("T = %d\n%s\n", t, texto);
  char *p = &texto[0];
  for (int i = 0; i < t; i++, p++) {
    if(*p >= 65 && *p <= 90) {
      //printf("%d\n", *p);
      texto2[i]= texto[i]+32;
    } else {
      texto2[i]=texto[i];
    }
  }
  //free(texto2);
  return texto2;
}


int strComp (char texto1[], char texto2[]) {
  int t1 = strlen(texto1);
  int t2 = strlen(texto2);
  if(t1 != t2){
    return 0;
  }
  for (int i = 0; i < t1; i++) {
    if(!(texto1[i] == texto2[i] || texto1[i] + 32 == texto2[i])) {
      return 0;
    }
  }
  return 1;
}


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
    if(strComp(palavra, nome[i]) == 0){
      return 1;
    }
  }
  return 0;
}


int processarEntrada(char* entrada, int tamanho){
    /* printf("Você deve implementar esta função para a Parte 1.\n"); */

    //1 LER LINHA
    /*fazer for de (0 ate tamanho )e ir percorrendo entrada
    se achar espaco ou fim de linha -> grava texto em variavel
    var pra gravar qual linha ta
    */
    int linha = 1;
    int tipo;
    int comecoDaString = 0;
    int atualizaStr = 0;
    int atualizaLinha = 1;
    char* p = &entrada[0];
    char* inicio;
    char* final;
    char* pedaco = entrada;
    printf("Processando %d\n\n", tamanho);

    for(int i = 0; i < tamanho; i++, p++){
      if (p[0] == '\0') {
        pedaco = strSlice(entrada, comecoDaString, i);
        //printf("Achei final %d\n%s\n", i, pedaco);
        atualizaStr = 1;
      }
      else if (p[0] == ' ') {
        pedaco = strSlice(entrada, comecoDaString, i);
        //printf("Achei espaco %d %d\n%s\n", comecoDaString, i, pedaco);
        while(p[1] == '\n' || p[1] == ' '){
          if(p[1] == '\n'){
            atualizaLinha++;
            printf("Linha++ em Esp loop %d\n", linha);
          }
          p++;
          i++;
        }
        atualizaStr = i + 1;
      }
      else if (p[0] == '\n') {
        pedaco = strSlice(entrada, comecoDaString, i);
        printf("Achei enter %d %d\n%s\n", comecoDaString, i, pedaco);
        if(pedaco != NULL){
          while(p[1] == '\n' || p[1] == ' '){
            if(p[1] == '\n'){
              atualizaLinha++;
              //printf("Linha++ em Enter loop %d\n", linha);
            }
            p++;
            i++;
          }
        }
        atualizaLinha++;
        atualizaStr = i + 1;
      }
      else if(p[0] == '#'){
        //Ja sei que é comentario
        int dif = strFind(&entrada[i], '\n');
        //printf("%d -----", dif);
        if(dif >= 0){
          pedaco = strSlice(entrada, i, i + dif);
          atualizaStr = 1;
          //printf("Achei # %d %d\n%s\n", i, dif, pedaco);
          i += dif - 1;
          p += dif - 1;
          while(p[1] == '\n' || p[1] == ' '){
            if(p[1] == '\n'){
              atualizaLinha++;
              //printf("Linha++ em #loop %d\n", linha);
            }
            p++;
            i++;
          }
          atualizaStr = i + 1;
          //printf("Novo i:%d p:%d  ", i, p[0]);
        }
        if(dif == -1){
          printf("Achei coment final\n");
          i = tamanho;
          break;
        }
      }


    //2 Identificar tipo de token (com a linha tb)
    /*Usar a var em cima para achar o tipo
    E achar que palavra ele representa
    ja tem a lonha
    */
    if(atualizaStr > 0 && pedaco != NULL){
      pedaco = strLower(pedaco);
      inicio = &pedaco[0];
      int comp = strlen(pedaco) - 1;
      final = &pedaco[strlen(pedaco) - 1];
      //printf("%d %d %ld ", inicio[0], inicio[comp], strlen(pedaco));
      //quer dizer que achou um mnemonico
      if(inicio[0] != '\n' && inicio[0] != ' ' && inicio[0] != '\0'){
        if(inicio[0] == '.'){
          //quer dizer que achei Diretiva
          printf("Diretiva %d\n%s\n", linha, pedaco);
          tipo = 1;
        }
        else if(inicio[comp] == ':'){
          //quer dizer que achei Rotulo
          printf("Rotulo %d\n%s\n", linha, pedaco);
          tipo = 2;
        }
        else if(inicio[1] == 'x'){
          printf("Hex %d\n%s\n", linha, pedaco);
          //quer dizer q achei HEX
          tipo = 3;
        }
        else if(*inicio >= '0' && *inicio <= '9'){
          //quer dizer q achei decimal
          printf("Decimal %d\n%s\n", linha, pedaco);
          tipo = 4;
        }
        else if(inicio[0] != '#'){
          //printf("Comentario\n");
          //quer dizer q achei HEX
          //quer dizer que achei intrucao ou Nome
          if(isMnemon(&pedaco[0]) == 1){
              printf("Instrucao %d\n%s\n", linha, pedaco);
          }
          else{
            printf("Nome %d\n%s\n", linha, pedaco);
          }
        }
      }
      else{
        printf("Inicio Z\n");
      }
      //3 Criar token


      comecoDaString = atualizaStr;
      atualizaStr = 0;
      linha = atualizaLinha;
      printf("-\n");
    }
    else if(atualizaStr > 0){
      comecoDaString = atualizaStr;
      atualizaStr = 0;
      linha = atualizaLinha;
      printf("Else\n");
    }

  }
  return 0;
}

int aux(char entrada[], int pos){
  if (entrada[pos] == '\n') {
    printf("Achei enter %d\n", pos);
  }
  else if (entrada[pos] == ' ') {
    printf("Achei espaco %d\n", pos);
  }
  else{
    printf("%d %c\n", pos, entrada[pos]);
  }
}



int main(){
    char entry[] = "\nADD 0x10\nSUB 20\n\nadd k           #Erro na Parte 2! Usado, mas não definido!\nSUB 15";
    int size = strlen(entry);
    printf("%s \nTamanho: %d\n---------------------------------------------------\n", entry, size);
    aux(entry, 0);
    int ret = processarEntrada(entry, size);
    printf("\nFIM\n");
    return ret;
  }
