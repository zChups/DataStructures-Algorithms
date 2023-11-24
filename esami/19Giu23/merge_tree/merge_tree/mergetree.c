#include "tree.h"

static void MergeTreeRec(const Node* t1,const Node* t2, Node** ret) {
	if (!t1 && !t2) {
		*ret = NULL;
		return;
	}

	if (t1 && t2) {	//sommo i valori
		ElemType sum = *TreeGetRootValue(t1) + *TreeGetRootValue(t2);
		*ret = TreeCreateRoot(&sum, NULL, NULL);
		MergeTreeRec(t1->left, t2->left, &(*ret)->left);
		MergeTreeRec(t1->right, t2->right, &(*ret)->right);
	}
	else if (t1) {	//non considero t2
		*ret = TreeCreateRoot(TreeGetRootValue(t1), NULL, NULL);
		MergeTreeRec(t1->left, NULL, &(*ret)->left);
		MergeTreeRec(t1->right, NULL, &(*ret)->right);
	}
	else if (t2) {	//non considero t1
		*ret = TreeCreateRoot(TreeGetRootValue(t2), NULL, NULL);
		MergeTreeRec(NULL, t2->left, &(*ret)->left);
		MergeTreeRec(NULL, t2->right, &(*ret)->right);
	}

}

Node* MergeTree(const Node* t1, const Node* t2) {
	if (!t1 && !t2)return NULL;
	Node* ret = NULL;
	MergeTreeRec(t1, t2, &ret);
	return ret;
}