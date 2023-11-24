#include "fattoriale.h"

double Fattoriale(double n) {
	if (n < 0) return -1;
	else return FattorialeRec(n);
}

double FattorialeRec(double n) {
	if (n == 0) return 1;
	else return FattorialeRec(n - 1) * n;
}