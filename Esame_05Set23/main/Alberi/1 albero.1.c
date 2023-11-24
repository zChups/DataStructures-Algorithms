#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "tree.h"

int main(void) {
	ElemType e[] = { 0,1,2,3,4 };
	Node* t0 = TreeCreateRoot(e,
		TreeCreateRoot(e + 1, 
			TreeCreateRoot(e+3, NULL, NULL),
			NULL),
		TreeCreateRoot(e + 2, NULL, NULL)
	);
	/*		
			0
		1		2
	3
	
	*/



	_CrtDumpMemoryLeaks();
	return 0;
}