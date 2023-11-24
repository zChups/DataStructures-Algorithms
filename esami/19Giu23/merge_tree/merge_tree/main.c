#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "tree.h"

extern Node* MergeTree(const Node* t1, const Node* t2);

int main(void) {
	ElemType e[] = { 0,1,2,3,4 };
	Node* t0 = TreeCreateRoot(e,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 3, NULL, NULL),
			NULL),
		TreeCreateRoot(e + 2, NULL, NULL)
	);
	/*
			0
		1		2
	3

	*/

	Node* t1 = TreeCreateRoot(e,
		TreeCreateRoot(e + 4,
			TreeCreateRoot(e + 3, NULL, NULL),
			NULL),
		TreeCreateRoot(e + 2, NULL, NULL)
	);
	/*
			4
		1		2
	3

	*/

	Node* t = MergeTree(t0, t1);
	TreeWriteStdoutPreOrder(t);

	_CrtDumpMemoryLeaks();
	return 0;
}