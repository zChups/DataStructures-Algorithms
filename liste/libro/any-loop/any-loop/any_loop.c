#include "list.h"

bool AnyLoop(const Item* i) {
	Item* l = i;
	Item* t = i;

	while (!ListIsEmpty(l) && !ListIsEmpty(l->next)) {
		l = l->next->next;
		t = t->next;
		
		if (l == t)return true;
	}
	return false;
}