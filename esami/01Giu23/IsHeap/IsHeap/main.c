#include "minheap.h"
extern bool IsHeap(const Heap* h);
static Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	Heap* h = HeapCreateEmpty();
	if (!v)return h;

	h->size = v_size;
	h->data = calloc(v_size, sizeof(ElemType));
	memcpy(h->data, v, v_size * sizeof(ElemType));

	for (int j = (int)h->size / 2 - 1; j >= 0; j--) {
		HeapMinMoveDown(h, j);
	}

	return h;
}

int main(void) {
	ElemType v[] = { 0,12,4,21,2,18,77,8,9 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	Heap* h = HeapCreateEmpty();

	h = HeapMinHeapify(v, v_size);
	/*
				0
			   / \
			  /   \
			 2     4
			/ \   / \
		   8  12 18 77
		  / \
		 21  9

	*/
	Heap h1 = {
		.data = {0},
		.size = 1
	};
	return IsHeap(&h1);
}

