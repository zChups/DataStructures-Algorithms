#include "list.h"

int main(void){

	//3 liste

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
	Item* v[] = { i1, i2 ,i3 };	//vettore di 3 liste

	return 0;
}