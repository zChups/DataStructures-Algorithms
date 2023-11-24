#include <stdlib.h>
#include <stdio.h>

extern int* SolarCut(int A, size_t* sol_size);

int main(void) {
	size_t sol;
	int* vcurr = SolarCut(256, &sol);
	for (size_t j = 0; j < sol; j++) {
		printf("%d ", vcurr[j]);
	}
	free(vcurr);
}