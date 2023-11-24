#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//static void SubsetEqualRec(int n, int s, int i, bool* vcurr, int scurr, int* nsol) {
//	if (scurr == s) {	//somma corrente == s
//		(*nsol)++;	//incremento numero soluzioni
//		printf("{ ");
//		for (int j = 1; j <= n; j++) {
//			if (vcurr[j]) {
//				printf("%d ", j);
//			}
//		}
//		printf("}, ");
//		return;
//	}
//	if (i > n)return;
//
//	for (int e = i; e <= n; e++) {
//		if (scurr + e <= s) {
//			vcurr[e] = true;
//
//			SubsetEqualRec(n, s, e + 1, vcurr, scurr + e, nsol);
//
//			vcurr[e] = false;	//ripristino valore i-esimo
//		}
//	}
//
//}
//
//int SubsetEqual(int n, int s) {
//	if (n <= 0 || s <= 0)return 0;
//	bool* vcurr = calloc(n + 1, sizeof(bool));
//	int nsol = 0;
//	SubsetEqualRec(n, s, 1, vcurr, 0, &nsol);
//	free(vcurr);
//	return nsol;
//}

//seconda soluzione

void SubsetEqualRec(int n, int s, int i, bool* vcurr, int scurr, int* nsol) {
	if (scurr == s) {
		(*nsol)++;
		printf("{ ");
		for (int j = 1; j <= n; j++) {
			if (vcurr[j])printf("%d ", j);
		}
		printf("}, ");
		return;
	}

	if (i > n)return;

	if (scurr + i <= s) {
		vcurr[i] = true;
		SubsetEqualRec(n, s, i + 1, vcurr, scurr + i, nsol);
		vcurr[i] = false;
	}
	SubsetEqualRec(n, s, i + 1, vcurr, scurr, nsol);
}

int SubsetEqual(int n, int s) {
	if (n <= 0 || s <= 0)return 0;
	bool* vcurr = calloc(n + 1, sizeof(bool));
	int nsol = 0;

	SubsetEqualRec(n, s, 1, vcurr, 0, &nsol);

	free(vcurr);
	return nsol;
}