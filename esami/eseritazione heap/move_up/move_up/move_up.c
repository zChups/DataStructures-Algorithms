

#include "minheap.h"

void HeapMinMoveUpRec(Heap* h, int i) {
	if (i <= 0 || ElemCompare(h->data + i, h->data + HeapParent(i)) > 0) return;
	else {
		ElemSwap(h->data + i, h->data + HeapParent(i));
	}
	HeapMinMoveUpRec(h, HeapParent(i));
}