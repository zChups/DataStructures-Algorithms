#include "list.h"

extern int ListLength(const Item* i);

int main(void) {
	ElemType v[] = { 0,1,2,3,4,5,6,7 };
	int l;

	Item* i1 = ListInsertHead(&v[7], ListInsertHead(&v[2], NULL));
	return ListLength(i1);
}