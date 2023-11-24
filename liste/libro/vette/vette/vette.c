#include "list.h"

static void ContaVetteRec(const Item* i, int* max, int* n_vette) {
	if (!ListGetTail(i)) {	//raggiungo l'ultimo nodo della lista
		(*n_vette)++;
		(*max) = i->value;
		return;
	}
	ContaVetteRec(i->next, max, n_vette);
	if (i->value > (*max))(*n_vette)++;
	(*max) = (*max) < i->value ? i->value : (*max);
}

int ContaVette(const Item* i) {
	if (!i)return 0;
	int n_vette = 0;
	int max = 0;
	ContaVetteRec(i, &max, &n_vette);
	return n_vette;
}