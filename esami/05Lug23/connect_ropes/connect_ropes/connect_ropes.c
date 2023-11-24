#include "minheap.h"

size_t ConnectRopes(Heap* ropes) {
	if (HeapIsEmpty(ropes))return 0;
	size_t len = 0;

	while (ropes->size >= 2) {
		len += (size_t)*ropes->data;
		ElemType* last_elem = ropes->data + ropes->size - 1;
		ElemSwap(ropes->data, last_elem);
		ropes->size--;
		HeapMinMoveDown(ropes, 0);
	}
	len += (size_t)*ropes->data;

	return len;
}