

#include "tree.h"

static bool PercorsoSommaRec(Node* t, const ElemType* target, ElemType curr_sum) {
	if (!t) {
		if (ElemCompare(&curr_sum, target) == 0)return true;
		return false;
	}

	return PercorsoSommaRec(TreeRight(t), target, curr_sum + *TreeGetRootValue(t)) ||
		PercorsoSommaRec(TreeLeft(t), target, curr_sum + *TreeGetRootValue(t));
}

bool PercorsoSomma(Node* t, const ElemType* target) {
	if (!t)return false;
	return PercorsoSommaRec(t, target, 0);
}

/*int main(void) {
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

	
			 0
		  /     \
		 1	     4
		/ \     / \
	   2   3   5   8
			  / \
			 6   7

	
	TreeWriteStdoutPreOrder(t);

	ElemType s = 5;
	return PercorsoSomma(t, &s);
}
*/