#define _CRT_SECURE_NO_WARNINGS

#include "list.h"

Item* ListLoad(const char* filename) {
	FILE* f;
	if (!(f = fopen(filename, "r"))) {
		return NULL;
	}
	//leggo da file
	ElemType e;
	Item* i = NULL;
	while (1) {
		if (ElemRead(f, &e) != 2)break;
		i = ListInsertHead(&e, i);
	}
	fclose(f);
	return i;
}