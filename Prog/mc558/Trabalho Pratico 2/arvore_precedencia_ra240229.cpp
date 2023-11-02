//LUCCA FERREIRA PAIVA 240229

#include <iostream>
#include <list>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include "grafo.hpp"


// No do minHeap
struct MinHeapNode
{
	int v;
	int dist;
};

// Heap de minimo
struct MinHeap
{
	// numero de vertices no momento
	int tamanho;

	// tamanho maximo
	int capacidade;

	// usa no decreaseKey()
	int* pos;
	struct MinHeapNode** vetor;
};

// cria no do min heap
struct MinHeapNode* NovoNoMinHeap(int v, int dist)
{
	struct MinHeapNode* minHeapNode = (struct MinHeapNode*)
		malloc(sizeof(struct MinHeapNode));
	minHeapNode->v = v;
	minHeapNode->dist = dist;
	return minHeapNode;
}

// Cria o min heap
struct MinHeap* CriarMinHeap(int capacidade)
{
	struct MinHeap* minHeap = (struct MinHeap*)
		malloc(sizeof(struct MinHeap));
	minHeap->pos = (int*) malloc(capacidade * sizeof(int));
	minHeap->tamanho = 0;
	minHeap->capacidade = capacidade;
	minHeap->vetor = (struct MinHeapNode**)
		malloc(capacidade * sizeof(struct MinHeapNode*));
	return minHeap;
}

// Troca a posicao de 2 nos
void TrocarNoMinHeap(struct MinHeapNode** a, struct MinHeapNode** b)
{
	struct MinHeapNode* t = *a;
	*a = *b;
	*b = t;
}

// minheapify: garante que e um
//heap de min
void minHeapify(struct MinHeap* minHeap, int idx)
{
	int minimo, esq, dir;
	minimo = idx;
	esq = 2 * idx + 1;
	dir = 2 * idx + 2;

	if (esq < minHeap->tamanho &&
		minHeap->vetor[esq]->dist < minHeap->vetor[minimo]->dist)
		minimo = esq;

	if (dir < minHeap->tamanho &&
		minHeap->vetor[dir]->dist < minHeap->vetor[minimo]->dist)
		minimo = dir;

	if (minimo != idx)
	{
		// nos a serem trocados de posicao
		MinHeapNode* minimoNode =
			minHeap->vetor[minimo];
		MinHeapNode* idxNode =
			minHeap->vetor[idx];

		// troca de posicao
		minHeap->pos[minimoNode->v] = idx;
		minHeap->pos[idxNode->v] = minimo;

		// Trocando os nos
		TrocarNoMinHeap(&minHeap->vetor[minimo],
			&minHeap->vetor[idx]);

		minHeapify(minHeap, minimo);
	}
}

// Verifica se o heap ta vazio
int isEmpty(struct MinHeap* minHeap)
{
	return minHeap->tamanho == 0;
}

// Extrai o minimo do heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
	if (isEmpty(minHeap))
		return NULL;

	// raiz
	struct MinHeapNode* root =
		minHeap->vetor[0];

	// troca raiz com ultimo no
	struct MinHeapNode* lastNode =
		minHeap->vetor[minHeap->tamanho - 1];
	minHeap->vetor[0] = lastNode;

	// atualiza posicao ultimo no
	minHeap->pos[root->v] = minHeap->tamanho - 1;
	minHeap->pos[lastNode->v] = 0;

	// reduz tamanho
	--minHeap->tamanho;
	minHeapify(minHeap, 0);//heapify raiz

	return root;
}

