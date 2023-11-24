extern double Binomiale(unsigned int n, unsigned int k);
extern double BinomialeRec(unsigned int n, unsigned int k);

#include <stdio.h>


void main(void) {
	printf("Il coefficiente binomiale di: ( %u : %u ) -> %.0f", 10u, 4u, Binomiale(10u, 4u));
}

double Binomiale(unsigned int n, unsigned int k) {
	if (n == 0 || k > n) return -1;
	else return BinomialeRec(n, k);
}

double BinomialeRec(unsigned int n, unsigned int k) {
	if (k == 0 || k == n)return 1;
	else return BinomialeRec(n - 1, k - 1) + BinomialeRec(n - 1, k);
}