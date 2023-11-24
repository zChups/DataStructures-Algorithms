#include <stdint.h>
#include <stdio.h>

static size_t HailstoneRec(int n) {
	printf("%d", n);
	if (n == 1) {	//ho raggiunto il primo 1
		return 1;
	}
	printf(", ");
	//calcolo elemento successivo
	n = (n % 2) ? (3 * n + 1) : n / 2;
	return 1 + HailstoneRec(n);
}

size_t Hailstone(int n) {
	if (n <= 0)return 0;
	return HailstoneRec(n);
}