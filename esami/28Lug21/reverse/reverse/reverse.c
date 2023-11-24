#include "list.h"

Item* Reverse(Item* i) {
	if (!i)return NULL;

	Item* prev = ListCreateEmpty();
	Item* curr = i;

	while (curr) {
		Item* next = curr->next;	//mantengo il resto della lista
		curr->next = prev;	//costruisco la lista reversed
		prev = curr;	//mantengo il puntatore alla testa della lista reversed
		curr = next;	//riparto dalla lista senza il primo elemento
	}

	return prev;
}

//int main(void) {
//	Item* i;
//	ElemType e[] = { 0,1,2,3 };
//
//	i = ListInsertHead(e, ListInsertHead(e + 1, ListInsertHead(e + 2, ListInsertHead(e + 3, NULL))));
//	ListWriteStdout(i); //0->1->2->3->NULL
//
//	i = Reverse(i);
//	ListWriteStdout(i); 
//	return 0;
//}