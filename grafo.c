#include "grafo.h"

static int cnt;

Graph graphInit(int V){
    Graph G = (Graph) malloc(sizeof *G);
    G->V = V;
    G->A = 0;
    G->adj = (list*) malloc(sizeof(list) * V);
    for(int i = 0; i < V; i++)
        initList(&G->adj[i]);

    return G;
}

//void graphInserirVertice(Graph G, vertice v){
//
//}

//void graphExluirVertice(Graph G, vertice v){
//    
//}

void graphInserirAresta(Graph G, vertice v, vertice w){
    if(v >= G->V){
        printf("Erro: indicou um vertice maior que o tamanho do grafo\n");
        return;
    }
    else if(w >= G->V){
        printf("Erro: indicou um vertice maior que o tamanho do grafo\n");
        return;
    }
    for(node *a = G->adj[v].first; a != NULL; a = a->next){
        //printf("percorrendo o grafo\n");
        if(a->data == w){
            //printf("encontrou a->w == w\n");
            return;
        }
    }
    //printf("alocando novo nodo\n");
    insertRight(w, &G->adj[v]);
    for(node *a = G->adj[w].first; a != NULL; a = a->next){
        //printf("percorrendo o grafo\n");
        if(a->data == v){
            //printf("encontrou a->w == w\n");
            return;
        }
    }
    insertRight(v, &G->adj[w]);
    G->A++;
}

void graphExcluirAresta(Graph G, vertice v, vertice w){
    if(v >= G->V){
        printf("Erro: indicou um vertice maior que o tamanho do grafo\n");
        return;
    }
    else if(w >= G->V){
        printf("Erro: indicou um vertice maior que o tamanho do grafo\n");
        return; 
    }

    removeSpec(w, &G->adj[v]);
    removeSpec(v, &G->adj[w]);

    G->A--;
}

void reachR(Graph G, vertice v, int *visited){
    visited = (int*) malloc(sizeof(int) * G->V);
    visited[v] = 1;
    for(node *a = G->adj[v].first; a != NULL; a = a->next){
        if(visited[a->data] == 0){
            free(visited), reachR(G, a->data, visited);
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
    if(G->A < 1){
        printf("Arestas insuficientes.\n");
        return;
    }
    
    cnt = 0;
    int *pre;
    pre = (int*) malloc(sizeof(int) * G->V);
    for(int i = 0; i < G->V; i++){
        pre[i] = -1;
    }
    for(int i = 0; i < G->V; i++){
        printf("v :: %d ", i);
        printf("pre[v] :: %d\n", pre[i]);
        if(pre[i] == -1){
            buscaRecur(G, i, pre); // nova etapa
        }
    }

}

static void buscaRecur(Graph G, vertice v, int *pre){
    pre[v] = cnt++;
    for(node *a = G->adj[v].first; a != NULL; a = a->next){
        int w = a->data;
        if(pre[w] == -1){
            buscaRecur(G, w, pre);
        }
    }
}

void buscaLargura(Graph G, vertice s){
    if(G->A < 1){
        printf("Arestas insuficientes.\n");
        return;
    }

    static int *num;
    list *queue;
    int cnt = 0;

    num = (int*) malloc(sizeof(int) * G->V);

    for(int i = 0; i < G->V; i++){
        num[i] = -1;
    }
    printf("inicializou o vetor num[] com -1s\n");

    initList(queue);
    printf("inicializou a lista auxiliar\n");

    num[s] = cnt++;
    printf("atribuiu c++ a num[s])\n");

    insertRight(s, queue);
    printf("inseriu s na lista\n");

    while(!emptyList(*queue)){
        // imprime a lista 
        printList(*queue);

        // imprime o vetor num[]
        printf("num[] = ");
        for(int i = 0; i < G->V; i++){
            printf("%d ", num[i]);
        }
        printf("\n");

        vertice v = removeLeft(queue);
        for(node *a = G->adj[v].first; a != NULL; a = a->next){
            if(num[a->data] == -1){
                num[a->data] = cnt++;
                insertRight(a->data, queue);
            }
        }
    }
    free(num);
    deleteList(queue);
}

void graphImprime(Graph G){
    printf("G->V = %d\n", G->V);
    printf("G->A = %d\n", G->A);
    for(int i = 0; i < G->V; i++){
        printf("V%d:: ", i);
        printList(G->adj[i]);
        printf("\n");
    }
}

void graphDeleta(Graph G){

}