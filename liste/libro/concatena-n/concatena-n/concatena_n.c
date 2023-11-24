
#include "list.h"

Item* ConcatenaN(Item* v[], size_t v_size) {
	Item* ret = NULL;
	Item* tmp = ret;
	for (int i = 0; i < v_size; i++) {
		Item* curr_item = v[i];
		while (!ListIsEmpty(curr_item)) {
			ret = ListInsertBack(ret, &curr_item->value);
			curr_item = curr_item->next;
		}
	}
	return ret;
}