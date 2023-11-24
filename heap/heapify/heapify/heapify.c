#include <stdlib.h>
#include <string.h>

#include "minheap.h"

Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	Heap* h = HeapCreateEmpty();
	if (!v)return h;

	h->size = v_size;
	h->data = calloc(v_size, sizeof(ElemType));
	memcpy(h->data, v, v_size * sizeof(ElemType));

	for (int j = (int)h->size/2 -1; j >= 0; j--) {
		HeapMinMoveDown(h, j);
	}
	
	return h;
}