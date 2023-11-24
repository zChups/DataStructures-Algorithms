#include "list.h"

Item* InsertOrdIter(const ElemType* e, Item* i) {
	Item* tmp = i;
	while (!ListIsEmpty(ListGetTail(tmp))){
		bool I = ElemCompare(&tmp->value, e) < 0;
		Item* tmp_next = tmp->next;
		bool II = ElemCompare(&tmp_next->value, e) > 0;
		if (I && II) {
			Item* new = ListInsertHead(e, tmp->next);
			tmp->next = new;
		}

		tmp = tmp->next;
	}
}

static Item* InsertOrdRec(const ElemType* e, Item* i) {
	if (!i || ElemCompare(ListGetHeadValue(i) , e) >=  0)return ListInsertHead(e, i);

	return ListInsertHead(ListGetHeadValue(i), InsertOrdRec(e, ListGetTail(i)));

}

Item* InsertOrd(const ElemType* e, Item* i) {
	if (!e)return i;
	else if (!i)return ListInsertHead(e, NULL);
	
	InsertOrdRec(e, i);

	return i;

}
