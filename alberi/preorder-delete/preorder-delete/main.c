#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "tree.h"

extern void TreePreOrderDelete(Node* t);

int main(void) {
	ElemType e[] = { 0,1,2,3,4 };
	Node* t0 = TreeCreateRoot(e,
		TreeCreateRoot(e + 1, NULL, NULL),
		TreeCreateRoot(e + 2, NULL, NULL)
	);
	/*	0
	1		3*/

	TreePreOrderDelete(t0);

	_CrtDumpMemoryLeaks();
	return 0;
}