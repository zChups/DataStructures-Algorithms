//#include <stdbool.h>
//#include <stdlib.h>
//#include <stdint.h>
//#include <stdio.h>
//#include <string.h>
//
//void RegoleRec(const char* r, int n, int* vcurr, bool* usati, int i) {
//	if (i == n + 1) {
//		for (int j = 0; j < n + 1; j++) {
//			printf("%d ", vcurr[j]);
//		}
//		puts("");
//		return;
//	}
//
//	for (int j = 1; j <= n + 1; j++) {
//		bool I = !usati[j - 1];	//numero non ancora usato
//		bool a = i == 0;
//		bool b = (r[i - 1] == 'i' || r[i - 1] == 'I') && vcurr[i - 1] < j;
//		bool c = (r[i-1] == 'd' || r[i - 1] == 'D') && vcurr[i - 1] > j;
//		bool II = a || b || c;
//
//		if (I && II) {
//			usati[j - 1] = 1;
//			vcurr[i] = j;
//			RegoleRec(r, n, i + 1, vcurr, usati);
//			usati[j - 1] = 0;
//		}
//	}
//}
//
//void Regole(const char* r) {
//	if (r == NULL)return;
//	else if (r[0] == '\0') {
//		puts("1");
//		return;
//	}
//	int n = strlen(r);
//	int* vcurr = malloc((n+1)* sizeof(int));
//	bool* usati = malloc((n + 1) * sizeof(bool));
//	RegoleRec(r, n, vcurr, usati, 0);
//	free(vcurr);
//}