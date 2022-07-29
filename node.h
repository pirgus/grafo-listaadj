#include <stdio.h>
#include <stdlib.h>

#define vertice int

typedef struct nodeGraph *link; // link = ponteiro para node
struct nodeGraph{ // nós que corresponde a um arco e contém um
    vertice w; // vizinho w de v e o endereço do nó seguinte
    link next;
};


// funções
link newNode(vertice w, link next);