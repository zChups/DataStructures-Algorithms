#include <stdlib.h>

#include "minheap.h"



void HeapMinHeapsort(Heap* h) {
	if (!h)return;

	size_t src_size = h->size;
	ElemType* last_elem;
	while (h->size > 1) {
		last_elem = h->data + h->size - 1;
		ElemSwap(h->data, last_elem);

		h->size--;

		HeapMinMoveDown(h, 0);
	}
	h->size = src_size;
}