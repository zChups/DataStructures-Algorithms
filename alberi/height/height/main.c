#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "tree.h"

extern int TreeHeight(const Node* t);

int main(void) {
	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9 };
	Node* t = TreeCreateRoot(e,
				TreeCreateRoot(e + 1,
					TreeCreateRoot(e + 2, NULL, NULL),
					TreeCreateRoot(e + 3, NULL, NULL)
				),
				TreeCreateRoot(e + 4,
					TreeCreateRoot(e + 5,
						TreeCreateRoot(e + 6, NULL, NULL),
						TreeCreateRoot(e + 7, NULL, NULL)),
					TreeCreateRoot(e + 8, NULL, NULL))
			);

	/*
			 0
		  /     \
		 1	     4
		/ \     / \
	   2   3   5   8
			  / \
			 6   7

	*/
	TreeWriteStdoutPreOrder(t);

	printf("l'albero t0 ha altezza: %d\n", TreeHeight(t));




	_CrtDumpMemoryLeaks();
	return 0;
}