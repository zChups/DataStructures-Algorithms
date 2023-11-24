
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

static void ParoleT9Rec(const char* str, char* vcurr, size_t pos, int* nsol) {
	if (str[pos] == '\0') {
		(*nsol)++;
		*nsol == 1 ? printf("%s", vcurr) : printf("\n%s", vcurr);
		
		return;
	}

	if (str[pos] == '9') {
		for (int j = 0; j < 4; j++) {
			int offset = str[pos] - '2';
			vcurr[pos] = 'A' + offset * 3 + j+1;
			ParoleT9Rec(str, vcurr, pos + 1, nsol);
		}
	}
	else if (str[pos] == '7') {
		for (int j = 0; j < 4; j++) {
			int offset = str[pos] - '2';
			vcurr[pos] = 'A' + offset * 3 + j;
			ParoleT9Rec(str, vcurr, pos + 1, nsol);
		}
	}
	else if (str[pos] == '8') {
		for (int j = 0; j < 3; j++) {
			int offset = str[pos] - '2';
			vcurr[pos] = 'A' + offset * 3 + j+1;
			ParoleT9Rec(str, vcurr, pos + 1, nsol);
		}
	}
	else {
		for (int j = 0; j < 3; j++) {
			int offset = str[pos] - '2';
			vcurr[pos] = 'A' + offset*3 + j;
			ParoleT9Rec(str, vcurr, pos+1, nsol);
		}
	}
	
}

int ParoleT9(const char* str) {
	if (!str)return 0;

	int n_sol = 0;
	size_t len = strlen(str);
	char* vcurr = calloc(len + 1, sizeof(char));
	vcurr[len] = '\0';
	ParoleT9Rec(str, vcurr, 0, &n_sol);
	free(vcurr);
	return n_sol;

}

//int main(void) {
//	ParoleT9("892");
//}