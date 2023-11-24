#include <stdbool.h>

#include "diff_dlist.h"



static Item* Copy(const Item* i) {
	Item* ret = NULL;
	for (; !DListIsEmpty(i); i = i->next) {
		if (i->value == 0) continue;
		ret = DListInsertBack(ret, &i->value);
	}
	return ret;
}

Item* DListDiff(const Item* i1_1, const Item* i2_1) {
	if (!i1_1 && !i2_1)return NULL;
	if (!i1_1)return i2_1;
	if (!i2_1)return i1_1;
	Item* ret = DListCreateEmpty();
	
	Item* i1 = Copy(i1_1);	//tolgo gli zeri da i1, i2
	Item* i2 = Copy(i2_1);

	//mi posiziono sull'ultimo elemento della prima lista
	Item* tmp1 = i1;
	for (; !DListIsEmpty(DListGetTail(tmp1)); tmp1=tmp1->next){}
	//mi posiziono sull'ultimo elemento della seconda lista
	Item* tmp2 = i2;
	for (; !DListIsEmpty(DListGetTail(tmp2)); tmp2 = tmp2->next) {}

	//inserisco la differenza n1-n2
	for (; tmp2; tmp2 = tmp2->prev, tmp1 = tmp1->prev) {
		bool a = ElemCompare(DListGetHeadValue(tmp1), DListGetHeadValue(tmp2)) < 0;	//primo elem < secondo elem
		if (a) {
			DListGetPrev(tmp1)->value = DListGetPrev(tmp1)->value - 1;
			tmp1->value += 10;
		}
		ElemType diff = tmp1->value - tmp2->value;
		ret = DListInsertHead(&diff, ret);
	}
	//inserisco gli ultimi elementi di i1
	for (; !DListIsEmpty(tmp1) ; tmp1 = tmp1->prev) {
		ret = DListInsertHead(&tmp1->value, ret);
	}

	return ret;
}