// Diminui a distancia de um vertice v
// usa pos[v] para obter o vertice atual no min heap
void decreaseKey(struct MinHeap* minHeap, int v, int dist)
{
	// indice de v no vetor
	int i = minHeap->pos[v];

	// pega no e atualiza valor de distancia
	minHeap->vetor[i]->dist = dist;

	// Sobe toda a arvore
	// Custo: O(lg V)
	while (i && minHeap->vetor[i]->dist <
		minHeap->vetor[(i - 1) / 2]->dist)
	{
		// troca no com pai
		minHeap->pos[minHeap->vetor[i]->v] =
			(i - 1) / 2;
		minHeap->pos[minHeap->vetor[
			(i - 1) / 2]->v] = i;
		TrocarNoMinHeap(&minHeap->vetor[i],
			&minHeap->vetor[(i - 1) / 2]);

		// vai para indice do pai
		i = (i - 1) / 2;
	}
}

// Verifica se v esta no min heap
bool isInMinHeap(struct MinHeap* minHeap, int v)
{
	if (minHeap->pos[v] < minHeap->tamanho)
		return true;
	return false;
}

//Imprime a distancia de cada vertice ate a fonte
void printArr(int dist[], int pred[], int n)
{
	cout << "Vertice\tDistancia\n";
	for (int i = 0; i < n; ++i)
	{
		if (dist[i] != INFINITY)
			cout << i << "\t" << dist[i] << endl;
		else
			cout << i << "\t" << "Inf" << endl;
	}
}

//Funcao recursiva que auxilia a impressa oda arvore de precedencia
void impPred(int pred[], int V, int verticeAtual)
{
	if (pred[verticeAtual] != 0)
	{
		impPred(pred, V, pred[verticeAtual]);
	}
	cout << pred[verticeAtual] << "  ";
}

//Funcao que imprime a arvore de precedencia
void imprimePrecedencia(int pred[], int V)
{
	cout << endl;
	int aux = 0;
	for (int i = 0; i < V; i++)
	{
		cout << "Vertice " << i << ": ";
		impPred(pred, V, i);
		cout << i << endl;
	}
}



//Funcao que calcula a o caminho minimo da fonte ate todos os vertices
bool arvore_precedencia(int V, int M, int W, Grafo grafo, string* mensagem, int RA, int dist[], int pred[])
{
	//Fonte
	int fonte = 0;

	// Precedencia da fonte = 0
	pred[fonte] = 0;

	//Cria min heap
	struct MinHeap* minHeap = CriarMinHeap(V);

	// Inicializacao do minHeap

	for (int v = 0; v < V; ++v)
	{
		dist[v] = (int) INFINITY;
		minHeap->vetor[v] = NovoNoMinHeap(v, dist[v]);
		minHeap->pos[v] = v;
	}

	// dist da fonte = 0
	//que ai ele é extraido primeiro
	minHeap->vetor[fonte] = NovoNoMinHeap(fonte, dist[fonte]);
	minHeap->pos[fonte] = fonte;
	dist[fonte] = 0;
	decreaseKey(minHeap, fonte, dist[fonte]);

	// Tamanho inicial do minHeap é V
	minHeap->tamanho = V;

	// Enquanto a fila nao estiver vazia
	// sendo que minheap contem todos os vertices
	// que ainda nao foram finalizados
	while (!isEmpty(minHeap))
	{
		// Obtem no com menor distancia
		struct MinHeapNode* minHeapNode = extractMin(minHeap);

		// Armazena o valor do no
		int origem = minHeapNode->v;

		// passa por todos os vertices adjacentes a origem
		// atualizando suas distancias
		list<pair <int, int>> ::iterator temp;
		pair <int, int> aresta;
		for (temp = grafo.adj[origem].begin(); temp != grafo.adj[origem].end(); temp++)
		{
			aresta = *temp;
			int destino = aresta.first;
			int peso = aresta.second;

			if (isInMinHeap(minHeap, destino) && dist[origem] != INFINITY
				&& peso + dist[origem] < dist[destino])
			{
				dist[destino] = dist[origem] + peso;
				// Atualiza distancia
				//diminui a chave do destino
				decreaseKey(minHeap, destino, dist[destino]);
				pred[destino] = origem;
			}
		}
	}
	return true;
}