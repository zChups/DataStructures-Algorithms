#include <stdbool.h>
#include <stdlib.h>


void SwapElem(int* a, int* b) {
	int tmp = *a;
	*a = *b; 
	*b = tmp;
}

static bool Check(const int* s, int n, char c) {
	int curr_mul = 0;
	if (c == 'c') {
		for (int i = 0; i < n; i++) {	//controllo sulla colonna
			curr_mul += s[i*n];
		}
	}
	else if (c == 'r') {
		for (int i = 0; i < n; i++) {	//controllo sulla riga
			curr_mul += s[i * n + i];
		}
	}
	
}

static void RisolviProdottoRec(int n, const int* s, int i) {
	if (i == n) {
		if (Check(s, n, 'r')) {
			
		}
		if (Check(s, n, 'c')) {

		}
	}
}

int* RisolviProdotto(int n, const int* s) {
	int* vcurr = calloc((size_t)n * (size_t)n, sizeof(int));	//matrice nXn
	RisolviProdottoRec(n, s, 0);

	return vcurr;
}