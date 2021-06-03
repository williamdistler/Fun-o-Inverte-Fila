#include <stdio.h>
#include <malloc.h>

struct elemento {
  int valor;
  struct elemento* prox;
};

typedef struct {
	struct elemento* head;
  struct elemento* tail;
} FILA;

void iniciaFila(FILA* fila) {
  fila->head = NULL;
  fila->tail = NULL;
}

void adicionar(FILA* fila, int valor) {
  struct elemento* novo = (struct elemento*) malloc(sizeof(struct elemento));

  novo->valor = valor;
  novo->prox = NULL;

  if (fila->head == NULL) fila->head = novo; // FILA ESTA VAZIA
  else fila->tail->prox = novo;

  // ADICIONANDO NO FIM
  fila->tail = novo;
}

void remover(FILA* fila) {
  if (fila->head != NULL) {
    // REMOVENDO DO COMEÇO
    struct elemento* apagar = fila->head;
    fila->head = fila->head->prox;

    free(apagar);
    
    if (fila->head == NULL) fila->tail = NULL;
  }
}

void imprimeFila(FILA* fila) {
  struct elemento* i = fila->head;

  printf("MINHA FILA :)\n");

  while(i != NULL) {
    printf("|_%d_|", i->valor);
    i = i->prox;
  }

  printf("\n\n");
}

int length(FILA* fila) {
  struct elemento* i = fila->head;
  int tamanho = 0;

  while(i != NULL) {
    tamanho++;
    i = i->prox;
  }

  return tamanho;
}

void copiaInverso(FILA* fila1, FILA* fila2) {
  for(int i = fila1->head; i < fila1->tail; i++){
    fila2->head = fila1->tail;
  }
}

int main(void) {
  FILA minhaFila;
  FILA minhaFila2;

  iniciaFila(&minhaFila);
  iniciaFila(&minhaFila2);

  adicionar(&minhaFila, 2);
  adicionar(&minhaFila, 3);
  adicionar(&minhaFila, 4);

  remover(&minhaFila);

  imprimeFila(&minhaFila);
  imprimeFila(&minhaFila2);

  return 0;
}