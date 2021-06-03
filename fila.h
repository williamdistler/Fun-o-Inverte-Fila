struct elem {
  int valor;
  struct elemento* prox;
};

typedef struct {
	struct elemento* head;
  struct elemento* tail;
} QUEUE;

void enqueue(QUEUE* queue, int valor);
void dequeue(QUEUE* queue);