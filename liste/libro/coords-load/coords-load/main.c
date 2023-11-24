#include "list.h"

extern Item* ListLoad(const char* filename);

int main(void) {
	Item* i;

	i = ListLoad("coords01.txt");
	ListWriteStdout(i);
	return 0;
}