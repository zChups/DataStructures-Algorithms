#include <stdlib.h>
#include <stdbool.h>

int AToIRec(const char* str, int count, int* res) {
	int curr = str[count];
	if (curr == 0)return true;
	//controllo se numero
	if (str[count] > '9' || str[count] < '0')return false;
	*res = (*res) * 10 + (str[count] - '0');
	return AToIRec(str, count+1, res);
}

int AToI(const char* str) {
	if (str == NULL)return 0;	//return 0 if string is null or creates problems
	int res = 0;
	//sign contiene il segno della stringa
	int sign = (str[0] == '-') ? -1 : 1;
	//controllo se primo carattere è un segno
	if (str[0] == '-' || str[0] == '+')str += 1;	//mi sposto con il puntatore al carattere successivo
	bool ok = AToIRec(str, 0, &res);
	if (!ok) {	//ci sono stati problemi durante la conversione
		res = 0;
	}
	return res * sign;
}