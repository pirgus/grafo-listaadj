#include "grafo.h"

static int cnt;

Graph graphInit(int V){
    Graph G = (Graph) malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = (link*) malloc(sizeof(link) * V);
    for(int i = 0; i < V; i++){
        G->adj[i] = NULL;
    }

    return G;
}

//void graphInserirVertice(Graph G, vertice v){
//
//}

//void graphExluirVertice(Graph G, vertice v){
//    
//}

void graphInserirAresta(Graph G, vertice v, vertice w){
    if(v <= G->V){
        printf("Erro: indicou um vertice maior que o tamanho do grafo\n");
        return;
    }
    else if(w <= G->V){
        printf("Erro: indicou um vertice maior que o tamanho do grafo\n");
        return;
    }
    for(link a = G->adj[v]; a != NULL; a = a->next){
        printf("percorrendo o grafo\n");
        if(a->w == w)
            printf("encontrou a->w == w\n");
            return;
    }
    printf("alocando novo nodo\n");
    G->adj[v] = newNode(w, G->adj[v]);
    G->A++;
}

void graphExcluitAresta(Graph G, vertice v, vertice w){

}

void reachR(Graph G, vertice v, int *visited){
    visited = (int*) malloc(sizeof(int) * G->V);
    visited[v] = 1;
    for(link a = G->adj[v]; a != NULL; a = a->next){
        if(visited[a->w] == 0){
            free(visited), reachR(G, a->w, visited);
        }
    }
}

bool graphReach(Graph G, vertice s, vertice t){
    int *visited;
    visited = (int*) malloc(sizeof(int) * G->V);
    for(int i = 0; i < G->V; i++){
        visited[i] = 0;
    }
    reachR(G, s, visited);
    if(visited[t] == 0){
        free(visited); 
        return false;
    }
    else{
        free(visited);
        return true;
    }
}

void buscaProfundidade(Graph G){
    cnt = 0;
    int *pre;
    pre = (int*) malloc(sizeof(int) * G->V);
    for(int i = 0; i < G->V; i++){
        pre[i] = -1;
    }
    for(int i = 0; i < G->V; i++){
        if(pre[i] == -1)
            buscaRecur(G, i, pre); // nova etapa
    }
}

void buscaRecur(Graph G, vertice v, int *pre){
    pre[v] = cnt++;
    for(link a = G->adj[v]; a != NULL; a = a->next){
        int w = a->w;
        if(pre[w] == -1){
            buscaRecur(G, w, pre);
        }
    }
}

void buscaLargura(Graph G, vertice s){
    int *num;
    list queue;
    num = (int*) malloc(sizeof(int) * G->V);
    int cnt = 0;
    for(int i = 0; i < G->V; i++){
        num[i] = -1;
    }
    initList(&queue);
    num[s] = cnt++;
    insertRight(s, &queue);

    while(queue.size != 0){
        vertice v = removeLeft(&queue);
        for(link a = G->adj[v]; a != NULL; a = a->next){
            if(num[a->w] == -1){
                num[a->w] = cnt++;
                insertRight(a->w, &queue);
            }
        }
    }
    free(num);
    deleteList(&queue);
}

void graphImprime(Graph G){
    printf("G->V = %d\n", G->V);
    printf("G->A = %d\n", G->A);
    for(int i = 0; i < G->V; i++){
        printf("V%d:: ", i);
        link a = G->adj[i];
        for(link a = G->adj[i]; a != NULL; a = a->next){
            printf("%d ", a->w);
        }
        printf("\n");
    }
}

void graphDeleta(Graph G){

}