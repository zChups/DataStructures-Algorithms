
#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265
#endif // !M_PI


extern double Sen(double x, int n);


int main(void) {
	printf("%e\n", Sen(M_PI / 2, 4));
	return 0;
}