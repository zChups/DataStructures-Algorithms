#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

static bool Check(char* str, int n) {
	int right = 0, left = 0;

	for (int i = 0; i < n; i++) {
		if (right > left)return false;
		if (str[i] == ')') {
			right += 1;
		}
		else {
			left += 1;
		}
	}
	return true;
}

static void ParentesiRec(int n, int* nsol, char* vcurr, int i, int left, int right) {
	if (i > n || left < 0 || right < 0)return;
	if (left == 0 && right == 0) {
		if (!Check(vcurr, n)) return;
		(*nsol)++;
		/*if (vcurr[0] == ')')return;
		if (vcurr[n - 1] == '(')return;*/
		for (int j = 0; j < n; j++) {
			printf("%c", vcurr[j]);
		}
		puts("");
		return;
	}

	

	for (char c = '('; c <= '(' + 1; c++) {
		vcurr[i] = c;
		c == '(' ? ParentesiRec(n, nsol, vcurr, i + 1, left - 1, right) : ParentesiRec(n, nsol, vcurr, i + 1, left, right - 1);
	}

	/*for (int j = 0; j < 2*n; j++) {
		if (!taken[j]) {
			taken[j] = 1;
			vcurr[i] = arr[j];
			ParentesiRec(n, arr, nsol, vcurr, taken, i + 1);
			taken[j] = 0;
			ParentesiRec(n, arr, nsol, vcurr, taken, i + 1);
		}
	}*/
}

int Parentesi(int n) {
	if (n < 0)return -1;

	int nsol = 0;
	char* vcurr = malloc((2 * n + 1) * sizeof(char));
	vcurr[2 * n] = '\0';

	ParentesiRec(2*n, &nsol, vcurr, 0, n, n);

	free(vcurr);

	return nsol;
}
//
//int main(void) {
//	Parentesi(3);
//}