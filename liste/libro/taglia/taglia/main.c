#include "list.h"

extern Item* Taglia(Item* i, int n);

int main(void) {
	Item* i;
	ElemType e[] = { 1,2,3,4 };
	i = ListInsertHead(e, ListInsertHead(e+1, ListInsertHead(e+2, NULL)));
	i = Taglia(i, 2);
	ListWriteStdout(i);
	return 0;
}