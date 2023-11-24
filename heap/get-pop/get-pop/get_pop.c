#include <stdlib.h>s

#include "get_pop.h"

ElemType* Get(const Heap* h) {
	if (!h || HeapIsEmpty(h))return NULL;
	return h->data;
}

void Pop(Heap* h) {
	if (!h || HeapIsEmpty(h)) return NULL;

	ElemSwap(h->data, h->data + h->size - 1);
	ElemDelete(h->data + h->size - 1);

	h->size--;
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	HeapMinMoveDown(h, 0);
}

