#include <stdbool.h>

#include "minheap.h"

static bool IsHeapRec(const Heap* h, int i) {
	if (i > (int)h->size / 2 - 1)return true;

	int l = HeapLeft(i);
	int r = HeapRight(i);

	bool a = ElemCompare(h->data + l, h->data + i) > 0;
	bool b = ElemCompare(h->data + r, h->data + i) > 0;

	if (l < (int)h->size && !a)return false;
	else if (r < (int)h->size && !b)return false;
	return IsHeapRec(h, l) && IsHeapRec(h, r);

}

bool IsHeap(const Heap* h) {
	if (!h)return false;
	else if (HeapIsEmpty(h) || h->size == 1)return true;

	return IsHeapRec(h, 0);
}