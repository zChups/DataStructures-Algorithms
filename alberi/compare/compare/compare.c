

#include "tree.h"

TreeAreIdenticalRec(const Node* t1, const Node* t2) {
	if (!t1 && !t2)return true;
	if (!t1 || !t2)return false;
	
	return ElemCompare(&t1->value, &t2->value) == 0 &&
		TreeAreIdenticalRec(TreeLeft(t1), TreeLeft(t2)) &&
		TreeAreIdenticalRec(TreeRight(t1), TreeRight(t2));
}

bool TreeAreIdentical(const Node* t1, const Node* t2) {
	if (!t1 && !t2)return true;
	return TreeAreIdenticalRec(t1, t2);
}