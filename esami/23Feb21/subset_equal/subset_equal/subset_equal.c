
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void SubsetEqualRec(int n, int s, int* vcurr, bool* vtaken, int i, int curr_sum) {
	if (i == n) {
		if (curr_sum != s)return;	//prune

		putchar('{');
		for (int j = 0; j < n; j++) {
			if (vtaken[j])printf(" %d", vcurr[j]);
		}
		printf(" }, ");

		return;
	}

	vtaken[i] = 1;
	curr_sum += vcurr[i];
	SubsetEqualRec(n, s, vcurr, vtaken, i + 1, curr_sum);
	vtaken[i] = 0;
	curr_sum -= vcurr[i];
	SubsetEqualRec(n, s, vcurr, vtaken, i + 1, curr_sum);
}

void SubsetEqual(int n, int s) {
	if (n <= 0 || s <= 0)return;

	int* vcurr = calloc(n, sizeof(int));
	//fill vcurr
	for (int j = 1; j <= n; j++) {
		vcurr[j-1] = j;
	}
	bool* vtaken = calloc(n, sizeof(bool));

	SubsetEqualRec(n, s, vcurr, vtaken, 0, 0);

	free(vcurr);
	free(vtaken);
}

//int main(void) {
//	SubsetEqual(5, 7);
//}