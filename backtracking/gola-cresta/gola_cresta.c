#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void GolaCrestaRec(size_t n, size_t* vcurr, int i) {
	if (i == (int)n) {
		putchar('(');
		for (size_t j = 0; j < n-1; j++) {
			printf("%zu, ", vcurr[j]);
		}
		printf("%zu), ", vcurr[n - 1]);
		return;
	}

	for (size_t j = 0; j < 3; j++) {
		vcurr[i] = j;

		bool I_1 = vcurr[i - 1] > vcurr[i];
		bool I_2 = vcurr[i] > vcurr[i-1];

		bool II_1 = vcurr[i - 2] < vcurr[i - 1] && vcurr[i - 1] > vcurr[i];
		bool II_2 = vcurr[i - 2] > vcurr[i - 1] && vcurr[i - 1] < vcurr[i];

		if (i == 0) {
			GolaCrestaRec(n, vcurr, i + 1);
		}
		
		if (i == 1 && (I_1 || I_2)) {
			GolaCrestaRec(n, vcurr, i + 1);
		}
		else if (i == 2 && (II_1 || II_2)) {
			GolaCrestaRec(n, vcurr, i + 1);
		}
	}
}

void GolaCresta(size_t n) {
	if (n < 3)return;
	size_t* vcurr = calloc(n, sizeof(size_t));
	GolaCrestaRec(n, vcurr, 0);
	free(vcurr);
}