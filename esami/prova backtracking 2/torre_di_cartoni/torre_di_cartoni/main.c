#include "torrecartoni.h"
extern void TorreCartoni(const Cartone* c, size_t n);
int main(void) {
	Cartone c[] = {{.p = 10,.a = 20,.l = 40}, {.p = 10,.a = 10,.l = 8}, {.p = 9,.a = 3,.l = 5}};
	Cartone p[] = {
		{.p = 25,.a = 20,.l = 40},
		{.p = 10,.a = 10,.l = 12},
		{.p = 9,.a = 3,.l = 5}
	};
	TorreCartoni(p, 3);
}