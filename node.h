#include <stdio.h>
#include <stdlib.h>

#define vertice int

typedef struct node *link; // link = ponteiro para node
struct node{ // nós que corresponde a um arco e contém um
    vertice w; // vizinho w de v e o endereço do nó seguinte
    link next;
};


// funções
link newNode(vertice w, link next);