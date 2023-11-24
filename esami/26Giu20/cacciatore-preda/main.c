#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

extern int* CacciatorePreda(const char* v, size_t v_size, int u);

int main(void) {
	char v[] = { 'C', 'P', 'P', 'C', 'P' };
	size_t dim = 5;
	int* s = CacciatorePreda(v, dim, 1);
	for (size_t i = 0; i < dim-1 ; i++) {
		printf("%d, ", s[i]);
	}
	printf("%d", s[dim-1]);
}