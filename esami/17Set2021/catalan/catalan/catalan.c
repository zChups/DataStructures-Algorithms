#include <stdio.h>
#include <stdlib.h>

static long long Catalan(int n) {
	if (n == 0)return 1;
	else if (n < 0)return 0;

	long long val = 0;

	for (int i = n - 1; i >= 0; i--) {
		val += Catalan(i) * Catalan(n - 1 - i);
	}

	return val;
}

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);

	if (argc != 2 || n < 0)return 1;

	printf("%lld", Catalan(n-1));

	return 0;
}