
#include "tree.h"

static bool TreeContainsNode(const Node* tree, const Node* node) {
	if (tree == node)return true;
	if (!tree)return false;
	return TreeContainsNode(TreeLeft(tree), node) || TreeContainsNode(TreeRight(tree), node);
}

static void LowestCommonAncestorRec(const Node* t, const Node* n1, const Node* n2, int* i_max, const Node** ret, int i) {
	if (!t)return;
	
	if (TreeContainsNode(t, n1) && TreeContainsNode(t, n2)) {
		if (i >= *i_max) {
			*ret = t;
			*i_max = i;
		}
		LowestCommonAncestorRec(TreeLeft(t), n1, n2, i_max, ret, i + 1);
		LowestCommonAncestorRec(TreeRight(t), n1, n2, i_max, ret, i + 1);
	}
}

const Node* LowestCommonAncestor(const Node* t, const Node* n1, const Node* n2) {
	int i_max = 0;
	const Node* ret = TreeCreateEmpty();
	LowestCommonAncestorRec(t, n1, n2, &i_max, &ret, 0);

	return ret;
}

