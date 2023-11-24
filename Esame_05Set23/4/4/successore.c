#include <stdint.h>

#include "tree.h"

static bool Contains(const Node* t, const Node* n) {
	if (n == t)return true;
	else if (!t)return false;

	return Contains(TreeLeft(t), n) || Contains(TreeRight(t), n);
}

static void SuccessoreRec(const Node* t, const Node* n,const Node** ret, ElemType* sux_best) {
	if (!t)return;

	ElemType sux_curr = t->value;
	if (ElemCompare(&sux_curr, &n->value) > 0) {
		if (*sux_best == 0) {
			*sux_best = sux_curr;
			*ret = t;
		}
		if (*sux_best > sux_curr) {
			*sux_best = sux_curr;
			*ret = t;
		}
	}
	SuccessoreRec(TreeLeft(t), n, ret, sux_best);
	SuccessoreRec(TreeRight(t), n, ret, sux_best);
}

const Node* Successore(const Node* t, const Node* n) {
	if (!t)return NULL;

	if (!Contains(t, n))return NULL;

	const Node* ret = TreeCreateEmpty();
	ElemType sux_best = 0;
	SuccessoreRec(t, n, &ret, &sux_best);

	return ret;
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
//	Node* t1 = TreeRight(t0);
//	Successore(t0, t1);
//
//
//	return 0;
//}