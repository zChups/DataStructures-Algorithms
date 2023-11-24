#include "list.h"

static Item* InsertInList(Item* list, Item* curr_item, Item* curr_i) {
	Item* first_node = list;
	while (list) {
		bool I = ElemCompare(&curr_item->value, &list->value) < 0;
		if (I) {	//inserisco l'elemento
			if (first_node == list) {	//cambio la testa della lista
				first_node->next = curr_item->next;
				curr_item->next = first_node;
				curr_i = first_node;
				return curr_item;
			}
			curr_i = curr_item;
			list->next = curr_item->next;
			curr_item->next = list;
			return first_node;
		}
		list = list->next;
	}
}

static Item* InsertionSortI(Item* l) {
	Item* tmp = l;
	Item* i = l;

	for (; !ListIsEmpty(i);) {
		tmp = i->next;
		bool I = ElemCompare(&tmp->value, &i->value) < 0;
		if (I) {	//elemento dalla sottolista non ordinata è minore di elemento corrente, devo inserirlo nella sottolista ordinata
			l = InsertInList(l, tmp, &i);
		}
		else {
			i = i->next;
		}
		ListWriteStdout(l);
	}
	return l;
}

void InsertionSort(Item* i[]){
	Item* curr_item = i[0];

	if (!curr_item)return;
	i[0] = InsertionSortI(curr_item);
}