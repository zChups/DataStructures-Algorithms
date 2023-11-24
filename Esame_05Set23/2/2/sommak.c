#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static void SommaKRec(int n, int sum, int* nsol, bool* taken, int i, int curr_sum, int* vcurr) {
	if (curr_sum > sum)return;
	if (curr_sum == sum && i==n) {
		(*nsol)++;
		printf("{");
		for (int j = 0; j < n; j++) {
			if (taken[j]) {
				printf("%d, ", vcurr[j]);
			}
		}
		printf("}, ");
	}
	if (i >= n)return;
	taken[i] = 1;
	curr_sum += vcurr[i];
	SommaKRec(n, sum, nsol, taken, i + 1, curr_sum, vcurr);
	taken[i] = 0;
	curr_sum -= vcurr[i];
	SommaKRec(n, sum, nsol, taken, i + 1, curr_sum, vcurr);
}

int SommaK(int n, int k) {
	//if (n==0)
	bool* taken = calloc(n, sizeof(bool));
	int nsol = 0;
	int* vcurr = calloc(n, sizeof(int));
	//fillo vcurr
	for (int i = 1; i <= n; i++) {
		vcurr[i - 1] = i;
	}
	SommaKRec(n, k, &nsol, taken, 0, 0, vcurr);

	free(taken);
	free(vcurr);
	return nsol;

}

//int main(void) {
//	return SommaK(6, 9);
//}