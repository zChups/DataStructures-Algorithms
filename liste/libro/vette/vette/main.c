#include "list.h"

extern int ContaVette(const Item* i);

int main(void) {
	ElemType e[] = { 1,2,3,4,5 };
	Item* i1 = ListInsertHead(e, ListInsertHead(e, ListInsertHead(e + 2, NULL)));

	return ContaVette(i1);
}