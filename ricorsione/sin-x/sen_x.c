#include <float.h>

extern double ExpRec(double x, int n);

double FattorialeRec(int n) {
	if (n == 1 || n == 0)return 1;
	else {
		return FattorialeRec(n - 1) * n;
	}
}

double Fattoriale(int n) {
	if (n < 0)return -1;
	return FattorialeRec(n);
}

double Sign(int n) {
	return ((n % 2) ? -1 : 1);
}

double Exp(double x, int n) {
	if (n < 0)return -1;
	else if (n == 0) return 1;
	else return ExpRec(x, n);
}

double ExpRec(double x, int n) {
	if (n == 1)return x;
	else {
		return Exp(x, n - 1) * x;
	}
}

double Sen(double x, int i) {
	if (i < 0)return DBL_MIN;
	double sum = 0; //adder
	for (int n = 0; n < i; n++) {
		double first_num = Sign(n);
		double second_num = Exp(x, 2 * n + 1);
		double denom = Fattoriale(2 * n + 1);
		sum += (first_num / denom) * second_num;
	}
	return sum;
}

