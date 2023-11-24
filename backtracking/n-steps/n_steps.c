#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void StepsRec(int n, int* vcurr, int i, int* nsol) {
	if (n == 0) {
		(*nsol)++;
		putchar('[');
		for (int j = 0; j < i-1; j++) {
			printf("%i, ", vcurr[j]);
		}
		printf("%i", vcurr[i-1]);
		printf("], ");
		return;
	}

	for (int j = 1; j <= 3; j++) {
		if (n >= j) {
			vcurr[i] = j;
			StepsRec(n - j, vcurr, i + 1, nsol);
		}
	}

}

int Steps(int n) {
	if (n <= 0)return 0;
	int nsol = 0;
	int* vcurr = calloc(n, sizeof(int));
	StepsRec(n, vcurr, 0, &nsol);
	free(vcurr);
	return nsol;
}