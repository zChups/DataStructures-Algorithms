#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

static void CacciatorePredaRec(const char* v, size_t v_size, int u, int* s,  int pos_c, int* sbest, int* found) {
	if (pos_c == v_size) {
		(*found)++;
		if ((*found) == 1)memcpy(sbest, s, v_size * sizeof(int));
		return;
	}

	if (v[pos_c] == 'P') {
		CacciatorePredaRec(v, v_size, u, s, pos_c + 1, sbest, found);
	}

	if (v[pos_c] == 'C') {	//sono su un cacciatore
		//controllo se posso raggiungere qualche preda
		for (int i = 1; i <= u; i++) {
			bool I = pos_c - i >= 0;
			bool II = pos_c + i < v_size;
			if (I) {
				if (v[pos_c - i] == 'P' && s[pos_c - i] == -1) { //ho trovato la preda a sx
					s[pos_c] = pos_c - i;
					s[pos_c - i] = -2;
					CacciatorePredaRec(v, v_size, u, s, pos_c + 1, sbest, found);
					s[pos_c - i] = -1;
					s[pos_c] = -1;
				}
			}
			if (II) {
				if (v[pos_c + i] == 'P' && s[pos_c + i] == -1) {	//ho trovato la preda a dx
					s[pos_c] = pos_c + i;
					s[pos_c + i] = -2;
					CacciatorePredaRec(v, v_size, u, s, pos_c + 1, sbest, found);
					s[pos_c + i] = -1;
					s[pos_c] = -1;
				}
			}
				
			CacciatorePredaRec(v, v_size, u, s, pos_c + 1, sbest, found);
			
		}
	}
	
}

int* CacciatorePreda(const char* v, size_t v_size, int u) {
	int* s = calloc(v_size, sizeof(int));
	int* sbest = calloc(v_size, sizeof(int));
	int found= 0;
	//popolo il vettore s
	for (int i = 0; i < v_size; i++)s[i] = -1;

	CacciatorePredaRec(v, v_size, u, s, 0, sbest, &found);
	
	return sbest;
}