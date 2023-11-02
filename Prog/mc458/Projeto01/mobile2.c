
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	 int peso;

	 int dist_e;
	 int peso_e;
	 struct node *no_e;

	 int dist_d;
	 struct node *no_d;
	 int peso_d;
} node;

int i = 0;

int criar (int j, int mob[][4], node *no){
		//Inserir no
		if(mob[i][0] > 0){
			no->peso_e = mob[i][0];
			no->dist_e = mob[i][1];
			no->peso_d = mob[i][2];
			no->dist_d = mob[i][3];
			no->no_e = NULL;
			//printf("Inserido E %d %d %d %d %d\n", i, mob[i][0], mob[i][1], mob[i][2], mob[i][3]);
		}
		if(mob[i][2] > 0){
			no->peso_e = mob[i][0];
			no->dist_e = mob[i][1];
			no->peso_d = mob[i][2];
			no->dist_d = mob[i][3];
			no->no_d = NULL;
			//printf("Inserido D %d %d %d %d %d\n", i, mob[i][0], mob[i][1], mob[i][2], mob[i][3]);
		}
		j = i;
		if(mob[j][0] == 0){
			no->no_e = malloc(sizeof(node));
			//no->no_e->dist_e = mob[j][1];
			//no->no_e->peso = 0;
			no->peso_e = 0;
			no->dist_e = mob[j][1];
			no->peso_d = mob[j][2];
			no->dist_d = mob[j][3];
			criar (++i, mob, no->no_e);
		}
		if(mob[j][2] == 0){
			no->no_d = malloc(sizeof(node));
			//no->no_d->dist_d = mob[i + 1][3];
			//no->no_d->peso = 0;
			no->peso_e = mob[j][0];
			no->dist_e = mob[j][1];
			no->peso_d = 0;
			no->dist_d = mob[j][3];
			criar (++i, mob, no->no_d);
		}
}

int pesos (node *no) {

/*
	if(no->no_e == NULL && no->no_d == NULL){
		E haste inteira
		if(no->peso_e*no->dist_e == no->peso_d*no->dist_d) {
			printf("Base %d %d %d %d\n", no->peso_e, no->dist_e, no->peso_d, no->dist_d);
			no->peso = no->peso_e + no->peso_d;
			return (no->peso_e + no->peso_d);
		}
		else{
			printf("Base desequilibrio\n");
			return -1;
		}
	}
*/

	//Parte esquerda
	if(no->no_e != NULL){
		//printf("In E\n");
		no->peso_e = pesos(no->no_e);
		no->peso = no->peso_e;
		//printf("Out E %d\n", no->peso);
	}

	//Parte direita
	if(no->no_d != NULL){
		//printf("In D\n");
		no->peso_d = pesos(no->no_d);
		no->peso = no->peso_d;
		//printf("Out D %d\n", no->peso);
	}
	return no->peso_d + no->peso_e;
/*
	if(no->no_e == NULL){
		printf("Ponta E\n");
		if(no->dist_e*no->peso_e == no->peso_d*no->dist_d){
			no->peso += no->peso_e;
			//printf("Ponta E %d\n", no->peso);
			return no->peso;
		}
		else{
			no->peso = 0;
			return 0;
		}
	}

	if(no->no_d == NULL){
		printf("Ponta D %d %d %d %d\n", no->peso_e, no->dist_e, no->peso_d, no->dist_d);
		if(no->dist_d*no->peso_d == no->peso_e*no->dist_e){
			no->peso += no->peso_d;
			//printf("Ponta D %d\n", no->peso);
			return no->peso;
		}
		else{
			no->peso = 0;
			return 0;
		}
	}

	if(no->peso != 0){
		printf("Retorno %d %d %d %d %d\n",no->peso, no->peso_e, no->dist_e, no->peso_d, no->no_d->dist_d);
		if(no->peso_e*no->no_e->dist_e == no->peso_d*no->no_d->dist_d){
			printf("Haste %d\n", no->peso);
			return no->peso;
		}
		else{
			return 0;
		}
	}
	else{
		//printf("Saindo %d\n",no->peso);
		return no->peso;
	}
*/
}

void imprimir (node *no, int i) {
	if (no != NULL) {
		i++;
		imprimir(no->no_e, i);
		for (int j=0; j<i; j++) {
			printf ("   ");
		}
		printf ("%d %d %d %d %d\n", no->peso, no->peso_e, no->dist_e, no->peso_d, no->dist_d);
		imprimir(no->no_d, i);
	}
}

void imprimeSaida(unsigned emBalanco) {
	printf("%s\n", (emBalanco ? "S" : "N"));
}

int balanco (node *no) {
	if (no != NULL){
		//printf ("a: %d %d %d %d\n", no->peso_e, no->dist_e, no->peso_d, no->dist_d);
		int peso_e = balanco(no->no_e);
		if (peso_e == -1)
			return -1;
		int peso_d = balanco(no->no_d);
		if (peso_d == -1)
			return -1;

	  //printf ("b: %d %d %d %d\n", no->peso_e, no->dist_e, no->peso_d, no->dist_d);

		if ((no->dist_e)*no->peso_e != (no->dist_d)*no->peso_d) {
			//printf ("-1\n");
			return -1;
		} else {
			//printf ("0\n");
			return 0;
		}
	}
}


int main(int argc, char const *argv[]) {
	int k;
	scanf("%d", &k);
	int mobile[1000][4];

	printf ("Entradas\n");
	for(int i = 0; i < k; i++){
		scanf("%d", &mobile[i][0]);
		scanf("%d", &mobile[i][1]);
		scanf("%d", &mobile[i][2]);
		scanf("%d", &mobile[i][3]);
		printf ("%d %d %d %d\n", mobile[i][0], mobile[i][1], mobile[i][2], mobile[i][3]);
	}

	node *raiz = malloc(sizeof(node));
	criar (0, mobile, raiz);
	printf("\nMobile Original\n");
	imprimir(raiz, 0);
	printf("\n");
	//printf("Criado\n");
	//printf("------------------------------------------------------------\n");

	int resp = pesos(raiz);
	//printf("%d %d %d\n", resp, raiz->peso_d, raiz->peso_e);
  resp = balanco(raiz);
	printf("Mobile Pesos\n");
	imprimir(raiz, 0);
	if (resp == -1) {
		printf ("\nN\n");
	} else {
		printf ("\nS\n");
	}

	//imprimeSaida(resp);
	return (0);
}
