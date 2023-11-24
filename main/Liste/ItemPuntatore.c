#include "list.h"

extern void Back2Front(Item** i);

int main(void) {

	ElemType e[] = { 1,2,3,4,5, 6,7,8 };
	Item* i2 = ListInsertHead(e + 2, ListInsertHead(e + 3, ListInsertHead(e + 4, NULL)));
	ListWriteStdout(i2);

	Item* v[] = { i2 };	//vettore di 1 lista
	Item** i = &v[0];

	
	return 0;
}