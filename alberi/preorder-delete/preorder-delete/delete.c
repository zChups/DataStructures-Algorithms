#include "stdlib.h"

#include "tree.h"

void TreePreOrderDelete(Node* t) {
	if (t == NULL)return;

	Node* l = t->left;
	Node* r = t->right;

	printf("%d ", t->value);
	free(t);

	TreePreOrderDelete(l);	//sotto-albero sx
	TreePreOrderDelete(r);	//sotto-albero dx

}