#include "list.h"

void Back2Front(Item** i) {
	Item* node = *i;

	if (!node || i == NULL)return;

	for (Item* j = node; !ListIsEmpty(node); node = node->next) {
		if (!ListGetTail(node)) {	//sono all'ultimo nodo
			ElemType e_tmp = j->value;
			j->value = node->value;
			node->value = e_tmp;
		}
	}
}