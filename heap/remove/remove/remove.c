#include <stdlib.h>

#include "minheap.h"

void DeleteNode(Heap* h, int k) {
	if (k < 0 || k >= h->size)return;
	else if (HeapIsEmpty(h))return;

	ElemSwap(&h->data[k], &h->data[h->size - 1]);
	ElemDelete(&h->data[h->size - 1]);

	h->size--;
	h->data = realloc(h->data, h->size * sizeof(ElemType));

	HeapMinMoveDown(h, k);
}