#include "no_dups.h"

static void Copy(const Item* i, Item** ret) {
	if (!i) {
		return;
	}

	Copy(ListGetTail(i), ret);
	*ret = ListInsertHead(&i->value, *ret);
}

static Item* RemoveDuplicatesRec(Item* i, ElemType* curr_val) {
	if (!i)return NULL;
	Item* tmp = NULL;
	if (ElemCompare(&i->value, curr_val) == 0) {	// ho trovato il duplicato
		tmp = i->next;
		free(i);
		return tmp;
	}
	tmp = ListInsertHead(&i->value, RemoveDuplicatesRec(ListGetTail(i), curr_val));

	return tmp;
}
Item* RemoveDuplicates(const Item* i) {
	if (!i)return NULL;
	Item* i_copied = ListCreateEmpty();
	Copy(i, &i_copied);
	for (Item* tmp = i_copied; !ListIsEmpty(ListGetTail(tmp)); tmp = ListGetTail(tmp)) {
		i_copied = RemoveDuplicatesRec(ListGetTail(tmp), &tmp->value);
	}
	return i_copied;
}

//int main(void) {
//	Item* i;
//	ElemType e[] = { 0,1,2,1 };
//
//	i = ListInsertHead(e, ListInsertHead(e + 1, ListInsertHead(e + 2, ListInsertHead(e + 1, NULL))));
//	ListWriteStdout(i); //0->1->2->1->NULL
//
//	RemoveDuplicates(i);
//	ListWriteStdout(i); //0->1->2->3->NULL
//	return 0;
//}