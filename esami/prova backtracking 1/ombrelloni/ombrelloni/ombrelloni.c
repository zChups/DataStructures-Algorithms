#include <stdio.h>
#include <stdlib.h>


static void OmbrelloniRec(int k, int n, int* vcurr, int i, int* nsol) {
	if (i == n) {
		if (k != 0)return;
		(*nsol)++;
		printf("%2d) ", *nsol);
		for (int j = 0; j < n - 1; j++) {
			printf("%2d ", vcurr[j]);
		}
		printf("%2d\n", vcurr[n - 1]);
		return;
	}

	vcurr[i] = 0;
	OmbrelloniRec(k, n, vcurr, i + 1, nsol);
	vcurr[i] = 1;
	if (vcurr[i] == 1 && vcurr[i] == vcurr[i - 1])return;
	OmbrelloniRec(k - 1, n, vcurr, i + 1, nsol);
	vcurr[i] = 0;
}

int Ombrelloni(int k, int n) {	//n ombrelloni, k ragazzi
	if (k < 0 || n < 0)return 0;
	int nsol = 0;
	int* vcurr = calloc(n, sizeof(int));
	OmbrelloniRec(k, n, vcurr, 0, &nsol);
	free(vcurr);
	return nsol;
}