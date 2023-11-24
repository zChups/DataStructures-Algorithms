#include "list.h"

extern Item* InsertOrd(const ElemType* e, Item* i);
extern Item* InsertOrdIter(const ElemType* e, Item* i);

int main(void) {

	ElemType e[] = { 0,1,2,3 };

	Item* i_crescente;
	i_crescente = ListInsertHead(e, ListInsertHead(e + 1, ListInsertHead(e + 3, NULL)));
	ListWriteStdout(i_crescente);

	Item* i = i_crescente;
	i = InsertOrdIter(e + 2, i);
	ListWriteStdout(i);



	return 0;
}