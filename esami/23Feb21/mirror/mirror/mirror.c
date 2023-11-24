

#include "tree.h"

static bool TreeIsMirrorRec(Node* l, Node* r) {
	if (!l && !r)return true;
	else if (!l || !r)return false;
	else if (ElemCompare(TreeGetRootValue(l), TreeGetRootValue(r)) != 0)return false;

	return TreeIsMirrorRec(TreeLeft(l), TreeRight(r)) && TreeIsMirrorRec(TreeRight(l), TreeLeft(r));
}

bool TreeIsMirror(Node* t) {
	if (!t || (!TreeLeft(t) && !TreeRight(t)))return true;

	return TreeIsMirrorRec(TreeLeft(t), TreeRight(t));
}

/*
int main(void) {
	ElemType e[] = { 0,1,2,3,4 };
	Node* t0 = TreeCreateRoot(e,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 3, NULL, NULL),
			NULL),
		TreeCreateRoot(e + 1, 
			NULL, 
			NULL)
	);
	
			0
		1		2
	3				3

	

	

	TreeIsMirror(t0);

	return 0;
}
*/