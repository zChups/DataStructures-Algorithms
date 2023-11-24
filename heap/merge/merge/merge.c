#include "minheap.h"

Heap* HeapMerge(const Heap* h1, const Heap* h2) {
	Heap* h_merged = HeapCreateEmpty();

	if (h1) {
		for (size_t j = 0; j < h1->size; j++) {
			h_merged->data[j] = ElemCopy(h1->data + j);
		}
	}
	if (h2) {
		for (size_t j = 0; j < h2->size; j++) {
			h_merged->data[j] = ElemCopy(h2->data + j);
		}
	}

}