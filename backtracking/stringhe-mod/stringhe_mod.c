#include <stdlib.h>
#include <stdio.h>

void BacktrackStrModRec(int n, int k, char* vcurr, int i) {
	if (i == n) {
		printf(" { ");
		for (int j = 0; j < n; j++) {
			printf("%c", vcurr[j]);
		}
		printf(" },");
		return;
	}

	for (char c = 'a'; c < 'a' + k; c++) {
		vcurr[i] = c;
		BacktrackStrModRec(n, k, vcurr, i + 1);
	}
}

void BacktrackStrMod(int n, int k) {
	if (k <= 0 || k > 26 || n <= 0)return;
	char* vcurr = malloc(n);

	BacktrackStrModRec(n, k, vcurr, 0);

	free(vcurr);
}