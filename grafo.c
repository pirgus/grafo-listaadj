#include "grafo.h"

static int cnt;

graph* graphInit(int V){
    graph *G = (graph*) malloc(sizeof(graph));
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

void graphInserirAresta(graph *G, vertice v, vertice w){
    if(v >= G->V){
        printf("Erro: indicou um vertice maior que o tamanho do grafo\n");
        return;
    }
    else if(w >= G->V){
        printf("Erro: indicou um vertice maior que o tamanho do grafo\n");
        return;
    }
    else if(v == w){
        printf("Grafos não direcionados não podem possuir self-loop\n");
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

void graphExcluirAresta(graph *G, vertice v, vertice w){
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

void reachR(graph *G, vertice v, int *visited){
    visited = (int*) malloc(sizeof(int) * G->V);
    visited[v] = 1;
    for(node *a = G->adj[v].first; a != NULL; a = a->next){
        if(visited[a->data] == 0){
            free(visited), reachR(G, a->data, visited);
        }
    }
}

bool graphReach(graph *G, vertice s, vertice t){
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

list* buscaLargura(graph *G, vertice v){
    list *queue, *visitados;
    node *aux;
    
    queue = initList(queue);
    visitados = initList(visitados);
    //printf("inicializou as listas\n");

    if(G->A < 1){
        printf("Arestas insuficientes.\n");
        return visitados;
    }

    //printf("stack->last == %x\n", stack->last);

    insertRight(v, queue);
    //printf("inseriu na stack\n");
    while(!emptyList(*queue)){
        //printf("entrou no while\n");
        int visitado = removeLeft(queue);
        //printf("deu pop na stack\n");
        if(searchList(visitado, *visitados) == NULL)
            insertRight(visitado, visitados);
        //printf("inseriu na lista de visitados\n");
        for(node *a = G->adj[visitado].first; a != NULL; a = a->next){
            if((searchList(a->data, *queue) == NULL) && (searchList(a->data, *visitados) == NULL)){
                //printf("caminhando lista de adjacencia\n");
                insertRight(a->data, queue);
            }
        }
    }

    deleteList(queue);
    return visitados;
}

list* buscaProfundidade(graph *G, vertice v){
    list *stack, *visitados;
    node *aux;

    stack = initList(stack);
    visitados = initList(visitados);
    //printf("inicializou as listas\n");
    
    if(G->A < 1){
        printf("Arestas insuficientes.\n");
        return visitados;
    }

    if(G->A < 1){
        printf("Arestas insuficientes.\n");
        return visitados;
    }

    //printf("stack->last == %x\n", stack->last);

    insertRight(v, stack);
    //printf("inseriu na stack\n");
    while(!emptyList(*stack)){
        //printf("entrou no while\n");
        int visitado = removeRight(stack);
        //printf("deu pop na stack\n");
        if(searchList(visitado, *visitados) == NULL)
            insertRight(visitado, visitados);
        //printf("inseriu na lista de visitados\n");
        for(node *a = G->adj[visitado].first; a != NULL; a = a->next){
            if(/*(searchList(a->data, *stack) == NULL) &&*/ (searchList(a->data, *visitados) == NULL)){
                //printf("caminhando lista de adjacencia\n");
                insertRight(a->data, stack);
            }
        }
    }

    deleteList(stack);
    return visitados;

}

void graphImprime(graph *G){
    printf("G->V = %d\n", G->V);
    printf("G->A = %d\n", G->A);
    for(int i = 0; i < G->V; i++){
        printf("V%d:: ", i);
        printList(G->adj[i]);
        printf("\n");
    }
}

void graphDeleta(graph *G){
    for(int i = 0; i < G->V; i++){
        deleteList(&G->adj[i]);
    }
    free(G->adj);
    free(G);

}