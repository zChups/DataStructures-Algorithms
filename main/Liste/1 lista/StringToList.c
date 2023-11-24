#include "list.h"

static Item* StringToList(char* word) {
	Item* node = NULL; 
	for (size_t j = 0; word[j] != 0; j++) {
		node = ListInsertBack(node, word + j);
	}
	return node;
}

int main(void) {
	Item* i1 = StringToList("");

	ListWriteStdout(i1);
	puts("");

	return 0;
}