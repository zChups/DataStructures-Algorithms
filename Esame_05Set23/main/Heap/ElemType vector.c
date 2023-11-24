#include "minheap.h"

int main(void) {
	ElemType v[] = { 0,12,4,21,2,18,77,8,9 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	Heap* h = HeapCreateEmpty();

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
	
	HeapDelete(h);
}

