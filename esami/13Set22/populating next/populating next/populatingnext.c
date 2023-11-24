#include "tree.h"

static void PopulatingNextRec(Node* t, Node** prev) {
	if (!t) {
		return;
	}

	PopulatingNextRec(t->left, prev);
	if (*prev) {
		(*prev)->next = t;
	}
	*prev = t;
	PopulatingNextRec(t->right, prev);
}

void PopulatingNext(Node* t) {
	if (!t)return;

	Node* prev = TreeCreateEmpty();

	PopulatingNextRec(t, &prev);
}

int main(void) {
	ElemType e[] = { 0,1,2,3,4,5,6,7,8,9 };
	Node* t = TreeCreateRoot(e,
		TreeCreateRoot(e + 1,
			TreeCreateRoot(e + 2, NULL, NULL),
			TreeCreateRoot(e + 3, NULL, NULL)
		),
		TreeCreateRoot(e + 4,
			TreeCreateRoot(e + 5,
				TreeCreateRoot(e + 6, NULL, NULL),
				TreeCreateRoot(e + 7, NULL, NULL)),
			TreeCreateRoot(e + 8, NULL, NULL))
	);

	/*
			 0
		  /     \
		 1	     4
		/ \     / \
	   2   3   5   8
			  / \
			 6   7

	*/

	TreeWriteStdoutPreOrder(t);

	PopulatingNext(t);


	return 0;
}
