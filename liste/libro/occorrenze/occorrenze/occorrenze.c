#include "list.h"

static void ListOccorrenzeRec(const Item* i, const ElemType* e,int* n_occ) {
	if (ListIsEmpty(i))return;
	if (ElemCompare(ListGetHeadValue(i), e) == 0)(*n_occ)++;
	ListOccorrenzeRec(ListGetTail(i), e, n_occ);
}
int ListOccorrenze(const Item* i, const ElemType* e) {
	int n_occ = 0;
	ListOccorrenzeRec(i, e, &n_occ);
	return n_occ;
}