
#include "cc.h"



static void ComponentiConnesseRec(const Item* i, const ElemType* v, size_t v_size, int* nsol, bool* taken) {
	ElemType curr;
	for (size_t j = 0; j < v_size; j++) {	//scorro l'array
		if (taken[j])continue;	//controllo se ho gia preso questo elemento
		curr = v[j];
		for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {	//scorro la lista
			if (ElemCompare(ListGetHeadValue(tmp), &curr) == 0) {	//controllo se i successivi elementi delle lista li ho nell'array
				(*nsol)++;	//aggiungo la soluzione corrente
				taken[j] = 1;
				//controllo se il prox elemento della lista è presente nell'array
				tmp = ListGetTail(tmp);
				if (!tmp)break;
				for (size_t j = 0; j < v_size; j++) {
					if (taken[j])continue;
					ElemType curr_sec = v[j];
					if (ElemCompare(ListGetHeadValue(tmp), &curr_sec) == 0) {
						taken[j] = 1;
						tmp = ListGetTail(tmp);
					}
					else {
						break;
					}
				}
			}
		}
		
	}
}

int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size) {
	if (!i || v_size == 0 || !v)return 0;

	int nsol = 0;

	bool* taken = calloc(v_size, sizeof(bool));

	ComponentiConnesseRec(i, v, v_size, &nsol, taken);

	free(taken);

	return nsol;
}

/*int main(void) {
	Item* i;
	ElemType e[] = { 0,1,2,3, 4 };

	i = ListInsertHead(e, ListInsertHead(e + 1, ListInsertHead(e + 2, ListInsertHead(e + 3, ListInsertHead(e+4, NULL)))));
	ListWriteStdout(i); //0->1->2->3->4->NULL

	ElemType v[] = { 1,2,4 };
	size_t dim = 3;

	return ComponentiConnesse(i, v, dim);

}
*/