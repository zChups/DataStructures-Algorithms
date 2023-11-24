#include "prezzo.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

static void TrovaArticoliRec(const struct Articolo* a, size_t a_size, int sum,bool* taken, int scurr, int i) {
	if (scurr == sum) {
		for (int j = 0; j < a_size; j++) {
			if (taken[j]) {
				printf("%s, ", a[j].nome);
			}
		}
		puts("");
		return;
	}
	else if (i == a_size)return;

	TrovaArticoliRec(a, a_size, sum, taken, scurr, i + 1);


	if (scurr + a[i].prezzo <= sum) {
		scurr += a[i].prezzo;
		taken[i] = true;
		TrovaArticoliRec(a, a_size, sum, taken, scurr, i + 1);
		taken[i] = false;
	}

}

void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum) {
	if (a == NULL || a_size == 0)return;

	bool* taken = calloc(a_size, sizeof(bool));

	TrovaArticoliRec(a, a_size, sum, taken, 0, 0);
}