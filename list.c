#include "list.h"

void initList(list *L){
  // inicializa todos os aspectos da lista como NULL ou 0
  L = (list*) malloc(sizeof(list));

  L->first = NULL;
  L->last = NULL;
  L->size = 0;
  printf("inicializou a lista.\n");
}

void deleteList(list *L){
  node *p = L->first;

  while(p){
    L->first = L->first->next;
    free(p); // libera o espaço de memoria alocado daquela posição
    p = L->first; // ate que a lista termine
  }

  L->size = 0;
  L->last = NULL;
}

void printList(list L){
  node *p = L.first;

  while(p){
    printf("%d ", p->data);
    p = p->next;
    //printf("L.last->data = %d", L.last->data);
  }
  printf("\n");

}

void insertLeft(tdata x, list *L){
  node *aux;
  aux = (node*) malloc(sizeof(node));

  if(aux == NULL)
    return; // erro ao alocar memoria
  else{
    aux->data = x; // insere o valor de x no nó
    aux->next = L->first; // o novo elemento é inserido antes do atual primeiro
    L->first = aux; // aux é o novo primeiro
    if(L->last == NULL)
      L->last = aux;    // ajuste do ultimo elemento
    L->size++; // aumenta o tamanho da lista
  }
}

void insertRight(tdata x, list *L){
  node *aux = (node*) malloc(sizeof(node));

  if(aux == NULL) // nao conseguiu alocar aux
    return; // retorna com erro
  else{
    aux->data = x;
    aux->next = NULL; // pois é o ultimo elemento da lista
    if(L->last == NULL) // a lista está vazia
      L->first = L->last = aux;
    else{
      L->last->next = aux;
      L->last = aux;
    }
    L->size++; // aumentou o tamanho da lista
  }
  //printf("l.last.data = %d\n", L->last->data);
}

bool emptyList(list L){
  return (L.size == 0);
}

int removeLeft(list *L){
  node *aux = L->first; // guarda o nó que será deletado
  int vertice;

  L->first = L->first->next;
  vertice = aux->data;
  free(aux);
  if(L->first == NULL) // se ao deletar esse nó, a lista ficou vazia
    L->last = NULL;   // atribui NULO ao ultimo elemento
  L->size--; // diminuiu o tamanho da lista

  return vertice;
}

void removeRight(list *L){
  node *aux = L->last;

  if(L->first == L->last){ // lista com um unico elemento
    free(aux);
    L->first = L->last = NULL;
  }
  else{
    L->last = L->first; // o ultimo elemento recebe o primeiro elemento
    while(L->last->next != aux){  // enquanto o elemento seguinte for diferente do elemento que será excluido
      L->last = L->last->next; // o ultimo elemento vai "seguindo para frente"
    }
    free(aux);
    L->last->next = NULL;
  }
  L->size--; // diminuiu o tamanho da lista
}

node* searchList(tdata x, list L){
  node *aux = L.first;

  while(aux && x != aux->data){ // enquanto aux nao for nulo e
    aux = aux->next;            // o dado x for diferente do dado de aux
  }

  return aux;
}

void insertPos(tdata x, unsigned pos, list *L){
  // verifica se a posição é possível considerando o tamanho da lista
  if(pos > L->size - 1){
    return;
  }
  else{
    // se quiser inserir na posição 0 chama insertLeft
    if(pos == 0){
      return insertLeft(x, L);
    }
    else if(pos == L->size){ // se quiser inserir na ultima pos, chama insertRight
      return insertRight(x, L);
    }
    else{
      node *p1 = L->first, *aux;
      unsigned i = 0;

      aux = (node*) malloc(sizeof(node));
      if(!aux){
        return; // nao conseguiu alocar aux
      }

      while(i++ < pos){ // itera até a posição
        p1 = p1->next;
      }
      aux->data = x;  // insere dado no nó auxiliar
      aux->next = p1->next; // o nó seguinte de aux é o nó seguinte de p1
      p1->next = aux;     // o nó seguinte de p1 agora é o nó aux
      L->size++; // aumentou o tamanho da lista
    }
  }
}

void removePos(unsigned pos, list *L){
  // verifica se a posição é possível
  if(pos > L->size - 1){
    return;
  }
  else if(pos == 0){ // remoção pela esquerda
    return removeLeft(L);
  }
  else if(pos == L->size - 1){ // remoção pela direita
    return removeRight(L);
  }
  else{
    node *p1 = L->first, *p2 = NULL;
    unsigned i = 0;

    while(i++ < pos){ // procura o lugar onde vai remover
      p1 = p1->next;
    }

    //ação de remover
    p2 = p1->next;
    p1->next = p2->next;
    free(p2);
    L->size--; // diminuiu o tamanho da lista
  }
}

void removeSpec(tdata x, list *L){
  node *ant = NULL; // ponteiro para o elemento anterior
  node *p = L->first; // ponteiro para percorrer a lista

  // vai percorrer a lista procurando o elemento x
  while(p != NULL && p->data != x){
    ant = p;
    p = p->next;
  }

  // verifica se o elemento existe na lista
  if(p == NULL){
    printf("o elemento não existe na lista\n");
    return;
  }

  // nao entrou no erro, entao retira o elemento
  if(ant == NULL){
    // retira o elemento do inicio
    removeLeft(L);
  }
  else if(p->next == NULL){
    // retira um elemento do final da lista
    removeRight(L);
  }
  else{
    // remove elemento do meio da lista
    ant->next = p->next;
  }

  free(p);
}