#include "colormap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool Constrains(const struct SquareMatrix* m, int i, char* vcurr, char color) {
	int r = i;
	for (int c = 0; c < i; c++) {
		if (m->data[r * (int)m->side + c] && color == vcurr[c])return false;
	}
}

static void ColorMapRec(const struct SquareMatrix* m, const char* c, char* vcurr, int* nsol, int i) {
	if (i == (int)m->side) {
		(*nsol)++;
		for (int j = 0; j < m->side; j++) {
			printf("%i -> %c; ", j, vcurr[j]);
		}
		puts("");
		return;
	}

	for (int j = 0; c[j] != 0; j++) {
		if (Constrains(m, i, vcurr, c[j])) {	//il colore è presente in aree adiacenti

		}
	}


}

int ColorMap(const struct SquareMatrix* m, const char* c) {
	char* vcurr = malloc(m->side);
	int nsol = 0;
	ColorMapRec(m, c, vcurr, &nsol, 0);
	free(vcurr);
	return nsol;
}