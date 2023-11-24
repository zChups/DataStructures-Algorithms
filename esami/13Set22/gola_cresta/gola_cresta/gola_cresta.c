#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static bool CheckConstraint(int* vcurr) {
	bool a = *vcurr < *(vcurr + 1) && *(vcurr + 1) >*(vcurr + 2);
	bool b = *vcurr > *(vcurr + 1) && *(vcurr + 1) < *(vcurr + 2);
	if (!a && !b) {	//prune
		return true;
	}
	return false;
}

static void GolaCrestaRec(size_t n, int* vcurr, size_t i) {
	if (i == n) {
		for (size_t j = 0; j <= n - 3; j++) {
			if (CheckConstraint(vcurr + j))return;	//prune
		}
		//stampo la soluzione
		putchar('(');
		for (size_t j = 0; j < n-1; j++) {
			printf("%d, ", *(vcurr + j));
		}
		printf("%d), ", *(vcurr + n - 1));
		return;
	}

	for (int j = 0; j < 3; j++) {
		vcurr[i] = j;
		GolaCrestaRec(n, vcurr, i + 1);
	}
}

void GolaCresta(size_t n) {
	if (n < 3)return;
	int* vcurr = calloc(n, sizeof(int));

	GolaCrestaRec(n, vcurr, 0);

	free(vcurr);
}

//int main(void) {
//	GolaCresta(4);
//}