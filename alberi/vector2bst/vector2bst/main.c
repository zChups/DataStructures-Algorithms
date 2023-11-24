

#include "tree.h"
extern Node* Vector2Bst(const ElemType* v, size_t v_size);

int main(void) {
	ElemType v[] = { 1,2,3,4,5,6 };
	size_t v_size = sizeof(v) / sizeof(ElemType);
	Node* t = Vector2Bst(v, v_size);

	TreeWriteInOrder(t, stdout);

	TreeDelete(t);
	return 0;
}
