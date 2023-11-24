

#include "list.h"

extern Item* Filter(Item* i, ElemType e);

int main(void) {
	ElemType e[] = { 1,2,3,4,5, 6,7,8 };
	Item * i1 = ListInsertHead(e + 2, ListInsertHead(e + 3, ListInsertHead(e + 4, ListInsertHead(e+1, NULL))));
	ListWriteStdout(i1);
	puts("");

	i1 = Filter(i1, 3);
	ListWriteStdout(i1);
	puts("");

	return 0;
}