

#include "tree.h"

static bool TreeIsMirrorRec(Node* t1, Node* t2) {
	if (!t1 && !t2)return true;
	else if (!t1 || !t2)return false;

	return ElemCompare(&t1->value, &t2->value) == 0 &&
		TreeIsMirrorRec(TreeLeft(t1), TreeRight(t2)) &&
		TreeIsMirrorRec(TreeRight(t1), TreeLeft(t2));
	
}

bool TreeIsMirror(Node* t) {
	if (!t)return false;
	else if (TreeIsLeaf(t))return false;
	return TreeIsMirrorRec(t->left, t->right);
}