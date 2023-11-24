#include <stdlib.h>

#include <math.h>



int* SolarCut(int A, size_t* sol_size) {
	int* vcurr = malloc(1*sizeof(int));

	for(size_t i = 0; A > 0; i++) {
		int A_i = (int)sqrt((int)A);
		while (1) {
			if (A >= (int)pow(A_i, 2)) {
				if (i == 0) {
					vcurr[i] = (int)pow(A_i, 2);
					break;
				}
				else {
					vcurr = realloc(vcurr, (*sol_size+1) * sizeof(int));
					vcurr[i] = (int)pow(A_i, 2) == 0 ? 1 : (int)pow(A_i, 2);
					break;
				}
			}
			A_i--;
		}
		A -= (int)pow(A_i, 2) == 0 ? 1 : (int)pow(A_i, 2);
		*sol_size = i+1;
	}
	return vcurr;
}