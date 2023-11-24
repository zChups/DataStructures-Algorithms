#include "list.h"

int main(void) {
	ElemType v[] = {12, 99, 37, 68};
	Item* i1 = ListInsertHead(v, ListInsertHead(v + 1, ListInsertHead(v + 2, ListInsertHead(v+3, NULL))));
	i1->next->next->next->next = i1->next;
}