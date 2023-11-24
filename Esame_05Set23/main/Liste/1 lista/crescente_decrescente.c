#include "list.h"

int main(void) {

	ElemType e[] = { 0,1,2,3 };

	Item* i_crescente;
	i_crescente = ListInsertHead(e, ListInsertHead(e + 1, ListInsertHead(e + 2, ListInsertHead(e + 3, NULL))));


	Item* i_decrescente;
	i_decrescente = ListInsertHead(e+3, ListInsertHead(e + 2, ListInsertHead(e + 1, ListInsertHead(e, NULL))));


	return 0;
}