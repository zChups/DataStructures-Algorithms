#include <stdbool.h>
#include <stdio.h>

extern bool IsPalindrome(const char* str);

void main(void) {
	const char word[100] = "anna";
	printf("%s", word);
	if (IsPalindrome(word))printf(" is palindrome\n");
	else printf(" is not palindrome\n");
}