
#include "minheap.h"

bool IsHeap(const Heap* h) {
	if (!h)return false;
	if (h->size == 1)return true;
	int l, r;

	for (size_t i = 0; i < h->size / 2 - 1; i++) {
		l = HeapLeft(i);
		r = HeapRight(i);

		if (ElemCompare(h->data + i, h->data + l) > 0)return false;
		if (ElemCompare(h->data + i, h->data + r) > 0)return false;

	}

	return true;
}