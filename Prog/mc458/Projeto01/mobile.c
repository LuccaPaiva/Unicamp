/**
 * Este arquivo pode ser usado como base para o seu codigo.
 * Preste especial atencao a funcao ja implementada "imprimeSaida". Esta função
 * deve ser usada para imprimir o resultado da execucao de cada algoritmo.
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * Imprime "S" se emBalanco for maior que 0, e "N" caso contrario.
*/

typedef struct haste{
	int peso;//peso da haste, considerando as sub

	//sub haste esquerda
	int dist_e;
	struct haste *has_e;

	//sub haste direita
	int dist_d;
	struct haste *has_d;
}haste;

//CRIAR FUNCAO PARA CRIAR HASTE



int j = 0;
void Genesis(int k, haste **raiz, int mobile[][4]){

			if(mobile[j][0] > 0){
				//folha esquerda
				*raiz-> = malloc(sizeof(haste));
				*raiz->has_e = NULL;
				*raiz->has_d = NULL;
				*raiz->dist_e = mobile[j][1];
				*raiz->dist_d = mobile[j][3];
				*raiz->peso = mobile[j][0];

				printf("Haste Folha E %d %d\n", j, mobile[j][0]);
	//			return raiz;
			}
			if(mobile[j][2] > 0){
				//folha direita
				raiz->has_d = malloc(sizeof(haste));
				raiz->has_d->has_e = NULL;
				raiz->has_d->has_d = NULL;
				raiz->has_d->dist_e = 0;
				raiz->has_d->dist_d = 0;
				raiz->has_d->peso = mobile[j][2];

				printf("Haste Folha D %d %d\n", j, mobile[j][2]);
		//		return raiz;
			}
			//Inducao
			if(mobile[j][0] == 0){
				j++;
				raiz->has_e = Genesis(k, j,mobile);
				printf("Inserido E %d %d\n", j, mobile[j][0]);
			}
			if(mobile[j][2] == 0){
				j++;
				raiz->has_d = Genesis(k, i, mobile);
				printf("Inserido D %d %d\n", j, mobile[j][2]);
			}
			return raiz;
	}
}

void exibirEmOrdem(haste *raiz, int i){
    if(raiz != NULL){
        i++;
        exibirEmOrdem(raiz->has_e, i);
        for (int e=0; e<i; e++) {
            printf ("   ");
        }
        printf("%i\n", raiz->peso);
        exibirEmOrdem(raiz->has_d, i);
    }
}

// !0 = equilibrio  |  0 = desequilibrio
int verifica(haste *has, int a){
	printf("Entrando %d\n", a);
	//os netos sao NULL
	if((has->has_e->has_e == NULL && has->has_e->has_d == NULL)&&(has->has_d->has_e == NULL && has->has_d->has_d == NULL)) {
		//has->has_e = FOLHA && has->has_d = FOLHA
		if(has->has_e->peso*has->dist_e == has->has_d->peso*has->dist_d){
			has->peso = has->has_e->peso + has->has_d->peso;
			return has->peso;
		}
		else{
			return 0;
		}
	}
	printf("Passou do if 1\n");

	//um dos netos e NULL
	if(has->has_e->has_e == NULL && has->has_e->has_d == NULL){
		printf("entrou if 2\n");
		//to numa haste final
		has->has_e->peso = has->has_e->has_e->peso + has->has_e->has_d->peso;
		return has->has_e->peso;
	}
	printf("Passou if 2\n");

	//Se neto direito é NULL tem arvore pra esquerda
	if(has->has_d == NULL){
		printf("KKKKKKKKK\n");
	}
	if(has->has_d->has_e == NULL && has->has_d->has_d == NULL){
		printf("Ola\n");
		return has->has_d->peso;
	}
	printf("Passou if 3\n");

	int aux_e = 0;
	int aux_d = 0;
	if(has->has_e->has_e != NULL){
		//has->has_e NAO-FOLHA
		printf("Indo pra E %d\n", ++a);
		aux_e = verifica(has->has_e, a++);
	}
	if(has->has_d->has_d != NULL){
		//has->has_e NAO-FOLHA
		printf("Indo pra D%d\n", ++a);
		aux_d = verifica(has->has_d, a++);
	}
	if(aux_e > 0 && aux_d > 0){
		has->peso = has->has_e->peso + has->has_d->peso;
		return has->peso;
	}
	else{
		return 0;
	}
}


void imprimeSaida(unsigned emBalanco) {
	printf("%s\n", (emBalanco ? "S" : "N"));
}

int main(int argc, char const *argv[]) {
	int k;
	int mobile[1000][4];
	scanf("%d", &k);
	for(int i = 0; i < k; i++){
		scanf("%d", &mobile[i][0]);
		scanf("%d", &mobile[i][1]);
		scanf("%d", &mobile[i][2]);
		scanf("%d", &mobile[i][3]);
	}
	haste *has=NULL;

	Genesis(k, &has, mobile);
	printf("Criado\n");
	exibirEmOrdem(has, 0);
	/*
	int resp = verifica(has, 0);
	printf("%d\n", resp);
	imprimeSaida(resp);
	*/
	return (0);
}
