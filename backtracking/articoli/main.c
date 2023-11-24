#include "prezzo.h"

#include <stdio.h>

int main(void) {
	struct Articolo a[] = {
		{.nome = "Monopoli", .prezzo = 20},
		{.nome = "Carcassone", .prezzo = 30},
		{.nome = "Perudo", .prezzo = 20},
	};
	size_t a_size = sizeof(a) / sizeof(struct Articolo);
	TrovaArticoli(a, a_size, 50);
	puts("");
	return 0;
}