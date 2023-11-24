#include "vector_list.h"

int main(void) {
	ElemType v1[] = { 1,2,3,4,5,6 }, * v2;
	size_t v1_size = sizeof(v1) / sizeof(ElemType), v2_size;
	Item* i;
	i = Vector2List(v1, v1_size, kInOrder);
	ListWriteStdout(i);
	v2 = List2Vector(i, &v2_size, kInOrder);
	return 0;
}