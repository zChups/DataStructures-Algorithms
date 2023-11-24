#include "newton.h"
#include <math.h>

static double F(Polinomio* p, double xn) {
	double fxn = 0;	//accumula il risultato

	for (size_t i = 0; i < p->size; i++) {
		fxn += pow(xn, i) * p->coeffs[i];
	}
	return fxn;
}

double Newton(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter) {
	double p_xn = F(p, xn); //calcolo valore della funzione p nel punto xn
	double d_xn = F(d, xn); // calcolo valore della derivata d nel punto xn

	//calcolo approssimazione al passo corrente
	double xn_1 = xn - p_xn / d_xn;

	//caso base 1
	if (fabs(xn_1 - xn) <= t) {
		return xn_1;
	}
	else if (max_iter == 1) {	//caso base 2
		return xn_1;
	}

	//chiamata ricorsiva
	return Newton(p, d, xn_1, t, max_iter - 1);
}
