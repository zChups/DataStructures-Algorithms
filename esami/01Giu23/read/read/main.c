#define _CRTDBG_MAP_ALLOC

#include <stdlib.h>
#include <crtdbg.h>

#include "tree.h"

extern Node* TreeRead(const char* filename);

int main(void) {
	char* filename = "albero1.txt";
	Node* t = TreeRead(filename);
	TreeWriteStdoutPreOrder(t);

	_CrtDumpMemoryLeaks();
	return 0;
}