#include <stdlib.h>

#include "vector_list.h"

Item* Vector2List(const ElemType* v, size_t v_size, enum ConversionType c) {
	if (!v)return NULL;
	Item* i = NULL;
	
	for (int j = 0; j < v_size; j++) {
		i = c ? ListInsertHead(&v[j], i) : ListInsertBack(i, &v[j]);	//0 -> inOrder, 1 -> reversed
	}
	return i;
}

ElemType* List2Vector(const Item* i, size_t* v_size, enum ConversionType c) {
	*v_size = 0;
	if (!i) {
		return NULL;
	}
	for (const Item* tmp = i; ListIsEmpty(tmp); ListGetTail(tmp), (*v_size)++) {
		//scorro la lista per calcolarne la lunghezza
	}
	const Item* tmp = i;
	size_t dim = (*v_size);
	ElemType* r = malloc(dim * sizeof(ElemType));
	if (c == kInOrder) {
		for (int j = 0; j < dim; j++) {
			r[j] = tmp->value;
			ListGetTail(tmp);
		}
	}
	else {	//reversed
		for (int j = 0; j < dim; j++) {
			r[dim-j-1] = tmp->value;
			ListGetTail(tmp);
		}
	}
	return r;
}