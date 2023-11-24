#include <stdint.h>

static void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

static void InvertiArrayRec(int* arr, size_t size, size_t start, size_t end) {
	if (start >= end)return;
	swap(&arr[start], &arr[end]);
	InvertiArrayRec(arr, size, start + 1, end - 1);
}

void InvertiArray(int* arr, size_t size) {
	if (arr == NULL)return;
	else if (size == 0 || size == 1)return;
	InvertiArrayRec(arr, size, 0, size-1);
}