#include "reverse.h"

int main(void) {
	Item* i;
	ElemType e[] = { 0,1,2,3 };

	i = ListInsertHead(e, ListInsertHead(e + 1, ListInsertHead(e + 2, ListInsertHead(e + 3, NULL))));
	ListWriteStdout(i);	//0->1->2->3->NULL

	i = Reverse(i, 3);
	ListWriteStdout(i);

	return 0;
}