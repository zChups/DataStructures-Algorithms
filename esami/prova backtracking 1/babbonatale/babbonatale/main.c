#include <stdlib.h>

extern void BabboNatale(const int* pacchi, size_t pacchi_size, int p);

int main(void) {
	int pacchi[] = { 10, 15, 13, 100, 23, 49, 30, 5 };
	size_t pacchi_size = 8;
	int p = 100;
	BabboNatale(pacchi, pacchi_size, p);
	return 0;
}