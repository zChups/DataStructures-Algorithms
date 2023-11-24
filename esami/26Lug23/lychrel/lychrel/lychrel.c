#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <math.h>

static void Reversed(int n, int* n_reversed, int* i) {
	if (n == 0)return;

	Reversed(n / 10, n_reversed, i);
	*n_reversed = (*n_reversed) + (n % 10) * (int)pow(10, *i);
	(*i)++;
}

static bool IsLychrel(int n, int i) {
	int n_reversed = 0;
	int cnt = 0;
	Reversed(n, &n_reversed, &cnt);

	if (n == n_reversed)return false;

	if (i == 0)return true;

	return IsLychrel(n + n_reversed, i - 1);
}

int main(int argc, char* argv[]) {
	int n = atoi(argv[1]);
	if (argc != 3 || n < 0)return 1;
	int i = atoi(argv[2]);


	if (IsLychrel(n, i)) {
		printf("Lychrel\n");
	}
	else {
		printf("Non di Lychrel\n");
	}


	return 0;
}