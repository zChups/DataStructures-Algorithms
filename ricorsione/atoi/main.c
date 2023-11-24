#include <stdio.h>

extern int AToI(const char* str);

void main(void) {
	char word[] = "1234";
	printf("Il numero corrispondente alla stringa %s: %d\n", word, AToI(word));
}