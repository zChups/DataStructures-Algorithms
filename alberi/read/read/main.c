#define _CRT_SECURE_NO_WARNINGS


#include "tree.h"
extern Node* TreeRead(const char* filename);

int main(void) {
	char* filename = "file00.txt";
	Node* t = TreeRead(filename);
	TreeWriteStdoutPreOrder(t);

	TreeDelete(t);
	return 0;
}