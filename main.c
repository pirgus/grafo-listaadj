#include "grafo.h"

int main(){
    Graph grafo;
    int vertices, v1, v2;

    printf("quantos vertices no grafo? ");
    scanf("%d", &vertices);
    printf("\n");
    grafo = graphInit(vertices);

    while(true){
        printf("grafo atual:: ");
        graphImprime(grafo);

        printf("adicionar aresta entre os vertices :: ");
        scanf("%d %d", &v1, &v2);
        graphInserirAresta(grafo, v1, v2);

        //printf("excluindo aresta criada...\n");
        //graphExcluirAresta(grafo, v1, v2);
    }

    return 0;

}