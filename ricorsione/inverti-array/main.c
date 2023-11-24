#include <stdint.h>
#include <stdio.h>

extern void InvertiArray(int* arr, size_t size);

void main(void) {
	int arr[] = { 1,2,3,4,5 };
	InvertiArray(arr, 5);
	for (size_t i = 0; i < 5; i++) {
		putchar(arr[i] + '0');
	}
}