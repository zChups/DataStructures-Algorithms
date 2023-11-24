#include "list.h"
#include <stdlib.h>

//
//Item* Filter(Item* i, ElemType e) {
//	if (!i)return NULL;
//	while (ListGetTail(i) && i->value >= e) {
//		i = i->next;
//	}
//	Item* tmp = i;
//	while (ListGetTail(tmp) && tmp) {
//		if (ListGetTail(tmp)->value >= e) {
//			tmp->next = (tmp->next)->next;
//			continue;
//		}
//		tmp = tmp->next;
//	}
//	return i;
//}

Item* Filter(Item* i, ElemType e) {
	if (!i)return NULL;

	Item* rnext = Filter(i->next, e);

	if (i->value >= e) {
		free(i);
		return rnext;
	}
	else {
		i->next = rnext;
		return i;
	}
}