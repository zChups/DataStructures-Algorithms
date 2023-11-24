#include <stdio.h>
#include <stdlib.h>

static int SumRec(int n) {
	if (n == 0)return 0;
	return n % 10 + SumRec(n / 10);
}
static void RadiceNumericaRec(int n){
	if (n / 10 == 0) {
		printf("%d", n);
		return;
	}

	RadiceNumericaRec(SumRec(n));
}

int main(int argc, char* argv[]) {
	if (argc != 2)return 1;
	int n = atoi(argv[1]);
	if (n < 0)return 1;

	RadiceNumericaRec(n);

	return 0;
}