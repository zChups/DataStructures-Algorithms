

#include "shift.h"

Item* ShiftN(Item* list, size_t n) {
	if (!list)return NULL;

	//calcolo lunghezza lista
	size_t len = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) { len++; }

	n = n >= len ? n % len + 1 : n;

	if (n == 0)return list;

	Item* head  = ListGetTail(list);
	Item* curr = list;
	Item* prev = ListCreateEmpty();
	for (size_t i = 0; i < n; i++) {
		Item* next = curr->next;
		curr->next = next->next;
		next->next = curr;
		if (!prev) {	//primo giro
			prev = next;
			head = prev;
			continue;
		}
		else {
			prev->next = next;
		}
		prev = next;
	}

	return head;
}

//int main(void) {
//	Item* i;
//	ElemType e[] = { 0,1,2,3 };
//
//	i = ListInsertHead(e, ListInsertHead(e + 1, ListInsertHead(e + 2, ListInsertHead(e + 3, NULL))));
//	ListWriteStdout(i); //0->1->2->3->NULL
//
//	i = ShiftN(i, 3);
//	ListWriteStdout(i); //0->1->2->3->NULL
//	return 0;
//}