#ifndef ELEMTYPE_INT_COORDS_H_
#define ELEMTYPE_INT_COORDS_H_

#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>

struct Coord {
	int x, y;
};

typedef struct Coord ElemType;

extern ElemType ElemCopy(const ElemType* e);
extern void ElemDelete(ElemType* e);
extern int ElemRead(FILE* f, ElemType* e);
extern void ElemWrite(const ElemType* e, FILE* f);
#endif // !ELEMTYPE_INT_COORDS_H_