
int main(void) {
	ElemType e[] = { 1,2,3,4,5 };
	Item* i1 = ListInsertHead(e, ListInsertHead(e + 1, NULL));
	ListWriteStdout(i1);
	puts("");
	Item* i2 = ListInsertHead(e + 2, ListInsertHead(e + 3, ListInsertHead(e + 4, NULL)));
	ListWriteStdout(i2);
	puts("");
	
	return 0;
}