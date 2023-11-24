#include <stdlib.h>

#include "minheap.h"

Heap* HeapCopy(const Heap* h) {
	if (h->size == 0 || !h)return NULL;

	Heap ret = {
		.data = calloc(h->size, sizeof(ElemType)),
		.size = h->size
	};

	for (size_t i = 0; i < h->size; i++) {
		ret.data[i] = ElemCopy(h->data + i);
	}

	return &ret;
}