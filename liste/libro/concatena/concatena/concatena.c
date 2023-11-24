#include "concatena.h"

Item* Concatena(Item* i1, Item* i2, enum ConcType c) {
	if (c == kCopy) {
		Item* i = NULL;
		while (!ListIsEmpty(i1)) {
			i = ListInsertBack(i, ListGetHeadValue(i1));
			i1 = i1->next;
		}
		while (!ListIsEmpty(i2)) {
			i = ListInsertBack(i, ListGetHeadValue(i2));
			i2 = i2->next;
		}
		return i;
	}
	else {	//kNoCopy
		if (!i1 && !i2)return i1;
		else if (i1 && !i2)return i1;
		else if (!i1 && i2)return i2;

		for (Item* tmp = i1; ; tmp = tmp->next) {
			if (ListIsEmpty(ListGetTail(tmp))) {
				tmp->next = i2;
				break;
			}
		}
		return i1;
	}
}