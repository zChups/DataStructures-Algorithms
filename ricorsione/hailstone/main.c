#include <stdint.h>
#include <stdio.h>

extern size_t Hailstone(int n);

int main(void) {
	int num = 5;
	size_t val = Hailstone(num);
	printf("\nIl numero di elementi che compone la sequenza data dal numero %d: %zu\n", num, val);

	puts("");


	return 1;
}