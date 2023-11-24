#include <stdlib.h>
#include <stdio.h>

void BacktrackStrRec(int n, int i, char* vcurr) {
	if (i == n) {	//caso base, trovata una soluzione possibile
		printf(" { ");
		for (int j = 0; j < n; j++) {
			printf("%c", vcurr[j]);
		}
		printf(" },");
		return;	//fine ricorsione
	}

	for (char c = 'a'; c < 'a' + n; c++) {
		vcurr[i] = c;
		//chiamata ricorsiva
		BacktrackStrRec(n, i + 1, vcurr);
	}
}

void BacktrackStr(int n) {
	if (n <= 0 || n > 26)return;
	char* vcurr = malloc(n);

	BacktrackStrRec(n, 0, vcurr);

	free(vcurr);
}