#include "list.h"

extern int ListOccorrenze(const Item* i, const ElemType* e);

int main(void) {
	Item* i;
	ElemType e[] = { 0,1,2,1 };

	i = ListInsertHead(e, ListInsertHead(e + 1, ListInsertHead(e + 2, ListInsertHead(e+3, NULL))));
	ListWriteStdout(i);
	int o = ListOccorrenze(i, e + 1);
	return o;
}