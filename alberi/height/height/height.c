//ElemType generico


#include "tree.h"

static void TreeHeightRec(const Node* t, int* i_max, int i) {
	if (TreeIsEmpty(t))return;
	if (TreeIsLeaf(t)) {	//raggiungo una foglia
		if (i > *i_max)(*i_max) = i;
		return;
	}

	TreeHeightRec(TreeLeft(t), i_max, i + 1);
	TreeHeightRec(TreeRight(t), i_max, i + 1);

}

int TreeHeight(const Node* t) {
	if (!t)return -1;
	int i_max = 0;
	TreeHeightRec(t, &i_max, 0);
	return i_max;
}