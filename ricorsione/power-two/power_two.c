#include <stdint.h>

unsigned int PowerTwo(unsigned int n) {	//n sempre positivo
	if (n & 1 || n == 0)return 0;
	return 1 + PowerTwo(n >> 1);
}