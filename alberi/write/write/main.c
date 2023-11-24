
#include "tree.h"
extern bool TreeWrite(const Node* t, const char* filename);
extern Node* TreeRead(const char* filename);

int main(void) {
	Node* t = TreeRead("file00.txt");
	return TreeWrite(t, "fileWRITE.txt");
}