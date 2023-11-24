#define _CRT_SECURE_NO_WARNINGS

#include "tree.h"

#include <stdio.h>

static void TreeReadRec(Node** t, FILE* f) {
	ElemType c_curr;
	int read = fscanf(f, " %c", &c_curr);

	if (read != 1)return;

	if (c_curr == '.') {
		read = fscanf(f, " %c", &c_curr);
		if (read != 1)return;
		// è una foglia
		*t = TreeCreateRoot(&c_curr, NULL, NULL);
		return;
	}

	*t = TreeCreateRoot(&c_curr, NULL, NULL);

	TreeReadRec(&(*t)->left, f);
	TreeReadRec(&(*t)->right, f);

}

Node* TreeRead(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (!f)return NULL;
	
	Node* t = TreeCreateEmpty();

	TreeReadRec(&t, f);

	fclose(f);

	return t;
}