#include <stdint.h>
#include <stdlib.h>

#include <string.h>

static void ReverseStringRec(const char* str, char** new_str) {
	if (*str == '\0')return;

	ReverseStringRec(str+1, new_str);
	*(*new_str) = *str;
	(*new_str)++;
}

char* ReverseString(const char* str) {
	if (!str)return NULL;

	char* new_str = calloc(strlen(str) + 1, sizeof(char));


	char* head = new_str;

	ReverseStringRec(str, &new_str);
	new_str[strlen(str) + 1] = '\0';

	return head;
}

//int main(void) {
//	char* a = ReverseString("ab");
//	return 0;
//}
