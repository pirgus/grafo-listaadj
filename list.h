#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int tdata;

typedef struct node{
    tdata data;
    struct node *next;
} node;

typedef struct list{
    node *first;
    unsigned size;
    node *last;
} list;

list* initList(list *L);

void deleteList(list *L);

void printList(list L);

void insertLeft(tdata x, list *L);

void insertRight(tdata x, list *L);

bool emptyList(list L);

int removeLeft(list *L);

int removeRight(list *L);

node* searchList(tdata x, list L);

void insertPos(tdata x, unsigned pos, list *L);

int removePos(unsigned pos, list *L);

void removeSpec(tdata x, list *L);