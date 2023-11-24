#include "list.h"

extern Item* sum(const Item* i1, const Item* i2);

static Item* StringToList(char* word) {
	Item* node = NULL; 
	for (size_t j = 0; word[j] != 0; j++) {
		node = ListInsertBack(node, word + j);
	}
	return node;
}

int main(void) {
	Item* i1 = StringToList("7254");

	ListWriteStdout(i1);
	puts("");

	Item* i2 = StringToList("324");

	ListWriteStdout(i2);
	puts("");

	Item* ret = sum(i1, i2);
	ListWriteStdout(ret);
	puts("");

	return 0;
}