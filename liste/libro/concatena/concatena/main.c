#include "concatena.h"

int main(void) {
	ElemType e[] = { 1,2,3,4,5 };
	Item* i1 = ListInsertHead(e, ListInsertHead(e + 1, NULL));
	ListWriteStdout(i1);
	Item* i2 = ListInsertHead(e + 2, ListInsertHead(e + 3, ListInsertHead(e + 4, NULL)));
	i1 = Concatena(i1, i2, kNoCopy);
	ListWriteStdout(i1);
	puts("");
	
	i1 = ListInsertHead(e, ListInsertHead(e + 1, NULL));
	i1 = Concatena(i1, i2, kCopy);
	ListWriteStdout(i1);
	puts("");

	i1 = NULL;
	i1 = Concatena(i1, i2, kNoCopy);
	ListWriteStdout(i1);
	puts("");

	return 0;
}