#include <math.h>

#include "list.h"

//const Item* CommonTail(const Item* i1, const Item* i2) {
//	for (; !ListIsEmpty(i1); i1 = i1->next) {
//		for (; !ListIsEmpty(i2); i2 = i2->next) {
//			if (i1 == i2) {	//ho trovato l'inizio della coda comune
//				return i1;
//			}
//		}
//	}
//	return NULL;
//}


static void FindLength(const Item* i, int* len) {
	while (i) {
		++(*len);

		i = i->next;
	}
}

static Item* SetElement(Item* i, int len) {
	for (int j = 1; j <= len; j++) {
		i = i->next;
	}
}

const Item* CommonTail(const Item* i1, const Item* i2) {
	int i1_len = 0;
	int i2_len = 0;

	FindLength(i1, &i1_len);
	FindLength(i2, &i2_len);

	int diff = abs(i1_len - i2_len);

	Item* tmp = NULL;
	
	if (i1_len > i2_len) {
		i1 = SetElement(i1, diff);
	}
	else {	// <=
		i2 = SetElement(i2, diff);
	}

	//ho due liste lunghe uguali
	for (; !ListIsEmpty(i1); i1 = i1->next,
							 i2 = i2->next) {
		if (i1 == i2)return i1;
	}
	return NULL;
}