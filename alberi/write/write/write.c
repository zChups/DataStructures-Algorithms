#define _CRT_SECURE_NO_WARNINGS

#include "tree.h"

static void TreeWriteRec(const Node* t, FILE* f, int deep) {
	if (TreeIsLeaf(t)) {
		fprintf(f, "%*s", 4 * deep, "");
		fprintf(f, ".%c\n", t->value);
		return;
	}
	fprintf(f, "%*s", 4 * deep, "");
	fprintf(f, "%c\n", t->value);
	 
	TreeWriteRec(TreeLeft(t), f, deep + 1);
	TreeWriteRec(TreeRight(t), f, deep + 1);

	return;
}

bool TreeWrite(const Node* t, const char* filename) {
	FILE* f = fopen(filename, "w");
	if (!f)return false;

	if (t)TreeWriteRec(t, f, 0);

	fclose(f);

	return true;
}