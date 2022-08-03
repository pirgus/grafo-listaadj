#include "grafo.h"

int main(){
    graph *grafo;
    list *visitados;
    int vertices, v1, v2;
    int opc;
    char enter;

    printf("quantos vertices no grafo? ");
    scanf("%d", &vertices);
    printf("\n");
    grafo = graphInit(vertices);
    system("read -p 'Pressione Enter...' var");

    while(true){
        system("clear");
        printf("*********** Menu ***********\n");
        printf("1) Inserir aresta\n");
        printf("2) Excluir aresta\n");
        printf("3) Imprimir grafo\n");
        printf("4) Busca em profundidade\n");
        printf("5) Busca em largura\n");
        printf("100) Sair\n");

        printf("digite sua opção:: ");
        scanf("%d", &opc);
        printf("\n");

        switch(opc){
            case 1:
                printf("adicionar aresta entre os vertices :: ");
                scanf("%d %d", &v1, &v2);
                graphInserirAresta(grafo, v1, v2);
                system("read -p 'Pressione Enter...' var");
            break;

            case 2:
                printf("excluir aresta entre os vertices :: ");
                scanf("%d %d", &v1, &v2);
                graphExcluirAresta(grafo, v1, v2);
                system("read -p 'Pressione Enter...' var");
            break;

            case 3:
                printf("grafo atual:: ");
                graphImprime(grafo);   
                system("read -p 'Pressione Enter...' var");
            break;

            case 4:
                printf("busca em profundidade\n");
                visitados = buscaProfundidade(grafo, 0);
                printList(*visitados);
                system("read -p 'Pressione Enter...' var");
            break;

            case 5:
                printf("busca em largura\n");
                printf("qual vertice? :: ");
                scanf("%d", &v1);
                visitados = buscaLargura(grafo, v1);
                printList(*visitados);
                system("read -p 'Pressione Enter...' var");
            break;

            case 100:
                graphDeleta(grafo);
                printf("até mais!\n");
                return 0;
        }
    }

    return 0;

}