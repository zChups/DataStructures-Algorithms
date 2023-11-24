//#include <math.h>
//
//double CountDigits(int num) {
//	if (num <= 0)return 0;
//	return CountDigits(num / 10) + 1;
//}
//
//int InvertiCifreRec(int n, double digits, int val) {
//	if (digits < 0)return val;
//	val += (n % 10) * pow(10.0, digits);
//	return InvertiCifreRec(n / 10, digits - 1, val);
//}
//
//int InvertiCifre(int n) {
//	if (n < 1)return n;
//	else if (n < 10)return n;
//	double digits = CountDigits(n);
//	return InvertiCifreRec(n, digits - 1, 0);
//}

//soluzione del prof

static int InvertiCifreRec(int n, int n_div) {
	if (n == 0)return n_div;
	return InvertiCifreRec(n / 10, n % 10 + n_div * 10);
}

int InvertiCifre(int n) {
	return InvertiCifreRec(n, 0);
}