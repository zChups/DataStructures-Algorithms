#include <stdint.h>

#include "list.h"

Item* Taglia(Item* i, int n) {
	if (i == NULL || n == 0)return NULL;
	else if (n < 0)return i;
	Item* tmp = i;

	for (int j = 0; !ListIsEmpty(ListGetTail(tmp)); tmp = tmp->next, j++) {
		if (j + 1== n) {
			ListDelete(ListGetTail(tmp));
			tmp->next = NULL;
			break;
		}
	}
	return i;
}