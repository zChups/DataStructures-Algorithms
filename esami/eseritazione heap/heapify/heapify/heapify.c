#include <stdint.h>

#include "minheap.h"

static void HeapMinHeapifyRec(const ElemType* v, size_t v_size, size_t i, Heap** h) {
	if (i >= v_size)return;
	HeapMinInsertNode(*h, v + i);
	HeapMinHeapifyRec(v, v_size, i + 1, h);
}

Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	if (v_size == 0 || !v)return HeapCreateEmpty();

	Heap* ret = HeapCreateEmpty();

	HeapMinHeapifyRec(v, v_size, 0, &ret);

	return ret;
}