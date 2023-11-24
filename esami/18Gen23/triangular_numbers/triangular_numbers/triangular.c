#include <stdio.h>
#include <stdlib.h>

static unsigned int TNumbersRec(int n) {
	if (n == 0)return 0;
	else if (n == 1)return 1;
	else if (n == 2)return 3;

	unsigned int val = 3 * TNumbersRec(n - 1) - 3 * TNumbersRec(n - 2) + TNumbersRec(n - 3);

	return val;
}

int main(int argc, char* argv[]) {
	if (argc != 2)return 1;
	int n = atoi(argv[1]);
	if (n < 0)return 1;
	unsigned int ret = TNumbersRec(n);

	printf("%d", ret);
	return 0;
}