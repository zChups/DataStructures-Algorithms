
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <math.h>

static double Fat(double y) {
	if (y == 1 || y == 0)return 1;
	return Fat(y - 1) * y;
}

static double Sen(double x, int i) {
	

	double num_first = i % 2 == 0 ? 1 : -1;
	double num_second = pow(x, 2 * i + 1);

	double denom = Fat(2*i+1);

	double curr_sen = num_first / denom * num_second;

	if (i == 0) {
		return curr_sen;
	}

	return curr_sen + Sen(x, i-1);
}

int main(int argc, char* argv[]) {
	if (argc != 3)return 1;

	char* ptr;

	double x = (double)strtod(argv[1], &ptr);
	int i = atoi(argv[2]);

	if (i < 0)return 1;

	printf("%f", Sen(x, i));

	return 0;
}