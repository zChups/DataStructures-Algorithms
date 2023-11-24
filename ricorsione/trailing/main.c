#include <stdio.h>

extern unsigned int TrailingZeros(unsigned int n);

int main(void) {
	printf("%d", TrailingZeros(6));
	return 0;
}