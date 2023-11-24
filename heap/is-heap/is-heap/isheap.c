#include "minheap.h"

static bool IsHeapRec(const Heap* h, int i) {
	if (i == h->size / 2 - 1)return true;

	size_t l = HeapLeft(i);
	size_t r = HeapRight(i);

	if (l < h->size && ElemCompare(h->data + l, HeapGetNodeValue(h, i)) < 0) {
		return false;
	}

	if (r < h->size && ElemCompare(h->data + r, HeapGetNodeValue(h, r)) < 0) {
		return false;
	}
	return IsHeapRec(h, l) && IsHeap(h, r);
}

bool IsHeap(const Heap* h) {
	if (!h)return false;
	return IsHeapRec(h, 0);
}