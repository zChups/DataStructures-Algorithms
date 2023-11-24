#include "tree.h"

static bool UniformColored(Node* curr_node, int* h, ElemType* c, int i) {
	if (TreeIsEmpty(curr_node))return;
	if (TreeIsLeaf(curr_node)) {
		if (*h < i)*h = i;
		return true;
	}
	if (ElemCompare(c, TreeGetRootValue(curr_node)) != 0) {
		return false;
	}
	return UniformColored(TreeLeft(curr_node), h, c, i + 1) && UniformColored(TreeRight(curr_node), h, c, i + 1);
}

const Node* BiggestColoredTree(const Node* t) {
	if (!t)return NULL;

	Node* l = TreeLeft(t);
	Node* r = TreeRight(t);

	int l_height = 0;
	int r_height = 0;

	bool lI = UniformColored(l, &l_height, &l->value, 0);
	bool rI = UniformColored(r, &r_height, &r->value, 0);

	if (lI && rI)return l_height > r_height ? TreeLeft(t) : TreeRight(t);
	else if (lI)return TreeLeft(t);
	else if (rI)return TreeRight(t);
	else return NULL;
}