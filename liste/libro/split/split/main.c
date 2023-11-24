#include "list.h"

extern Item* Split(Item* i);

int main(void) {
	ElemType e[] = { 1,2,3,4 };
	Item* i = ListInsertHead(e, ListInsertHead(e + 1, ListInsertHead(e + 2, ListInsertHead(e + 3, NULL))));
	i = Split(i);
	ListWriteStdout(i);
	return 0;
}