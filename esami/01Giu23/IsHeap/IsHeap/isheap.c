#include "minheap.h"

static bool IsHeapRec(const Heap* h, size_t i) {
	if (i > h->size/2-1)return true;
	size_t l = HeapLeft(i);
	size_t r = HeapRight(i);
	if (l < h->size && ElemCompare(h->data + i, h->data + l) > 0)return false;
	if (r < h->size && ElemCompare(h->data + i, h->data + r) > 0)return false;
	return IsHeapRec(h, l) && IsHeapRec(h, r);
}

bool IsHeap(const Heap* h) {
	if (!h)return false;
	else if (HeapIsEmpty(h) || h->size == 1)return true;
	return IsHeapRec(h, 0);
}