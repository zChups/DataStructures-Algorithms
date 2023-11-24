#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static bool Divis(int n) {
	if (n / 10 == 0) {
		if (n != 0 && n != 7)return false;
		return true;
	}
	int val = abs(n/10 - (n % 10) * 2);
	return Divis(val);
}

int main(int argc, char* argv[]) {
	if (argc != 2)return 1;

	int n = atoi(argv[1]);
	if (n < 0)return 1;

	Divis(n) ? printf("Multiplo di 7.") : printf("Non multiplo di 7.");
	return 0;
}