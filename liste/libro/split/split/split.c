
#include "list.h"

Item* Split(Item* i) {
	if (i == NULL)return NULL;
	int i_size;
	Item* tmp = i;

	//calcolo lungheza lista
	for (i_size = 0; !ListIsEmpty(tmp); i_size++, tmp= tmp->next) {}

	int taglio;
	taglio = (i_size % 2 == 0) ? i_size / 2 : i_size / 2 + 1;

	tmp = i;	//resetto il puntatore alla testa lista
	Item* ret;
	for (int j = 0; ; j++, tmp = tmp->next) {
		if (j == taglio - 1) {
			ret = ListGetTail(tmp);
			tmp->next = NULL;
			break;
		}
	}
	return ret;
}