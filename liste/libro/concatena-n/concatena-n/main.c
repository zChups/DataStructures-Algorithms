#include "list.h"

extern Item* ConcatenaN(Item* v[], size_t v_size);

int main(void) {
	ElemType e[] = { 1,2,3,4,5, 6,7,8 };
	Item* i1 = NULL;
	ListWriteStdout(i1);
	puts("");
	Item* i2 = ListInsertHead(e + 2, ListInsertHead(e + 3, ListInsertHead(e + 4, NULL)));
	ListWriteStdout(i2);
	puts("");
	Item* i3 = NULL;
	ListWriteStdout(i3);
	puts("");
	puts("");
	puts("");
	Item* v[] = { i1, i2 ,i3 };
	i1 = ConcatenaN(v, 3);
	ListWriteStdout(i1);

	return 0;
}