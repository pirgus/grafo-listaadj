#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "node.h"
#include "list.h"

#define vertice int

struct graph{
    int V;
    int A;
    link *adj;
};

typedef struct  graph *Graph;

Graph graphInit(int V);

//void graphInserirVertice(Graph G, vertice v);

//void graphExluirVertice(Graph G, vertice v);

void graphInserirAresta(Graph G, vertice v, vertice w);

void graphExcluitAresta(Graph G, vertice v, vertice w);

void reachR(Graph G, vertice v, int *visited);

bool graphReach(Graph G, vertice s, vertice t);

void buscaProfundidade(Graph G);

void buscaRecur(Graph G, vertice v, int *pre);

void buscaLargura(Graph G, vertice s);

void graphImprime(Graph G);

void graphDeleta(Graph G);