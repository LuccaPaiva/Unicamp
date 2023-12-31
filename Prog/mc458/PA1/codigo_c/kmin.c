#include <stdio.h>
#include <stdlib.h>

/*
  Funcao para validar seus algoritmos.
  Retorna 1 se a resposta estiver correta, 0 caso contrario.
  Caso a resposta seja incorreta, imprime tambem a resposta fornecida
  e a resposta esperada.
  Parametros:
  const double *v: vetor com a instancia do problema.
  int n: numero de elementos do vetor v.
  int k: parametro k do problema (ver enunciado).
  const double *r: vetor encontrado pelo seu algoritmo, contendo nas k
  primeiras posicoes, os k menores elementos do vetor v em ordem
  crescente.
*/
int resposta_correta(const double *v, int n, int k, const double *r);

/*
  Implementacao do algoritmo QuickSort.
  Ordena o vetor passado como parametro em ordem crescente.
  Parametros:
  double *v: vetor com a instancia do problema.
  int n: numero de elementos do vetor v.
*/
void quick_sort(double *v, int n);

/*
  Utilize esta funcao para medir o tempo de execucao do seu programa.
  A primeira chamada retorna um valor indefinido. A partir da segunda
  chamada, o double retornado contem o tempo decorrido, em segundos,
  entre a chamada atual e a ultima chamada da funcao.

  Exemplo de uso para medir o tempo de execucao de uma funcao 'f()':

  tempo();
  f();
  double t = tempo();
*/
double tempo();

/*
  Escreve o vetor com os k menores elementos em um arquivo "kmin.out" criado.
  (Obrigatório o uso dessa função no final do seu código para a correção).
  Parâmetros:
  vector<double> &r: vetor encontrado pelo seu algoritmo.
*/
void kmin_to_file(double *r, int k);

//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------Metodo Linear-----------------------------------------------------------------
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
//-----------------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------------------
int main(int argc, char **argv){

  if(argc != 4){
    if(argc == 3 && argv[2][0] != '0'){
      fprintf(stderr, "Uso Método 0: ./kmin <arq> 0\n");
      return 1;
    }
    else if(argc != 3){
      fprintf(stderr, "Uso geral: ./kmin <arq> <metodo> <k>\n");
      return 1;
    }
  }

  char *nomearq = argv[1];
  char metodo = argv[2][0];
  int k;
  if(argc == 4) k = atoi(argv[3]);

  FILE *arq = fopen(nomearq, "r");
  int n, i;
  double *v;

  fscanf(arq, "%d", &n);
  v = (double *)malloc(n * sizeof(double));

  for (i = 0; i < n; i++) {
    fscanf(arq, "%lf", &v[i]);
  }


  double *resp = malloc(k * sizeof(double));
  double t;
  tempo();
  linear(v, resp, n, k);
  t = tempo();





  fclose(arq);

  free(v);

  /* Descomente para imprimir o tempo de execucao */
   printf("%.6f\n", t); 

  return 0;
}
