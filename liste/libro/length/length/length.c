#include "list.h"

int ListLength(const Item* i) {
	if (ListIsEmpty(i))return 0;
	return 1 + ListLength(ListGetTail(i));
}