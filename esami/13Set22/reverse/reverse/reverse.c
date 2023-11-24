#include <stdlib.h>

#include "reverse.h"

Item* Reverse(Item* list, int right) {
	if (ListIsEmpty(list))return NULL;
	int length = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp= ListGetTail(tmp))length++;

	if (length == 1 || right == 0)return list;
	right = right > length ? length : right;

	Item* prev = ListCreateEmpty();
	Item* curr = list;
	for (int j = 0; j < right; j++) {
		Item* next = curr->next;	//contiene il resto della lista
		curr->next = prev;	//costruisco la lista reversed
		prev = curr;	//mantengo il puntatore alla testa della lista reversed
		curr = next;	//mando avanti la lista
	}

	for (Item* tmp = prev; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ListIsEmpty(tmp->next)) {
			tmp->next = curr;
			break;
		}
	}
	
	return prev;
}