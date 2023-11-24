

#include "list.h"

static Item* Copy(const Item* i) {
	if (!i)return NULL;
	return ListInsertHead(&(i->value), Copy(ListGetTail(i)));
}

Item* sum(const Item* i1, const Item* i2) {

}