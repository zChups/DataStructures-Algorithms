#include <stdlib.h>

#include "minheap.h"

bool HeapMinPop(Heap* h, ElemType* e) {
	if (HeapIsEmpty(h))return false;
	*e = ElemCopy(h->data);
	f
	ElemSwap(h->data, h->data + h->size - 1);
	h->size--;
	realloc(h->data, h->size * sizeof(ElemType));

	HeapMinMoveDown(h, 0);

	return true;
}