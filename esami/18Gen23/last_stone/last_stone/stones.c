#include <stdlib.h>

#include "maxheap.h"

int LastStoneWeight(Heap* h) {
	size_t max_sec;

	if (HeapIsEmpty(h))return 0;
	else if (h->size == 1) return h->data[0];

	max_sec = ElemCompare(h->data + 1, h->data + 2) <= 0 ? 2 : 1;

	if (ElemCompare(h->data + 1, h->data + 2) == 0) {	//elimino entrambe
		ElemSwap(h->data, h->data + h->size - 1);
		ElemSwap(h->data + max_sec, h->data + h->size - 2);
		h->size -= 2;
		h->data = realloc(h->data, h->size * sizeof(ElemType));
		HeapMaxMoveDown(h, max_sec);
		HeapMaxMoveDown(h, 0);
	}
	else {	//elimino la minore e sistemo la maggiore
		h->data[0] -= h->data[max_sec];
		ElemSwap(h->data + max_sec, h->data + h->size - 1);
		h->size--;
		h->data = realloc(h->data, h->size * sizeof(ElemType));
		HeapMaxMoveDown(h, max_sec);
	}

	return LastStoneWeight(h);
}