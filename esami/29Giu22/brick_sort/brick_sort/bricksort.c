//#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

static void Swap(int* n1, int* n2) {
	int tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

void BrickSort(int* v, size_t v_size) {
	for (size_t i = 0; i < v_size; i++) {
		bool swapped = false;

		for (size_t j = 1; j+1 < v_size; j += 2) {
			if (v[j] > v[j + 1]) {
				Swap(v + j, v + j + 1);
				swapped = true;
			}
		}
		for (size_t j = 0; j+1 < v_size; j+= 2) {
			if (v[j] > v[j + 1]) {
				Swap(v + j, v + j + 1);
				swapped = true;
			}
		}
		if (!swapped)break;
	}
}

/*int main(void) {
	int v[] = { 0,3,4,2 };
	BrickSort(v, 4);
	for (size_t j = 0; j < 4; j++) {
		printf("%d ", v[j]);
	}
	return 0;
}
*/