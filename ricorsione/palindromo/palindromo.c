#include <stdbool.h>
#include <string.h>
#include <stdint.h>

bool IsPalindromeRec(const char* str, unsigned int start, unsigned int end) {
	if (start >= end)return true;
	if (str[start] == str[end]) {
		return IsPalindromeRec(str, start + 1, end - 1);
	}
	else {
		return false;
	}
}

bool IsPalindrome(const char* str) {
	if (strlen(str) == 0)return 1;
	else if (str == NULL)return 0;
	return IsPalindromeRec(str, 0, strlen(str)-1);
}