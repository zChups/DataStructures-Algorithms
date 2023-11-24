#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include "tree.h"

Node* TreeReadRec(FILE* f) {
	ElemType c_curr;
	int read = fscanf(f, "%c", &c_curr);
	if (read != 1)return TreeCreateEmpty();

	if (c_curr == '.') {
		fscanf(f, "%c", &c_curr);
		return TreeCreateRoot(&c_curr, NULL, NULL);
	}

	Node* l = TreeReadRec(f);
	Node* r = TreeReadRec(f);

	return TreeCreateRoot(&c_curr, l, r);
}
Node* TreeRead(const char* filename) {
	if (!filename)return NULL;
	FILE* f = fopen(filename, "r");
	if (!f)return NULL;

	Node* ret = TreeReadRec(f);

	TreeReadRec(f);

	fclose(f);
	return ret;

}