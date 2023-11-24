#include "list.h"
extern void InsertionSort(Item* i[]);

int main(void) {
	ElemType e[] = { 0,1,2,3 };

	Item* i1;
	i1 = ListInsertHead(e+3, ListInsertHead(e + 2, ListInsertHead(e + 1, ListInsertHead(e, NULL))));
	ListWriteStdout(i1);

	Item* v[] = { i1 };
	InsertionSort(v);
	ListWriteStdout(i1);

	return 0;
}