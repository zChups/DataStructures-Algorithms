#include <stdio.h>

#include "torrecartoni.h"

static void TorreCartoniRec(const Cartone* c, size_t n, int* c_taken, int* vcurr, int i,
								int curr_height, int* best_height, int* vbest, int curr_weight, int cnt) {
	if (cnt == n) {
		if (*best_height < curr_height) {
			for (size_t j = 0; j < n; j++) {
				vbest[j] = vcurr[j];
			}
			*best_height = curr_height;
		}

		return;
	}

	for (size_t j = 0; j < n; j++) {
		if (c_taken[j] != 1) {	//prendo il cartone in posizione j
			if (c[j].l < (unsigned int)curr_weight)continue;
			vcurr[i] = j;
			c_taken[j] = 1;
			curr_weight += c[j].p;
			curr_height += c[j].a;
			TorreCartoniRec(c, n, c_taken, vcurr, i + 1, curr_height, best_height, vbest, curr_weight, cnt+1);
			curr_weight -= c[j].p;
			curr_height -= c[j].a;
			vcurr[i] = -1;
			c_taken[j] = 0;
		}
		
		
	}

}

void TorreCartoni(const Cartone* c, size_t n) {
	int* vcurr = calloc(n, sizeof(int));
	int* c_taken = calloc(n, sizeof(int));
	int* vbest = calloc(n, sizeof(int));
	int best_height = 0;
	for (size_t j = 0; j < n; j++) { vcurr[j] = -1; }
	TorreCartoniRec(c, n, c_taken, vcurr, 0, 0, &best_height, vbest, 0, 0);

	for (size_t j = 0; j < n; j++) {
		if (vbest[j] != -1)printf("%d\n", vbest[j]);
	}

	free(vcurr);
	free(c_taken);
	free(vbest);
}