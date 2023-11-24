#include "minheap.h"

void HeapMinMoveDownRec(Heap* h, int i) {
	if (i >= (int)h->size)return;

	bool a = ElemCompare(h->data + i, h->data + HeapLeft(i)) < 0;
	bool b = ElemCompare(h->data + i, h->data + HeapRight(i)) < 0;
	if ((a && b)) return;

	int l, r, smallest = i;

	l = HeapLeft(i);
	r = HeapRight(i);

	if (ElemCompare(HeapGetNodeValue(h, l), HeapGetNodeValue(h, smallest)) < 0)smallest = l;
	if (ElemCompare(HeapGetNodeValue(h, r), HeapGetNodeValue(h, smallest)) < 0)smallest = r;

	if (smallest != i)ElemSwap(h->data + i, h->data + smallest);

	HeapMinMoveDownRec(h, smallest);

}