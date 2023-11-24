#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "tree.h"

extern const Node* BiggestColoredTree(const Node* t);

int main(void) {
	ElemType e[] = {'b', 'g', 'g', 'g', 'r', 'r','r'};
	Node* t = TreeCreateRoot(e,
				TreeCreateRoot(e + 1,
					TreeCreateRoot(e + 2, 
						TreeCreateRoot(e + 3, NULL, NULL),
						NULL),
					NULL
				),
				TreeCreateRoot(e + 4, 
					NULL,
					TreeCreateRoot(e + 5, 
						NULL, 
						TreeCreateRoot(e+6, NULL, NULL)))
			);

	/*
			 b
		  /     \
		 g	     r
		/         \
	   g           r
	  /  			\
	 g  			 r

	*/
	t = BiggestColoredTree(t);

	TreeWriteStdoutPreOrder(t);



	_CrtDumpMemoryLeaks();
	return 0;
}