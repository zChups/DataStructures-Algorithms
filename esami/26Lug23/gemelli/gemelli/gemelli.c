#include <stdbool.h>

#include "tree.h"

static bool TreesAreTwinsRec(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))return true;
	else if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}

	return TreesAreTwinsRec(TreeLeft(t1), TreeLeft(t2)) && TreesAreTwinsRec(TreeRight(t1), TreeRight(t2));
}
bool TreesAreTwins(const Node* t1, const Node* t2) {
	if (!t1 && !t2)return true;
	else if (!t1 || !t2)return false;

	return TreesAreTwinsRec(t1, t2);
}

//int main(void) {
//	ElemType e[] = { 0,1,2,3,4 };
//	Node* t0 = TreeCreateRoot(e,
//		TreeCreateRoot(e + 1,
//			TreeCreateRoot(e + 3, NULL, NULL),
//			NULL),
//		TreeCreateRoot(e + 2, NULL, NULL)
//	);
//	/*
//			0
//		1		2
//	3
//
//	*/
//
//	Node* t2 = TreeCreateRoot(e,
//		TreeCreateRoot(e + 1,
//			TreeCreateRoot(e + 3, NULL, NULL),
//			NULL),
//		TreeCreateRoot(e + 2, NULL, NULL)
//	);
//
//	Node* t1 = TreeCreateRoot(e,
//		TreeCreateRoot(e + 1,
//			NULL,
//			NULL),
//		TreeCreateRoot(e + 2, NULL, NULL)
//	);
//
//	return TreesAreTwins(t0, t0);
//
//}