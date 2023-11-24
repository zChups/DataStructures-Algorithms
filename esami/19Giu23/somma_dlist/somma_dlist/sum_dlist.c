#include <stdlib.h>

#include "doublelist.h"

static void DlistCopyRecNull(const Item* i1, Item** ret) {
	if (DListIsEmpty(i1)) {
		return;
	}
	DlistCopyRecNull(i1->next, ret);
	*ret = DListInsertHead(&i1->value, *ret);


}

static Item* DlistCopy(const Item* i) {
	Item* ret = NULL;
	DlistCopyRecNull(i, &ret);
	return ret;
}

Item* DListSum(const Item* i1, const Item* i2) {
	if (!i1 && !i2)return NULL;
	else if (!i1)return DlistCopy(i2);
	else if (!i2)return DlistCopy(i1);

	Item* I1 = DlistCopy(i1);
	Item* I2 = DlistCopy(i2);
	Item* ret = DListCreateEmpty();

	int I1_count = 0;
	int I2_count = 0;

	//conto il numero di elementi
	for (Item* tmp = I1; !DListIsEmpty(tmp); tmp = tmp->next) { I1_count++; }
	for (Item* tmp = I2; !DListIsEmpty(tmp); tmp = tmp->next) { I2_count++; }
	
	Item* tmp = NULL;
	if (I1_count < I2_count) {	//swap
		tmp = I1;
		I1 = I2;
		I2 = tmp;
	}

	//mi posiziono sugli ultimi elementi
	while (!DListIsEmpty(DListGetTail(I1))) {
		I1 = I1->next;
	}
	while (!DListIsEmpty(DListGetTail(I2))) {
		I2 = I2->next;
	}

	while (!DListIsEmpty(I1)) {
		ElemType curr_sum = 0;
		if (!DListIsEmpty(I2)) {
			curr_sum = I1->value + I2->value;
		}
		else {
			curr_sum = I1->value;
		}

		if (curr_sum >= 10) {	//ho 1 di riporto
			if (!DListIsEmpty(I1->prev)) {
				I1->prev->value += 1;
			}
			else {
				ElemType val = curr_sum / 10;
				DListInsertHead(&val, I1);	//creo un elemento per il riporto
			}
			curr_sum %= 10;
		}

		ret = DListInsertHead(&curr_sum, ret);

		I1 = I1->prev;
		if (!DListIsEmpty(I2))I2 = I2->prev;
	}

	free(I1);
	free(I2);

	return ret;
}